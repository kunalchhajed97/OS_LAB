#include <stdio.h>
#include <stdlib.h>
#define n 5
#define m 3 
int available[m],max[n][m],allocation[n][m],need[n][m],request[m];

int safety()
{
	int work[m],finish[n]={0},i,j;
	//Initialzation	
	for(i=0;i<m;i++)
		work[i]=available[i];
	//Finding i
	int c=0;
	i=0;
	while(c<=n)
	{
		if(i==n)
			i=0;

		if(finish[i] == 0)
		{
			int flag=0;
			for(j=0;j<m;j++)
				if(need[i][j]>work[j])
					flag=1;

			if(flag == 0)
			{
				c=0;
				for(j=0;j<m;j++)
					work[j]+=allocation[i][j];
				finish[i]=1;
			}
			else
				c++;
		}
		else
			c++;
		i++;
	}

	for(i=0;i<n;i++)
		if(finish[i] == 0)
			return 0;
	return 1;

}

int resource_request(int process)
{
	int i;
	for(i=0;i<m;i++)
		if(request[i]>need[process][i])
			return -1;

	for(i=0;i<m;i++)
		if(request[i]>available[i])
			return 0;

	for(i=0;i<m;i++)
	{	
		available[i]-=request[i];
		allocation[process][i]+=request[i];
		need[process][i]-=request[i];
	}
	int safe = safety();
	if(safe)
		return 1;
	else
	{
		for(i=0;i<m;i++)
		{
			available[i]+=request[i];
			allocation[process][i]-=request[i];
			need[process][i]+=request[i];
		}
		return 0;
	}
}

int main()
{
	int i,j,process;
	printf("Enter allocation Matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);

	printf("Enter max Matrix: \n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - allocation[i][j];
		}

	printf("Enter available array: \n");
	for(j=0;j<m;j++)
		scanf("%d",&available[j]);

	int safe = safety();

	if(safe)
		printf("Safe\n");
	else
		printf("Not safe\n");


	printf("Enter request process and it's vector.\n");
	scanf("%d",&process);
	for(i=0;i<m;i++)
		scanf("%d",&request[i]);

	int grant = resource_request(process);
	if(grant == 1)
		printf("Resource can be granted immidiately.\n");
	else if(grant == 0)
		printf("Resource cannot be granted immidiately.\n");
	else if(grant == -1)
		printf("Error\n");
	
}