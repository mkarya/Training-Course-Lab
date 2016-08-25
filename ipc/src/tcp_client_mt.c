#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define DATA "Hello world of socket programming"

void * sender(void *sock) {
	char buff[512];
	int *sock_fd = (int *) sock;
	while(1) {
       		printf("Reply : ");
       		scanf("%s",buff);
       		if ((send(*sock_fd,buff,strlen(buff) + 1 ,0) < 0)) 
			perror("send failed :");
	}

	pthread_exit(0);
}

void * receiver (void *sock) {
	char buff[512];
	int rval;
	int *sock_fd = (int *) sock;
	memset(buff,0,512);
	while(1) {
		if ((rval = recv(*sock_fd, buff, sizeof(buff),0)) < 0 ) {
			perror("reading failed on incoming connection :");
			pthread_exit(0);
		}
		else if(rval == 0) {
			perror("client ending connections :");
			pthread_exit(0);
		}
		else 
		{
			printf("MSG : %s\n", buff);
		}

		memset(buff,0,strlen(buff));
	}

	pthread_exit(0);
}
	
int main (int argc, char **argv) {
	int mysock;
	pthread_t sender_t, receiver_t;
	pthread_attr_t at;
	pthread_attr_init(&at);
	struct sockaddr_in server;
	struct hostent *hp;
	char buff[1024];
	int rval;
	mysock = socket(AF_INET, SOCK_STREAM, 0);
	if (mysock < 0) {
		perror ("socket opening failed");
		exit(1);
	}
		
	hp = gethostbyname(argv[1]);

	server.sin_family = AF_INET;
	memcpy(&server.sin_addr,hp->h_addr, hp->h_length);
	server.sin_port = htons(6410);

	if (connect(mysock, (struct sockaddr*) &server, sizeof(server)) < 0 ){
		perror("connect to server failid");
		close(mysock);
		exit(1);
	}
	
        if (pthread_create(&sender_t, &at, sender,&mysock) < 0) {
                perror ("thread creation failed:");
                exit(-1);
        }

        if (pthread_create(&receiver_t, &at, receiver,&mysock) < 0) {
                perror ("thread creation failed:");
                exit(-1);
        }

        pthread_join(sender_t,0);
        pthread_join(receiver_t,0);
        close(mysock);
	
	return 0;
}
	
