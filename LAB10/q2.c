#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
	int page_size,tot_page,page_no,offset,add;
	printf("Enter Page Size:");
	scanf("%d",&page_size);
	printf("Enter total number of pages:");
	scanf("%d",&tot_page);

	printf("Enter logical memeory address:");
	scanf("%d %d",&page_no,&offset);
	int c = page_no<<((int)(log(page_size)/log(2)));
	int address = c + offset;
	printf("%d\n", address);

	printf("Input logical address:");
	scanf("%d",&add);

	page_no = add/page_size;
	offset = add-page_no*page_size;
	printf("Page Number: %d. Offset: %d.",page_no,offset);
}