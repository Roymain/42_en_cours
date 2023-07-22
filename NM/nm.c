#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char **argv){
    unsigned char *addr;
    int fd;
    struct stat sb;
    off_t offset, pa_offset;
    size_t length;
    ssize_t s;

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

    if (argc < 3 || argc > 4) {
        fprintf(stderr, "%s fichier offset [longueur]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    fd = open(argv[1], O_RDONLY);
    


    addr = mmap(NULL, length + offset - pa_offset, PROT_READ+PROT_EXEC,
                MAP_SHARED, fd, pa_offset);
    hdr = (Elf32_Ehdr *) addr;
    phdr = (Elf32_Phdr *)(addr + hdr->e_phoff);


    printf("\n %d  \n", hdr->e_ident[EI_DATA]);



    return 0;
}