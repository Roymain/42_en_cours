#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>


ssize_t write_asm(int fildes, const void *buf, size_t nbyte);
ssize_t strlen_asm(const void *buf);
int strcmp_asm(const char *s1, const char *s2);
char* strcpy_asm( char *s1, const char *s2);

int main(){
	errno = 0;
	char *str = strdup("crotttttttttttttte");
	printf("%s\n", strcpy_asm(str, "qwertyui"));
	printf("%s\n", strcpy(str, ""));
	return 0;
}