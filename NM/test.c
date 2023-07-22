#include <stdio.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)
           
int main(int argc, char **argv){
    printf("roger\n");
   
    return 0;
}