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
		execl("./prog1","./prog1",(char*)NULL);
		printf("Error in exec\n");	
	}	
	else if(new_pid > 0)
	{	
		wait(&status);
		printf("Parent Complete\n");
	}
}
