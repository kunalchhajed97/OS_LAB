#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
struct shared_use_st{
	int written_by_you;
	char text[2048];
};
int main(){
	void *shared_memory = (void *)0;
	struct shared_use_st *shared_stuff;
	char buffer[2048];
	int shmid;
	char *buf;
	char msg[] = {"END"};
	shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid==-1){
		fprintf(stderr,"shmget failed\n");
		exit(EXIT_FAILURE);
	}
	shared_memory = shmat(shmid,(void *)0,0);
	if(shared_memory == (void *)-1){
		fprintf(stderr,"shmat failed\n");
		exit(EXIT_FAILURE);
	}
	shared_stuff = (struct shared_use_st *)shared_memory;
	shared_stuff->written_by_you = 0;
	while(1){
		while(shared_stuff->written_by_you == 1){
			sleep(1);
			printf("Waiting for the consumer\n");
		}
		buf  = (char *)calloc(100,sizeof(buf));
		printf("Enter a text\n");
		fgets(buf,sizeof(buf),stdin);
		strcpy(shared_stuff->text,buf);
		shared_stuff->written_by_you = 1;
		if(strcmp(buf,msg)==0){
			printf("You killed the producer\n");
			break;
		}
	}
	if(shmdt(shared_memory)==-1){
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
