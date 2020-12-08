//     Doubly Circular Linked list


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
class DoublyLinkedList
{
public:
	struct node<T> *Head;
	struct node<T> *Tail;

	DoublyLinkedList()
	{
		Head = NULL;
		Tail = NULL;
	}

	void InsertFirst(T no)
   {
	
	struct node<T>*  newn = new node<T> ;
	newn -> data = no;
	newn -> next = NULL;
	newn -> prev = NULL;
	 
	
	  if((Head ==NULL) && (Tail == NULL)) 
     {
      Head = newn;
      Tail = newn;
      }
       else 
      {
        newn->next = Head;
		
	(Head)->prev = newn;
	Head = (Head)->prev;
      }
         (Tail)->next = Head;
         (Head)->prev = Tail; 
	
}

	void InsertLast(T no)
	{
	    struct node<T>* newn = new node<T>;
	    newn->data = no;
	    newn->next = NULL;
	    newn->prev = NULL;

	    if((Head == NULL)&&(Tail == NULL))
	    {
	        Head = newn;
	        Tail = newn;
	    }
	    else
	    {
	        (Tail)->next = newn;
	        newn->prev = Tail;
	        Tail = newn;
	    }
	    newn->next = Head;
	    (Head)->prev = newn;
	}


void Display()
{
    if((Head == NULL)&&(Tail == NULL))
    {
        return;
    }
    
    do
    {
        cout<<"|"<<Head->data<<"|-->";
        Head = Head->next;

    } while (Head != Tail->next);
    cout<<"| NULL |";
}

int Count()
{
    int iCnt = 0;
    if((Head == NULL)&&(Tail == NULL))
    {
        return 0;
    }
    
    do
    {
        iCnt++;
        Head = Head->next;

    } while (Head != Tail->next);
    
    return iCnt;
}

	void DeleteFirst()
	{
	    if((Head == NULL)&&(Tail == NULL))
	    {
	        return;
	    }

	    if((Head)->next == Head)
	    {
	        delete(Head);
	    
	        Head = NULL;
	        Tail = NULL;
	    }
	    else
	    {
	        Head = (Head)->next;
	        delete((Tail)->next);
	    }
	    (Tail)->next = Head;
	    (Head)->prev = Tail;
	}

	void DeleteLast()
	{
	    if((Head == NULL)&&(Tail == NULL))
	    {
	        return;
	    }

	    if((Head)->next == Head)
	    {
	        delete(Head);
	    
	        Head = NULL;
	        Tail = NULL;
	    }
	    else
	    {
	        Tail = (Tail)->prev;
	        delete((Head)->prev);
	    }
	    (Tail)->next = Head;
	    (Head)->prev = Tail;
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
	DoublyLinkedList <char> obj;

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
