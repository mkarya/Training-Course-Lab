#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main (void) {
	//printf("hello, world\n");
	write(1,"I am good \n", 11);
	syscall(SYS_write,1, "hello, world\n", 14);

	return 0;
}
