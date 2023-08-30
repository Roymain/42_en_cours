#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <elf.h>

#define	ELF64_ST_BIND(info)		((info) >> 4)
#define	ELF64_ST_TYPE(info)		((info) & 0xf)

/* Macro for constructing st_info from field values. */
#define	ELF64_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

#define ERR_NO_PRG "« a.out »: pas de tel fichier"

void print_prg(const char *prg, const char *prefix, const char *error) {
	if (prefix) {
		write(2, prefix, strlen(prefix));
		write(2, " - ", 3);
	}
	if (error) {
		write(2, prg, strlen(prg));
		write(2, ": ", 2);
		write(2, error, strlen(error));
		write(2, "\n", 1);
	} else {
		perror(prg);
	}
}

void	print_header(void *map) {
	Elf32_Ehdr	*header32 = map;
	printf("e_ident ");
	for (int i = 0; i < EI_NIDENT;i++) {
		printf("%c", header32->e_ident[i]);
	}
	printf("\n");
	printf("e_type %d\n", header32->e_type);
	printf("e_machine %d\n", header32->e_machine);
	printf("e_version %d\n", header32->e_version);
	printf("e_entry %d\n", header32->e_entry);
	printf("e_phoff %d\n", header32->e_phoff);
	printf("e_shoff %d\n", header32->e_shoff);
	printf("e_flags %d\n", header32->e_flags);
	printf("e_ehsize %d\n", header32->e_ehsize);
	printf("e_phentsize %d\n", header32->e_phentsize);
	printf("e_phnum %d\n", header32->e_phnum);
	printf("e_shentsize %d\n", header32->e_shentsize);
	printf("e_shnum %d\n", header32->e_shnum);
	printf("e_shstrndx %d\n", header32->e_shstrndx);
	Elf64_Ehdr	*header = (Elf64_Ehdr *)map;
	printf("e_ident ");
	for (int i = 0; i < EI_NIDENT;i++) {
		printf("%c", header->e_ident[i]);
	}
	printf("\n\n");
	printf("e_type %d\n", header->e_type);
	printf("e_machine %d\n", header->e_machine);
	printf("e_version %d\n", header->e_version);
	printf("e_entry %ld\n", header->e_entry);
	printf("e_phoff %ld\n", header->e_phoff);
	printf("e_shoff %ld\n", header->e_shoff);
	printf("e_flags %d\n", header->e_flags);
	printf("e_ehsize %d\n", header->e_ehsize);
	printf("e_phentsize %d\n", header->e_phentsize);
	printf("e_phnum %d\n", header->e_phnum);
	printf("e_shentsize %d\n", header->e_shentsize);
	printf("e_shnum %d\n", header->e_shnum);
	printf("e_shstrndx %d\n\n", header->e_shstrndx);
}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		print_prg(argv[0], NULL, ERR_NO_PRG);
		return 1;
	}
	int	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		print_prg(argv[0], NULL, NULL);
		return 1;
	}
	struct stat	my_stat = {0};
	if (stat(argv[1], &my_stat) != 0) {
		print_prg(argv[0], "stat", NULL);
		return 1;
	}
	size_t	len = my_stat.st_size;
	printf("file size %zu\n", len);
	size_t	offset = 0;
	void	*map = mmap(NULL, len - offset, PROT_EXEC, MAP_PRIVATE, fd, offset);
	if (map == (void *) -1) {
		print_prg(argv[0], "mmap", NULL);
		return 1;
	}
	print_header(map);
	Elf64_Ehdr* elfHeader = (Elf64_Ehdr*)map;
    if (elfHeader->e_ident[EI_MAG0] != ELFMAG0 ||
        elfHeader->e_ident[EI_MAG1] != ELFMAG1 ||
        elfHeader->e_ident[EI_MAG2] != ELFMAG2 ||
        elfHeader->e_ident[EI_MAG3] != ELFMAG3 ||
        elfHeader->e_ident[EI_CLASS] != ELFCLASS64 ||
        elfHeader->e_ident[EI_DATA] != ELFDATA2LSB /*||
        elfHeader->e_type != ET_EXEC*/) {
        fprintf(stderr, "Invalid or unsupported ELF format.\n");
        munmap(map, len);
        close(fd);
        return 1;
    }
	// recup ptr 1er hdr section
	Elf64_Shdr* sectionHeaders = (Elf64_Shdr*)((char*)map + elfHeader->e_shoff);
    Elf64_Shdr* symbolTableHeader = NULL;
    Elf64_Shdr* stringTableHeader = NULL;

	// parcourt hdr section
    for (int i = 0; i < elfHeader->e_shnum; i++) {
        if (sectionHeaders[i].sh_type == SHT_SYMTAB) {
            symbolTableHeader = &sectionHeaders[i];
        } else if (sectionHeaders[i].sh_type == SHT_STRTAB) {
            stringTableHeader = &sectionHeaders[i];
        }

        if (symbolTableHeader != NULL && stringTableHeader != NULL) {
            break;
        }
    }

    if (symbolTableHeader == NULL || stringTableHeader == NULL) {
        fprintf(stderr, "Symbol table or string table not found.\n");
        munmap(map, len);
        close(fd);
        return 1;
    }

    // Get the symbol table and string table pointers.
    Elf64_Sym* symbols = (Elf64_Sym*)((char*)map + symbolTableHeader->sh_offset);
    char* strTable = ((char*)map + symbolTableHeader->sh_offset + 1);


  
       


    //Iterate through the symbol table and print symbol information.
    printf("Symbol table:\n");
    for (int i = 0; i < symbolTableHeader->sh_size / sizeof(Elf64_Sym); ++i) {
		if ((unsigned long long)symbols[i].st_value != 0)
        
            printf("%s - Address: 0x%016llx\n", &strTable[symbols[i].st_info], (unsigned long long)symbols[i].st_value);
 unsigned char info = symbols[i].st_info; // Récupérer la valeur de st_info
unsigned char type = ELF64_ST_BIND(info); // Extraire le type de liaison
printf("Type de liaison : %s\n", type);
            //printf("Contenu de l'adresse : %s\n", (char*)symbols[i].st_value);
    }

	if (munmap(map, len)) {
		print_prg(argv[0], "munmap", NULL);
		return 1;
	}
	close(fd);
	return 0;
}



// Elf64_Half st_shndx est un champ dans la structure Elf64_Sym qui représente 
// l'index de la section à laquelle le symbole est associé. Chaque symbole dans la table des symboles 
// est défini par rapport à une section, et ce champ contient l'index de la section pertinente dans la table des en-têtes de section.
//  Si la valeur de st_shndx est SHN_UNDEF, cela signifie que le symbole est indéfini ou sans section. Si la valeur est SHN_ABS, 
//  cela signifie que le symbole est défini dans une section de données absolue.
//  Si la valeur est SHN_COMMON, cela signifie que le symbole est défini dans une section de données commune.