#include <stdio.h>
#include <stdlib.h>
#define n 5
#define m 3 
int available[m],allocation[n][m],request[n][m];

int detection()
{
	int work[m],finish[n],i,j;
	//Initialzation	
	for(i=0;i<m;i++)
		work[i]=available[i];
	for(i=0;i<n;i++)
	{
		int c=0;
		for(j=0;j<m;j++)
			if(allocation[i][j] != 0)
				c++;
		if(c==0)
			finish[i] = 1;
		else
			finish[i] = 0;
	}


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
				if(request[i][j]>work[j])
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
			return 1;
	return 0;

}

int main()
{
	int i,j,process;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&allocation[i][j]);

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&request[i][j]);

	for(j=0;j<m;j++)
		scanf("%d",&available[j]);

	int deadlock = detection();

	if(deadlock)
		printf("Deadlock is present.\n");
	else
		printf("No deadlock\n");
	
}