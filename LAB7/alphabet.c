#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#define SIZE 2

void alpha(char * a) 
{
	char *next = (char *)calloc(2, sizeof(char));
	next[1] = '\0';
	if (*a == 'Z')
		next[0] = 'a';
	else if (*a == 'z')
		next[0] = 'A';
	else
		next[0] = *a + 1;
	*a = *next;
}

int main () 
{
	int id = shmget(IPC_PRIVATE, SIZE, S_IRUSR | S_IWUSR);
	char *sharedmemory = (char *)shmat(id, NULL, 0);
	*sharedmemory = '\0';
	pid_t pid;
	int i;
	*sharedmemory = 'A';
	for (i = 0; i < 52; ++i) 
	{
		pid = fork();
		if (pid == 0) 
		{
			while (*sharedmemory == '\0');
			alpha(sharedmemory);
			exit(0);

		} 
		else 
		{
            		printf("%s to -- ", sharedmemory);
			wait(NULL);
            		printf("%s\n", sharedmemory);
		}
	}
	shmdt(sharedmemory);
	return 0;
}
