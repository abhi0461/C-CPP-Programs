								/*  Doubly Linear linked list */

#include<stdio.h>
#include<stdlib.h>

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		newn -> next = *Head;
		(*Head )->prev = newn;
		*Head = newn;		
	}	
}

void Display(PNODE Head)
{
	while(Head != NULL)
	{
		printf("| %d |-->",Head->data);
		Head = Head -> next;
	}
	printf("| NULL |");
}

void DisplayX(PNODE Head)
{
	PNODE temp = Head;
	while(Head->next != NULL)
	{
		temp = temp ->next;
	}
	while(Head != NULL)
	{
		printf("|%d|->",Head->data);
		Head = Head -> prev;
	}

}




int Count(PNODE Head)
{
	int iCnt = 0;
	while(Head != NULL)
	{
		iCnt++;
		Head = Head ->next;
	}
	return iCnt;
}

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn = NULL;
	PNODE temp = NULL;
	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;

	if(*Head == NULL)
	{
		*Head = newn;
	}
	else
	{
		temp = *Head;
		while(temp -> next != NULL)
		{
			temp = temp -> next;
			
		}
		temp ->next =newn;
		newn ->prev = temp;		
	}
}

void DeleteFirst(PPNODE Head)
{
	if((*Head) == NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
	}
	else
	{		
		(*Head) = (*Head) -> next;
		free((*Head) -> prev);
		(*Head) -> prev = NULL;
	}

}
void DeleteLast(PPNODE Head)
{
	PNODE temp = *Head;
	if(*Head == NULL)           // Empty LL
    {
        return;
    }

	else if((*Head)-> next == NULL )
	{
		free(*Head);
		(*Head) = NULL;
	}
	else
	{
		while(temp -> next->next != NULL)
		{
			temp = temp -> next;
		}
		free(temp -> next);
		temp -> next =NULL;
	}
}

void InsertAtPos(PPNODE Head,int iNo,int Pos)
{
	PNODE newn = NULL;
	/*newn = (PNODE)malloc(sizeof(NODE));
	newn->data = iNo;
	newn->next = NULL;
	newn->prev = NULL;*/
	int i = 0;
	int Size = Count(*Head);
	PNODE temp = *Head;

	if((Pos < 1)||(Pos > (Size +1)))
	{
		return;
	}	
	if(Pos == 1)
	{
		InsertFirst(Head,iNo);
	}
	else if(Pos == (Size + 1))
	{
		InsertLast(Head,iNo);
	}
	else
	{
		newn = (PNODE)malloc(sizeof(NODE));
		newn->data = iNo;
		newn->next = NULL;
		newn->prev = NULL;
		for(i = 1;i < Pos-1;i++)
		{
			temp = temp->next;
		}
		newn->next = temp->next;
		temp->next->prev = newn;
		temp->next = newn;
		newn->prev = temp; 
	}
}

int main()
{
	PNODE First = NULL;
	int iValue = 0;
	int iPos = 0;

	printf("Enter number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,iValue);

	printf("Enter number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,iValue);

	printf("Enter number\n");
	scanf("%d",&iValue);
	InsertFirst(&First,iValue);


	Display(First);


	int iRet = Count(First);
	printf("\nNumber of nodes are : %d\n",iRet);

	printf("\nEnter number for insert in last\n");
	scanf("%d",&iValue);
	InsertLast(&First,iValue);

	printf("Enter number for insert in last\n");
	scanf("%d",&iValue);
	InsertLast(&First,iValue);


	Display(First);

	printf("\nNow Deleting first node\n");
	DeleteFirst(&First);


	Display(First);


	printf("\nNow Deleting Last node\n");
	DeleteLast(&First);


	Display(First);

	DisplayX(First);

	/*printf("\nEnter new number for Enter in position\n");
	scanf("%d",&iValue);
	printf("\nAlso Enter the position at which node has to be insert\n");
	scanf("%d",iPos);
	InsertAtPos(&First,iValue,iPos);

	Display(First);*/


}

