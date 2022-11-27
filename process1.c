#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO1 "fifo1"
#define FIFO2 "fifo2"

int main()
{
	char buf[100],buf1[100];
	int fd,fd1;
	printf("\n__________________________________________\n");
	printf("\nEnter a string with fullstop at end : \n");
	printf("\n__________________________________________\n");
	
	scanf("%[^\n]",buf);
	
	mkfifo(FIFO1,0666);          //creates a named pipe
	
	fd=open(FIFO1,O_WRONLY);
	write(fd,buf,100);
	printf("\n__________________________________________\n");
	printf("\nMessage sent");
	printf("\n__________________________________________\n");
	close(fd);                    //unlink(FIFO1);
	
	fd1=open(FIFO2,O_RDONLY);
	read(fd1,buf1,100);
	printf("\n__________________________________________\n");
	printf("\nMessage received");
	printf("\n__________________________________________\n");
	printf("\n%s",buf1);
	close(fd1);
	
	return 0;
}

