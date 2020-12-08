/*  Problen statement : 1. Write a recursive program which display below pattern.
Output : * * * * * 
*/
using namespace std;

#include <iostream>

class Demo
{
    private:

    int iValue;
    
    public:

    void Display(int iValue)
    {
        if(iValue < 0)
        {
            iValue = -iValue;
        }
        
        if(iValue > 0)
        {
            cout<<"*"<<'\t';
            iValue--;
            Display(iValue);

        }
    }
};

int main()
{
    Demo obj;
    int iNo = 0;
    cout<<"Enter number of stars you want to Display"<<'\n';
    cin>>iNo;

    obj.Display(iNo);

    return 0;
}






