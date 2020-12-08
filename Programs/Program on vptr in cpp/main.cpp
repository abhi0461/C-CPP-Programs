using namespace std;
#include <iostream>

class Base
{
    public:
    int i,j;
    virtual void fun()
    {
        cout<<"Base fun\n";
    }

    virtual void gun()
    {
        cout<<"Base gun\n";
    }

    void sun()
    {
        cout<<"Base sun\n";
   }
};

class Derived: public Base
{
    public:
    int x,y;

    void fun()
    {
        cout<<"Derived fun\n";
    }

    void sun()
    {
        cout<<"Derived sun\n";
    }

    virtual void run()
    {
        cout<<"Derived run\n";
    }
};

int main()
{
    Base bobj;
    Derived dobj;
    cout<<"sizeof(bobj)";
    cout<<"sizeof(dobj)";

    long int* op = (long int*)(&dobj);
    cout<<"Base address bobj is:"<<op<<"\n";

    long int* vptr =(long int*)(*op);
    cout<<"Address of VTABLE is :"<<vptr<<"\n";

    void (*fp)();

    fp = (void(*)()) (*vptr);
    fp();

    fp = (void(*)()) (*(vptr+1));
    fp();

    fp = (void(*)()) (*(vptr+2));
    fp();

    return 0;
}




























