#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int sstf(int arr[],int n,int head){
	int i,j,movement=0;
	int* serviced = (int*)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		int min=INT_MAX,new_head = -1;
		for(j=0;j<n;j++)
		{
			if(!serviced[j] && abs(arr[j]-head)<min)
			{
				min = abs(arr[j]-head);
				new_head = j;
			}
		}
		movement+=abs(head-arr[new_head]);
		head=arr[new_head];
		serviced[new_head]=1;
	}
	return movement;
}
int main(int argc, char const *argv[])
{
	int n,i,head;
	printf("Enter current location of HEAD\n");scanf("%d",&head);
	printf("Enter no. of requests\n");scanf("%d",&n);
	int* arr = (int*)calloc(n,sizeof(int));
	printf("Enter request numbers\n");
	for(i = 0;i<n;i++)
		scanf("%d",arr+i);

	printf("THM: %d\n",sstf(arr,n,head));
	return 0;
}
