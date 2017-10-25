#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int scan(int arr[],int n,int head){
	int i=0,j,movement=0,rem=n,move=-1;;
	int* serviced = (int*)calloc(n,sizeof(int));
	while(arr[i]<head){i++;}i--;
	while(rem)
	{
		printf("%d\n", head);
		if(i==0)
			move=1;
		else if(i==n)
			move=-1;
		if(!serviced[i])
		{
			movement+=abs(arr[i]-head);
			printf("Move %d\n", abs(arr[i]-head));
			serviced[i]=1;
			head=arr[i];
			rem--;
		}
		i+=move;
	}
	return movement;
}
int main(int argc, char const *argv[])
{
	int n,i,head,max_size;
	printf("Enter max no of cylinders\n");scanf("%d",&max_size);
	printf("Enter current location of HEAD\n");scanf("%d",&head);
	printf("Enter no. of requests\n");scanf("%d",&n);
	int* arr = (int*)calloc(n+2,sizeof(int));
	printf("Enter request numbers\n");
	for(i = 0;i<n;i++)
		scanf("%d",arr+i);
	n+=2;
	arr[n-2]=0;arr[n-1]=max_size;
	qsort(arr,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
		printf("%d,", arr[i]);
	printf("\n");
	printf("THM: %d\n",scan(arr,n,head));
	return 0;
}