#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char ** filename) {

	int fd;	
	char buff[512];
	int len = 0;

	if (argc < 2) {
		printf("please run program with file name \n");
		return 0;
	}

	fd = open((const char *) filename[1],O_RDWR|O_CREAT|O_APPEND, S_IRWXU | S_IRGRP | S_IROTH);

	if (fd < 0) { perror ("file creation error :"); exit(-1); }

	while (1) {
		memset(buff,0,512);
		printf("write string to write in file: \n");
		len = scanf("%s", buff);
		printf("%d\n", strlen(buff)+1);
		if (buff[0] ==  "0") { 
			close(fd);
			break;
		}
		else {
			unsigned char length = strlen(buff);
			len = length + 1;
			write(fd, buff, length);
			write(fd, " ", 1);
			printf ("number of char written to file : %d\n",length );
		  
		}
		
		off_t offset = 0;
		if ( (lseek(fd, offset, SEEK_SET)) < 0 ) {
			perror("file operations :");
			exit(-1);
		}

		memset(buff,0,512);

		if ( (read(fd, buff, len)) < 0 ) {
			perror("file operations :");
			exit(-1);
		}
		else {
			printf("read from file %s\n", buff);
		}
		
	}
	
	return 0;
}
	

		
