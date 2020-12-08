// 1. Write generic program which accept one value and one number from user. Print
//    that value that number of times on screen. 

#include<iostream>
using namespace std;

template <class T>
class Display
{

public:
	void NoofTimes(int times,T value)
	{
		while(times != 0)
		{
			cout<<value<<"\t";
			times--;
		}
		cout<<"\n";
	}

};

int main()
{
	Display <int>obj1;
	int nooftimes = 0;
	int value = 0;
	cout<<"Enter the number of times\n";
	cin>>nooftimes;
	cout<<"Enter the integer value\n";
	cin>>value;
	obj1.NoofTimes(nooftimes,value);

	Display <float>obj2;
	int nooftimes1 = 0;
	float fvalue = 0;
	cout<<"Enter the number of times\n";
	cin>>nooftimes1;
	cout<<"Enter the float value\n";
	cin>>fvalue;
	obj2.NoofTimes(nooftimes1,fvalue);

	Display <char>obj3;
	int nooftimes2 = 0;
	char ch = 0;
	cout<<"Enter the number of times\n";
	cin>>nooftimes2;
	cout<<"Enter the char value\n";
	cin>>ch;
	obj3.NoofTimes(nooftimes2,ch);

	return 0;
}