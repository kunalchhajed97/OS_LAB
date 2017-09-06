#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() 
{
	int n;
	int fd[2];
	char buf[256];
	char *data="Hi, This is Utkarsh Agarwal!";
	pipe(fd);
	write(fd[1],data,strlen(data));
	if((n=read(fd[0],buf,256))>=0)
	{
		buf[n]='\0';
		printf("Message: %s\n",buf);
	}
	else
	{
		perror("error");
	}
	return 0;
}
