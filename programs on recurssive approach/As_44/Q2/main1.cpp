/*  Problen statement :3.Write a recursive program which display below pattern.
Output : 1  2   3   4   5
*/
using namespace std;

#include <iostream>

class Demo
{
    private:

    int iValue;
    //int iValue2;
    public:

    void Display(int iValue)
    {
        if(iValue < 0)
        {
            iValue = -iValue;
        }
        static int iValue2 = 1;

        if(iValue2 <= iValue)
        {
            cout<<iValue2<<'\t';
            iValue2++;
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






