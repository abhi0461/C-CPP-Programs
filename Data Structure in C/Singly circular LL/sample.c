/* 				Singly Circular Linked List            */

#include<stdio.h>
#include<stdlib.h>

typedef struct Node NODE;
typedef struct Node* PNODE;
typedef struct Node** PPNODE;

struct Node
{
	int data;
	struct Node* next;
};

void InsertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn = NULL;

	newn =(PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		newn->next = *Head;
		*Head = newn;
	}
	(*Tail)->next = newn;
}

void Display(PNODE Head,PNODE Tail)
{
	if((Head == NULL)&&(Tail == NULL))
	{
		return;
	}
	
	do
	{

		printf("| %d |-->",Head->data);
		Head = Head->next;

	} while (Head != Tail->next);
	printf("| NULL |");

}

int Count(PNODE Head,PNODE Tail)
{
	int iCnt = 0;

	if((Head == NULL)&&(Tail == NULL))
	{
		return -1;
	}
	
	do
	{
		
		iCnt++;
		Head = Head->next;

	} while (Head != Tail->next);

	return iCnt;
}

void InsertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn = NULL;

	newn =(PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;

	if((*Head == NULL)&&(*Tail == NULL))
	{
		*Head = newn;
		*Tail = newn;
	}
	else
	{
		(*Tail)->next = newn;
		*Tail = newn;

	}
	newn->next = *Head;
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}

	if((*Head)->next == *Head)
	{
		free(*Head);
	
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		*Head = (*Head)->next;
		free((*Tail)->next);
		(*Tail)->next = *Head;
	}
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
	if((*Head == NULL)&&(*Tail == NULL))
	{
		return;
	}

	if((*Head)->next == *Head)
	{
		free(*Head);
	
		*Head = NULL;
		*Tail = NULL;
	}
	else
	{
		PNODE temp = NULL;
		temp = *Head;

		while(temp->next != *Tail)
		{
			temp = temp->next;
		}
		free(*Tail);
		temp->next = *Head;
		*Tail = temp;
	}
}

void InsertAtPos(PPNODE Head,PPNODE Tail,int iNo,int Pos)
{
	PNODE newn = NULL;
	PNODE temp = NULL;
	int i = 0;

	int size = Count(*Head,*Tail); 
	if((Pos < 1)||(Pos > (size+1)))
	{
		return;
	}

	if(Pos == 1)
	{
		InsertFirst(Head,Tail,iNo);
	}
	else if(Pos == (size+1))
	{
		InsertLast(Head,Tail,iNo);
	}
	else
	{
		temp = *Head;
		newn =(PNODE)malloc(sizeof(NODE));
		newn->data = iNo;
		newn->next = NULL;
		
		for(i = 1; i< Pos-1; i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next = newn;

	}
}

void DeleteAtPos(PPNODE Head,PPNODE Tail,int Pos)
{
	PNODE newn = NULL;
	PNODE temp1 = NULL;
	PNODE temp2 = NULL;
	int i = 0;

	int size = Count(*Head,*Tail); 
	if((Pos < 1)||(Pos > (size)))
	{
		return;
	}

	if(Pos == 1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(Pos == size)
	{
		DeleteLast(Head,Tail);
	}
	else
	{	
		temp1 = *Head;
		for(i = 1;i< Pos-1;i++)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		free(temp2);
	}
}

int main()
{
	PNODE First = NULL;
	PNODE Last = NULL;
	int iValue = 0;
	int iPos = 0;

	printf("Enter Number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,&Last,iValue);

	printf("Enter Number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,&Last,iValue);

	printf("Enter Number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,&Last,iValue);
	
	printf("Enter Number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,&Last,iValue);

	printf("Nodes in linked list are :\n");
	Display(First,Last);


	int iRet = Count(First,Last);
	printf("\nNumber of nodes are : %d\n",iRet);

	printf("Enter Number to insert in last\n");
	scanf("%d",&iValue);
	printf("Linked list after insert in last is :\n");
	InsertLast(&First,&Last,iValue);


	Display(First,Last);

	printf("\nLinked list after deleting first node :\n");
	DeleteFirst(&First,&Last);

	Display(First,Last);

	printf("\nLinked list after deleting last node :\n");
	DeleteLast(&First,&Last);

	Display(First,Last);

	printf("\nEnter Position at which node has to be inserted :\n");
	scanf("%d",&iPos);
	printf("Enter Number to insert at given position\n");
	scanf("%d",&iValue);
	printf("Linked list after insert in given position is :\n");
	InsertAtPos(&First,&Last,iValue,iPos);

	Display(First,Last);

	printf("\nEnter Position from which node has to be deleted :\n");
	scanf("%d",&iPos);
	printf("Linked list after deleting from  given position is :\n");
	DeleteAtPos(&First,&Last,iPos);

	Display(First,Last);
}
