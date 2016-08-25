#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>

int sock;

void * sender(void *sock) {
	char buff[512];
	int *sock_fd = (int *) sock;
	while(1) {
		bzero(buff,512);
       		printf("<< : ");
       		fgets(buff,512,stdin);
		int len = strlen(buff) + 1;
		buff[len+1] = '\0';
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
			printf(">> : %s\n", buff);
		}

		memset(buff,0,strlen(buff));
	}

	pthread_exit(0);
}
	
	

void signal_handler(int sig) {
	printf("received user interrupt \n");
	close(sock);
	raise(SIGKILL);
}


int main (int argc, char **argv) {
	pthread_t sender_t, receiver_t;
	pthread_attr_t at;
	pthread_attr_init(&at);

	/*structure of struct sockaddr_in 
 	 * struct sockaddr_in {
 	 * 		short sin_family; = AF_INET(for most purpose)
 	 * 		struct in_addr sin_addr; contain unsigned long field for address.
 	 * 		u_short sin_port; contain port number to connect to.
 	 * 		char sin_zero[8]; not used currently.
 	 */ 		


	struct sockaddr_in server;
	int mysock;
	char buff[1024];
	int rval;
	
	signal(SIGINT, signal_handler);

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("failed to create sockte");
		exit(1);
	}

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(6410);

	/* bind the socket */
	if(bind(sock, (struct sockaddr *)&server, sizeof(server))) {
		perror("socket bind error");
		exit(1);
	}

	/*listen*/
	listen(sock,5);

	/*accept */
	mysock = accept(sock,(struct sockaddr *)0, 0);
	if (mysock == -1) {
		perror("accept failed");
		exit(-1);
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
	close(sock);

	return 0;
}
