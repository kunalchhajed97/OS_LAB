#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
	pid_t new_pid;
	new_pid = fork();
	int i,status;char* str;	
	if(new_pid == -1)
		printf("Fork failed");
	else if(new_pid == 0)
	{
		exit(0);
	}
	else if(new_pid > 0)
	{	
		sleep(1);
		execl("/bin/ps","ps","-e",NULL);
		printf("Parent Ending\n");
	}
}
