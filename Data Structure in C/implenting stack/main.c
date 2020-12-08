// Implemainting stack in c
/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Data;
    struct Node* next;
};

typedef struct Node INODE;
typedef struct Node* PINODE;
typedef struct Node** PPINODE;

void Push(PPINODE Head, int value) // insert first
{
    PINODE newn = NULL;
    newn = (PINODE)malloc(sizeof(INODE));

    newn->Data = value;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    printf("Element pushed successfully at the top\n");
}

void Pop(PPINODE Head) // delete first
{
    if(*Head == NULL)
    {
        printf("Unable to pop : Stack is empty\n");
        return;
    }

    if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        PINODE temp = *Head;
        *Head = (*Head)->next;
        free(temp);
    }
    printf("Element poped successfully from the top\n");    
}

int Top(PINODE Head) // return first
{
    if(Head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return Head->Data;
}

int getMin(PINODE Head) // return minimum
{
    if(Head == NULL)
    {
        printf("Stack is empty\n");
        return -1;
    }

    int min = 0;
    if(Head->next == NULL)
    {
        min = Head->Data;
    }
    else
    {
        PINODE temp = Head;
        min = temp->Data;
        while(temp != NULL)
        {
            if(temp->Data < min)
            {
                min = temp->Data;
            }
            temp = temp->next;
        }
    }
    return min;
}

int main()
{
    int no = 0,top = 0,min = 0;
    PINODE First = NULL;

    top = Top(First);
    if(top != -1)
        printf("Top element of the stack is %d\n",top);

    min = getMin(First);
    if(min != -1)
        printf("Smallest data element of the stack is %d\n",min);

    Pop(&First);

    printf("Enter the value to push at top\n");
    scanf("%d",&no);
    Push(&First,no);

    printf("Enter the value to push at top\n");
    scanf("%d",&no);
    Push(&First,no);

    printf("Enter the value to push at top\n");
    scanf("%d",&no);
    Push(&First,no);

    printf("Enter the value to push at top\n");
    scanf("%d",&no);
    Push(&First,no);

    printf("Enter the value to push at top\n");
    scanf("%d",&no);
    Push(&First,no);


    top = Top(First);
    if(top != -1)
        printf("Top element of the stack is %d\n",top);

    min = getMin(First);
    if(min != -1)
        printf("Smallest data element of the stack is %d\n",min);

    Pop(&First);


    top = Top(First);
    if(top != -1)
        printf("Top element of the stack is %d\n",top);

    min = getMin(First);
    if(min != -1)
        printf("Smallest data element of the stack is %d\n",min);

    Pop(&First);


    top = Top(First);
    if(top != -1)
        printf("Top element of the stack is %d\n",top);

    min = getMin(First);
    if(min != -1)
        printf("Smallest data element of the stack is %d\n",min);

    return 0;
}