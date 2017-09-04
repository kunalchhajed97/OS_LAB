#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct process{
	int id,arrTime,burstTime,priority,waitTime,turnTime,startTime,endTime;
}Process;

Process* highestPriorityAfterT(Process** p,int n,int t)
{
	int maxPriority=INT_MAX,i;
	Process* maxP = NULL;
	for(i=0;i<n;i++)
		if(p[i]->arrTime<=t && p[i]->priority < maxPriority && p[i]->burstTime!=0)
		{	
			maxPriority = p[i]->priority;
			maxP = p[i];
		}
	return maxP;
}
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
		p[i]->id = i+1;
	}

	int t=0,totWaitTime=0,totTurnTime=0;
	
	printf("Start Time\tProcess\t\tEnd Time\tWait Time\tTurnaround Time\n");



	for(i=0;i<n;i++)
	{
		if(p[i]->arrTime>t)
			t=p[i]->arrTime;

		Process* curr = highestPriorityAfterT(p,n,t);

		curr->waitTime = t - curr->arrTime;
		curr->startTime = t;
		t+=curr->burstTime;
		curr->endTime = t;
		curr->turnTime = curr->burstTime + curr->waitTime;

		curr->burstTime = 0;
		printf("%d\t\tP%d\t\t%d\t\t%d\t\t%d\n",curr->startTime,curr->id,curr->endTime,curr->waitTime,curr->turnTime);
		
		totWaitTime+=curr->waitTime;
		totTurnTime+=curr->turnTime;
	}

	printf("Average wait time: %f.\nAverage turnaround time: %f.\n",(float)totWaitTime/n,(float)totTurnTime/n);
	return 0;
}	