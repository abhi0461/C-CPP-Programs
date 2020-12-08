/*                  Singly Linear Linked list                   */

using namespace std;
#include<iostream>

typedef struct node
{
    int data;
    struct node* next;
}NODE,*PNODE;

class SinglyLL
{
    private:
        PNODE Head;
        int iSize;
    
    public:
        SinglyLL();
        ~SinglyLL();
        void InsertFirst(int);
        void InsertLast(int);
        void Display();
        int Count();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int,int);
        void DeleteAtPos(int);
        
};

        SinglyLL::SinglyLL()
        {
            iSize = 0;
            Head = NULL;
           // cout<<"Inside constructer \n";
        }

        SinglyLL::~SinglyLL()
        {
           // cout<<"Inside Destructer \n";
            delete(Head);

        }
        void SinglyLL::InsertFirst(int value)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn->next = NULL;
            newn->data = value; 

            if(Head == NULL)
            {
                Head = newn;
            }
            else
            {
                newn->next = Head;
                Head = newn;
            }
            iSize++;
            
        }
        void SinglyLL::InsertLast(int value)
        {
            PNODE newn = NULL;
            newn = new NODE;
            newn->next = NULL;
            newn->data = value; 

            if(Head == NULL)
            {
                Head = newn;
            }
            else
            {   
                PNODE temp = Head;
                while(temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newn;
            }
            iSize++;
        }
        
        void SinglyLL::Display()
        {
            PNODE temp = Head;
            while(temp != NULL)
            {
                cout<<temp->data<<" --> ";
                temp = temp->next;
            }
            cout<<" NULL ";
            cout<<"\n";
        }

        int SinglyLL::Count()
        {
            return iSize;   
        }
        
        void SinglyLL::DeleteFirst()
        {
            PNODE temp = Head;

            if(Head == NULL)
            {
                return;
            }

            if(Head->next == NULL)
            {
                delete(Head);
                Head = NULL;
            }
            else
            {
                Head = Head->next;
                delete(temp); 
            }
            iSize--;
        }

        void SinglyLL::DeleteLast()
        {
            if(Head == NULL)
            {
                return;
            }
            PNODE temp = Head;

            if(Head->next == NULL)
            {
                delete(Head);
                Head = NULL;
            }
            else
            {
                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                delete(temp->next);
                temp->next = NULL;
            }
            iSize--;
        }
        void SinglyLL::InsertAtPos(int value,int pos)
        {
            PNODE temp = Head;
            PNODE newn = NULL;
                        
            if((pos < 1) || (pos > (iSize + 1)))       // Invalid Position
            {
                return;
            }

            if(pos == 1)        // First position
            {
                InsertFirst(value);
            }
            else if(pos == iSize + 1)    // Last position
            {
                InsertLast(value);
            }
            else
            {
                newn = new NODE;
                newn->next = NULL;
                newn->data = value; 

                for(int i=1; i < pos-1; i++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn;
                iSize++;
            }
        }

        void SinglyLL::DeleteAtPos(int pos)
        {
            PNODE temp = Head;
                   
            if((pos < 1) || (pos > iSize))       // Invalid Position
            {
                return;
            }

            if(pos == 1)        // First position
            {
                DeleteFirst();
            }
            else if(pos == iSize)    // Last position
            {
                DeleteLast();
            }
            else
            {
                for(int i = 1; i< pos-1; i++)
                {
                    temp = temp->next;
                }
                PNODE temp2 = temp->next;

                temp->next = temp->next->next;
                delete(temp2);
                iSize--;
            }
        }
        
int main()
{
    SinglyLL obj;

    int choice = 1;
    int no,pos = 0;
    while(choice)
    {
        cout<<"Enter your choice...\n";
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


