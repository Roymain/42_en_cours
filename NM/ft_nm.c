#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char **argv){


    Elf32_Sym *symtab;
    char *strtab;
    int count;

    void *addr;
    int fd;
    struct stat sb;
    off_t offset, pa_offset;
    size_t length;
    ssize_t s;

    if (argc < 3 || argc > 4) {
        fprintf(stderr, "%s fichier offset [longueur]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        handle_error("open");
    if (fstat(fd, &sb) == -1)/* Pour obtenir la taille du fichier */
        handle_error("fstat");

    offset = atoi(argv[2]);

    pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
        /* l’offset pour mmap() doit être aligné sur une page */
       if (offset >= sb.st_size) {
           fprintf(stderr, "L’offset dépasse la fin du fichier\n");
           exit(EXIT_FAILURE);
       }
       if (argc == 4) {
           length = atoi(argv[3]);
           if (offset + length > sb.st_size)
               length = sb.st_size - offset;
                   /* Impossible d’afficher les octets en dehors du fichier */
       } else {    /* Pas de paramètre longueur
                      ==> affichage jusqu’à la fin du fichier */
           length = sb.st_size - offset;
       }
       addr = mmap(NULL, length + offset - pa_offset, PROT_READ+PROT_EXEC,
                   MAP_SHARED, fd, pa_offset);
       if (addr == MAP_FAILED)
           handle_error("mmap");
       s = write(STDOUT_FILENO, addr + offset - pa_offset, length);
       if (s != length) {
           if (s == -1)
               handle_error("write");
           fprintf(stderr, "écriture partielle");
      
       }

    printf("\n");

    Elf32_Ehdr      *hdr     = NULL;
    Elf32_Phdr      *phdr    = NULL;
    Elf32_Shdr      *shdr    = NULL;
    Elf32_Sym       *syms    = NULL;
    char            *strings = NULL;
    char            *start   = NULL;
    char            *taddr   = NULL;
    void            *entry   = NULL;
    int i = 0;
    char *exec = NULL;

    hdr = (Elf32_Ehdr *) addr;
    shdr = (Elf32_Shdr *) (addr + hdr->e_shoff);

    symtab = NULL;
    strtab = NULL;
    for (i = 0; i < hdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB) {
            symtab = (Elf32_Sym *) (addr + shdr[i].sh_offset);
            count = shdr[i].sh_size / sizeof(Elf32_Sym);
        } else if (shdr[i].sh_type == SHT_STRTAB && strcmp(".strtab", (char *) (addr + shdr[i].sh_name)) == 0) {
            strtab = (char *) (addr + shdr[i].sh_offset);
        }
    }

    if (symtab == NULL || strtab == NULL) {
        fprintf(stderr, "Failed to find symbol table or string table\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < count; i++) {
        printf("%08x %08x %s\n", symtab[i].st_value, symtab[i].st_size, strtab + symtab[i].st_name);
    }

    munmap(addr, lseek(fd, 0, SEEK_END));

    return 0;
}