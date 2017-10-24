#include <stdio.h>
#include <stdlib.h>

#define FRAME_SIZE 3 
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
Node* insert(Node* head,int val,int *c)
{
	if(head == NULL)
	{
		(*c)++;
		head = getNode(val);
		head->next = head;
		return head;
	}
	else
	{
		Node* temp = head;
		int flag = 0;
		do
		{
			if(temp->data == val)
			{
				flag = -1;
				break;
			}
			temp=temp->next;
			flag++;
		}while(temp!=head);
		if(flag == -1)
			return head;
		else
		{
			(*c)++;
			if(flag < FRAME_SIZE)
			{
				Node* t = getNode(val);
				t->next = head->next;
				head->next = t;
				return t;
			}
			else
			{
				head->next->data = val;
				return head->next;
			}
		}
	}
}
void printList(Node* head)
{
	Node* temp = head->next;
	printf("%d-->", head->data);
	while(temp!= head)
	{
		printf("%d-->", temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int fifo(int arr[],int n)
{
	Node* head = NULL;
	int c = 0;
	Node* p = NULL;
	for (int i = 0; i < n; ++i)
	{
		head = insert(head,arr[i],&c);
		if(i==0) p=head;
		printList(p);
	}
	return c;
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
	
	printf("No of page faults: %d\n",fifo(arr,n));
}		