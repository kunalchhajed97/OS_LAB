#include <stdlib.h>
#include <stdio.h>
int fcfs(int arr[],int n,int head){
	int i,movement=0;
	for(i=0;i<n;i++)
	{
		movement+=abs(head-arr[i]);
		head=arr[i];
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

	printf("THM: %d\n",fcfs(arr,n,head));
	return 0;
}
