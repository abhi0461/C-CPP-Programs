/*  Problen statement :2. Write a recursive program which display below pattern.
Output : 1 2 3 4 5 
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
            cout<<iValue<<'\t';
            iValue--;
            Display(iValue);

        }
    }
};

int main()
{
    Demo obj;
    int iNo = 0;
    cout<<"Enter number :"<<'\n';
    cin>>iNo;

    obj.Display(iNo);

    return 0;
}






