#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t new_pid;
	new_pid = fork();
	int i,status;char* str;	
	if(new_pid == -1)
		printf("Fork failed");
	else if(new_pid == 0)
	{
		str = "From Child";
	}
	else if(new_pid > 0)
	{	
		wait(&status);
		str = "From Parent";
	}
	for(i=0;i<5;i++)
			puts(str);
}
