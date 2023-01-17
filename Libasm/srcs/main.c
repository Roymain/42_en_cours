#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

ssize_t write_asm(int fildes, const void *buf, size_t nbyte);
ssize_t strlen_asm(const void *buf);

int main(){
	errno = 0;
	
	printf("%zd\n", strlen_asm("qwertyui"));
	return 0;
}