#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int* first_fit(int memory[],int n,int process[],int m)
{
	int i,j;
	int* allocation = (int*)calloc(m,sizeof(int));
	int* used = (int*)calloc(n,sizeof(int));
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(!used[j] && memory[j]>=process[i])
			{
				used[j]=1;
				allocation[i] = j;
				break;
			}
		}
		if(j==n)
			allocation[i] = -1;
	}
	return allocation;
}

int* best_fit(int memory[],int n,int process[],int m)
{
	int i,j;
	int* allocation = (int*)calloc(m,sizeof(int));
	int* used = (int*)calloc(n,sizeof(int));
	for(i=0;i<m;i++)
	{
		int* hole = NULL;
		int flag = -1;
		for(j=0;j<n;j++)
			if(!used[j] && process[i]<=memory[j] && memory[j]<=(hole?*hole:INT_MAX))
			{
				flag = j;
				hole = &memory[j];
			}
		if(flag == -1)
			allocation[i] = -1;
		else
		{
			allocation[i] = flag;
			used[flag] = 1;
		}
	}
	return allocation;
}
int* worst_fit(int memory[],int n,int process[],int m)
{
	int i,j;
	int* allocation = (int*)calloc(m,sizeof(int));
	int* used = (int*)calloc(n,sizeof(int));
	for(i=0;i<m;i++)
	{
		int* hole = memory;
		int flag = -1;
		for(j=0;j<n;j++)
		{
			if(!used[j] && memory[j]>=*hole && process[i]<=memory[j])
			{	
				flag = j;
				hole = &memory[j];
			}
		}
		if(flag == -1)
			allocation[i] = -1;
		else
		{
			allocation[i] = (int)(hole-memory);
			used[hole-memory] = 1;
		}
	}
	return allocation;
}


int main()
{
	int i,n,m;
	printf("Enter number of Memory partitions:\n");
	scanf("%d",&n);
	int* memory = (int*)calloc(n,sizeof(int));
	printf("Enter %d Memory partitions sizes:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&memory[i]);

	printf("Enter number of Processes:\n");
	scanf("%d",&m);
	int* process = (int*)calloc(m,sizeof(int));
	printf("Enter %d process sizes:\n",m);
	for(i=0;i<m;i++)
		scanf("%d",&process[i]);

	int* first = first_fit(memory,n,process,m);
	int* best = best_fit(memory,n,process,m);
	int* worst = worst_fit(memory,n,process,m);

	
	printf("----------FIRST FIT----------\n");
	for(i=0;i<m;i++)
		printf("%d --> %d\n", process[i],memory[first[i]]);
	printf("----------BEST FIT----------\n");
	for(i=0;i<m;i++)
		printf("%d --> %d\n", process[i],memory[best[i]]);
	printf("----------WORST FIT----------\n");
	for(i=0;i<m;i++)
		printf("%d --> %d\n", process[i],memory[worst[i]]);
}