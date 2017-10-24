#include <stdio.h>
#include <stdlib.h>
typedef struct process{
	int id,arrTime,burstTime,priority,waitTime,turnTime,startTime,endTime;
	struct process* next;
}Process;

int main()
{
	int n,i;
	printf("Enter number of processes.\n");
	scanf("%d",&n);
	Process* p = (Process*)calloc(n,sizeof(Process));
	printf("Enter PID's, Arrival Time, Burst Time, Priority of %d processes.\n",n);
	for(i=0;i<n;i++)
	{
		scanf(" %d %d %d %d \n",&(p[i].id),&(p[i].arrTime),&(p[i].burstTime),&(p[i].priority));
	}

	int t=0,totWaitTime=0,totTurnTime=0,c=0;
	
	printf("Start Time\tProcess\t\tEnd Time\n");
	i=1;
	
	

	Process* list = p;
	list->next = list;
	

	while(1)
	{
		// printf("Process P%d\n", list->id);
		if(list->burstTime!=0)
		{
			c=0;
			list->waitTime += t - ((list->endTime == 0)?list->arrTime:list->endTime);
			list->startTime = t;
			if(list->burstTime<quantum)
			{
				t+=list->burstTime;
				list->burstTime = 0;
			}
			else
			{
				t+=quantum;
				list->burstTime-=quantum;
			}
			Process* head = list;
			while(list->next!=head)
				list=list->next;

			while(i<n && t>=p[i].arrTime)
			{
				list->next = (p + i++);
				list = list->next;
			}
			list->next = head;
			list = list->next;

			list->endTime = t;
			printf("%d\t\tP%d\t\t%d\n",list->startTime,list->id,list->endTime);
		}
		else
			c++;
		
		list = list->next;
		
		if(c==n)
			break;
	}
	printf("Process\t\tTurnaround Time\tWait Time\n");
	for(i=0;i<n;i++)
	{
		p[i].turnTime = p[i].endTime-p[i].arrTime;
		totTurnTime += p[i].turnTime;
		totWaitTime += p[i].waitTime;
		printf("%d\t\t%d\t\t%d\n",p[i].id,p[i].turnTime,p[i].waitTime);
	}


	printf("Average wait time: %f.\nAverage turnaround time: %f.\n",(float)totWaitTime/n,(float)totTurnTime/n);
	return 0;
}	