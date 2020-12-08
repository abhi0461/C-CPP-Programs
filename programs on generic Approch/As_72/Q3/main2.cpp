/*	3. Write generic program to accept N values and search first occurrence of any
specific value.
Input : 10 20 30 10 30 40 10 40 10
Value to search : 40
Output : 6 
*/
#include<iostream>
using namespace std;

template <class T>
class Check
{
public:
	int i;
public:
	void Frequency(int size,T arr[],T value)
	{
		//i = 0;	
		for(int i = 0; i < size; i++)
		{
			if(arr[i] == value)
			{	
				cout<<"first occurrence of given value is : "<<i;
				break;
			}
		}
		//cout<<"first occurrence of given value is : "<<i;
	}

};

int main()
{
	Check <int>obj1;
	int size= 0;
	cout<<"Enter the size of array\n";
	cin>>size;
	int arr[size];
	int value = 0;
	cout<<"\nEnter the integer values\n";
	for(int i = 0; i < size; i++)
	{
		cin>>arr[i];
	}
	cout<<"\nEnter the integer value to check its frequency\n";
	cin>>value;
	obj1.Frequency(size,arr,value);

	Check <double>obj2;
	double brr[size];
	double fvalue = 0;
	cout<<"\nEnter the double values\n";
	for(int i = 0; i < size; i++)
	{
		cin>>brr[i];
	}
	cout<<"\nEnter the double value to check its frequency\n";
	cin>>fvalue;
	obj2.Frequency(size,brr,fvalue);

	Check <char>obj3;
	char crr[size];
	char ch = 0;
	cout<<"\nEnter the character values\n";
	for(int i = 0; i < size; i++)
	{
		cin>>crr[i];
	}
	cout<<"\nEnter the character value to check its frequency\n";
	cin>>ch;
	obj3.Frequency(size,crr,ch);

	return 0;
}