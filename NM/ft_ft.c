#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <elf.h>

int main(int argc, char **argv) {
    int fd;
    void *map;
    Elf32_Ehdr *ehdr;
    Elf32_Shdr *shdr;
    Elf32_Sym *symtab;
    char *strtab;
    int i, count;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    map = mmap(NULL, lseek(fd, 0, SEEK_END), PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    ehdr = (Elf32_Ehdr *) map;
    shdr = (Elf32_Shdr *) (map + ehdr->e_shoff);

    symtab = NULL;
    strtab = NULL;
    for (i = 0; i < ehdr->e_shnum; i++) {

            symtab = (Elf32_Sym *) (map + shdr[i].sh_offset);
            count = shdr[i].sh_size / sizeof(Elf32_Sym);

    }

    if (symtab == NULL) {
        fprintf(stderr, "Failed to find symbol table or string table\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < count; i++) {
        printf("%08x %08x %s\n", symtab[i].st_value, symtab[i].st_size, strtab + symtab[i].st_name);
    }

    munmap(map, lseek(fd, 0, SEEK_END));
    close(fd);
    exit(EXIT_SUCCESS);
}