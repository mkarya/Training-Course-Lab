#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

main() 
{ 
int i;   
pid_t id[3];
id[0] = fork(); 
id[1] = fork();
   printf("Hello World!\n"); 
   id[2] = fork();
   printf("Hello World!\n"); 

}

