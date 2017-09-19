#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex,wrt;
int readcount;
FILE *fp;
int dataLength = 5;
void *reader( void* param)
{
	sleep(0.1);
	int num = *(int*)param;
	char buffer[1000];
	int i=0;
	do
	{
		sem_wait(&mutex);
		readcount++;
		if(readcount == 1)
			sem_wait(&wrt);
		sem_post(&mutex);
		
		printf("#%d Reading: ",num);
		sleep(0.5);
		fscanf(fp,"%s",buffer);
		puts(buffer);
		printf("#%d Reading Ended\n", num);

		sem_wait(&mutex);
		readcount--;
		if(readcount == 0)
			sem_post(&wrt);
		sem_post(&mutex);
		i++;
	} while (i<5);

}

void *writer(void * param)
{
	int num = *(int*)param;
	int i = (num-1)*dataLength;
	do
	{
		sem_wait(&wrt);

		printf("#%d Writing started\n",num);
		sleep(1);
		fprintf(fp, "%d,", i);
		printf("#%d Writing complete\n",num);
		
		sem_post(&wrt);
		i++;
	} while (i<num*dataLength);
}

int main()
{
	pthread_t readers[5];
	pthread_t writers[5];
	sem_init( &mutex, 0, 1 );
	sem_init( &wrt,0,1);
	int i;
	fp = fopen("data.txt","a+");
	int indexes[]={1,2,3,4,5};
	for(i=0;i<5;i++)
	{	
		pthread_create( &writers[i], 0, writer, (void*)(indexes+i) );
		pthread_create( &readers[i], 0, reader, (void*)(indexes+i) );
	}
	sleep(100);
	// for(i=0;i<5;i++)
	// {	
	// 	pthread_join( readers[i], 0 );
	// 	pthread_join( writers[i], 0 );
	// }
	sem_destroy( &mutex );
	sem_destroy( &wrt );
	fclose(fp);
}