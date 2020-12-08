#include<stdio.h>
#include<stdlib.h>
struct node
	{
		int data;
		struct node * next;
	};
	typedef struct node NODE;
	typedef struct node* PNODE;
	typedef struct node** PPNODE;

void InsertNode( PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn -> data = iNo;
	newn -> next = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	} 
	else
	{
		newn -> next = *Head;
		*Head = newn;
	}
}
void Display( PNODE Head)
{

	while(Head != NULL)
	{
		printf("%d\t",Head->data);
		Head = Head -> next;
	}
}
		
int main()
{
	

	PNODE first = NULL;

	InsertNode(&first,21);
	InsertNode(&first,51);
	InsertNode(&first,71);

	Display(first);

	return 0;
} 