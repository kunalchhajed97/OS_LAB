#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node* next;
}Node;
Node* getNode(int val)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = val;
	return new;
}
Node* insert(Node* head,int val)
{
	if(head == NULL)
	{
		head = getNode(val);
		head->next = head;
		return head;
	}
	else
	{
		Node* temp = head;
		int flag = 0;
		while(temp!=head)
		{
			if(temp->data == val)
				flag = -1;
			temp=temp->next;
			flag++;
		}
		// if(flag != -1)
		// {
		// 	if(flag < FRAME )
		// }

	}
}
int fifo(int arr[],int n)
{
	Node* head = NULL;
	int len = 0;
	for (int i = 0; i < n; ++i)
	{
		head = insert(head,arr[i]);
		head = head->next;
	}

	


}
int main()
{
	int n;
	printf("Enter number of pages.\n");
	scanf("%d",&n);
	int* arr = (int*)calloc(n,sizeof(int));
	printf("Enter %d page numbers\n",n);
	for (int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	fifo(arr,n);
}		