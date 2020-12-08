//     Doubly Linear Linked list


#include <iostream>
using namespace std;


template <class T>
struct node
{
    T data;
    struct node* next;
    struct node* prev;
};

template <class T>
class DoublyLinearLinkedList
{
public:
	struct node<T> *Head;

	DoublyLinearLinkedList()
	{
		Head = NULL;
	}

	void InsertFirst(T no)
   {
	struct node<T>* newn = new node<T> ;
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	 
	
  	if(Head ==NULL) 
    {
     	Head = newn;
    }
    else 
    {
        newn->next = Head;
		Head->prev = newn;
		Head = (Head)->prev;
    }
}

	void InsertLast(T no)
	{
		struct node<T>*newn = new node<T>;
	    newn->data = no;
	    newn->next = NULL;
	    newn->prev = NULL;

	    if(Head == NULL)
	    {
	        Head = newn;
	    }
	    else
	    {
	    	struct node<T>*temp = Head;
	    	while(temp->next != NULL)
	    	{
	    		temp = temp->next;
	    	}
	    	temp -> next = newn;
	    	newn -> prev = temp;
	    }
	}


void Display()
{
    while(Head != NULL)
    {
    	cout<<"|"<<Head->data<<"|-->";
    	Head = Head->next;
    }
    cout<<"|NULL|";
}

int Count()
{
    int iCnt = 0;
    while(Head != NULL)
    {
    	iCnt++;
    	Head = Head->next;
    }
    return iCnt;
}

	void DeleteFirst()
	{
	    if(Head == NULL)
	    {
	        return;
	    }

	    if((Head)->next == NULL)
	    {
	        delete(Head);
	        Head = NULL;
	    }
	    else
	    {
	        Head = (Head)->next;
	        delete(Head->prev);
	 		Head->prev = NULL;
	    }
	}

	void DeleteLast()
	{
	    if(Head == NULL)
	    {
	        return;
	    }

	    if((Head)->next == NULL)
	    {
	        delete(Head);
	        Head = NULL;
	    }
	    else
	    {
	    	struct node<T>* temp = Head;
	    	while(temp->next->next != NULL)
	    	{
	    		temp = temp -> next;
	    	}
	    	delete(temp->next);
	    	temp->next = NULL;
	    }
	}

	void InsertAtPos(T no,int Pos)
	{
	    struct node<T>* newn = NULL;
	    struct node<T>* temp = NULL;
	    int i = 0;

	    int size = Count(); 
	    if((Pos < 1)||(Pos > (size+1)))
	    {
	        return;
	    }

	    if(Pos == 1)
	    {
	        InsertFirst(no);
	    }
	    else if(Pos == (size+1))
	    {
	        InsertLast(no);
	    }
	    else
	    {
	        temp = Head;
	        struct node<T>* newn = new node<T>;
	        newn->data = no;
	        newn->next = NULL;
	        newn->prev = NULL;

	        for(i = 1; i< Pos-1; i++)
	        {
	            temp = temp->next;
	        }
	        newn->next = temp->next;
	        temp->next->prev = newn; 
	        temp->next = newn;
	        newn->prev = temp;
	    }
	}

	void DeleteAtPos(int Pos)
	{
	    struct node<T>* newn = NULL;
	    struct node<T>* temp1 = NULL;
	    struct node<T>* temp2 = NULL;
	    int i = 0;

	    int size = Count(); 
	    if((Pos < 1)||(Pos > (size)))
	    {
	        return;
	    }

	    if(Pos == 1)
	    {
	        DeleteFirst();
	    }
	    else if(Pos == size)
	    {
	        DeleteLast();
	    }
	    else
	    {   
	        temp1 = Head;
	        for(i = 1;i< Pos-1;i++)
	        {
	            temp1 = temp1->next;
	        }
	        temp2 = temp1->next;
	        temp1->next = temp1->next->next;
	        delete(temp2);
	        temp1->next->prev = temp1;
	    }
	}

};

int main()
{
	DoublyLinearLinkedList <char> obj;

    int choice = 1;
    char no = '\0';
    int pos = 0;
    
    while(choice)
    {
        cout<<"\nEnter your choice...\n";
        cout<<"---------------------------\n";
        cout<<"1 : Insert at first \n";
        cout<<"2 : Insert at last \n";
        cout<<"3 : Display contents \n";
        cout<<"4 : Count number of nodes \n";
        cout<<"5 : Delete at first \n";
        cout<<"6 : Delete at last \n";
        cout<<"7 : Insert at position \n";
        cout<<"8 : Delete at position \n";
        cout<<"0 : Exit the application \n";
        cout<<"---------------------------\n";
        cin>>choice;

        switch(choice)
        {
            case 1: 
                cout<<"Enter number :\n";
                cin>>no;
                obj.InsertFirst(no);
                break;

            case 2:
                cout<<"Enter number \n";
                cin>>no;
                obj.InsertLast(no);
                break;

            case 3:
                cout<<"Elements in the linked list are : \n";
                obj.Display();
                break;

            case 4:
                cout<<"Number of elements are : "<<obj.Count()<<"\n";
                break;

            case 5:
                obj.DeleteFirst();
                break;

            case 6:
                obj.DeleteLast();
                break;

            case 7:
                cout<<"Enter position at which you want to insert node \n";
                cin>>pos;
                cout<<"Enter number \n";
                cin>>no;
                obj.InsertAtPos(no,pos);
                break;

            case 8:
                cout<<"Enter position from which you want to delete the node \n";
                cin>>pos;
                obj.DeleteAtPos(pos);
                break;

            case 0:
                cout<<"Thankyou for using this Application...\n";
                break;

            default:
                cout<<"Wrong Choice \n";
                break;

        }
    }

    return 0;
}
