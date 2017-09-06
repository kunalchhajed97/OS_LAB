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
	int shmid;
	char msg[]={"END"};
	shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid == -1){
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
		if(shared_stuff->written_by_you ){
			if(strcmp(shared_stuff->text,msg)==0){
				printf("The producer just died\n");
				break;
			}
			printf("%s\n",shared_stuff->text);
			shared_stuff->written_by_you = 0;
			sleep(1);
		}
	}
	if(shmdt(shared_memory)==-1){
		fprintf(stderr, "shmdt failed\n");
		exit(EXIT_FAILURE);
	}
	if(shmctl(shmid,IPC_RMID,0)==-1){
		fprintf(stderr,"shmctl failed\n");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
