#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t new_pid;
	new_pid = fork();
	int i,status;char* str;	
	if(-1 == new_pid)
		printf("Fork failed");
	else if(0 == new_pid)
	{
		printf("Child's parent pid: %d\n",getppid());
		printf("Child's pid: %d\n",getpid());
	}	
	else if(new_pid > 0)
	{	
		printf("Parent's parent pid: %d\n",getppid());
		printf("Parent pid: %d\n",getpid());
		printf("Parent's child pid: %d\n",new_pid);
		
	}
}
