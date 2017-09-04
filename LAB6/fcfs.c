#include <stdio.h>
#include <stdlib.h>
typedef struct process{
	int arrTime,burstTime,priority,waitTime,turnTime,startTime,endTime;
}Process;

int main()
{
	int n,i;
	printf("Enter number of processes.\n");
	scanf("%d",&n);
	Process** p = (Process**)calloc(n,sizeof(Process*));
	printf("Enter Arrival Time, Burst Time, Priority of %d processes.\n",n);
	for(i=0;i<n;i++)
	{
		p[i] = (Process*)malloc(sizeof(Process));
		scanf(" %d %d %d \n",&(p[i]->arrTime),&(p[i]->burstTime),&(p[i]->priority));
	}

	int t=0,totWaitTime=0,totTurnTime=0;
	
	printf("Start Time\tProcess\t\tEnd Time\tWait Time\tTurnaround Time\n");
	for(i=0;i<n;i++)
	{
		if(p[i]->arrTime>t)
			t=p[i]->arrTime;

		p[i]->waitTime = t - p[i]->arrTime;
		p[i]->startTime = t;
		t+=p[i]->burstTime;
		p[i]->endTime = t;
		p[i]->turnTime = p[i]->burstTime + p[i]->waitTime;
	
		printf("%d\t\tP%d\t\t%d\t\t%d\t\t%d\n",p[i]->startTime,i+1,p[i]->endTime,p[i]->waitTime,p[i]->turnTime);
		
		totWaitTime+=p[i]->waitTime;
		totTurnTime+=p[i]->turnTime;
	}

	printf("Average wait time: %f.\nAverage turnaround time: %f.\n",(float)totWaitTime/n,(float)totTurnTime/n);
	return 0;
}	