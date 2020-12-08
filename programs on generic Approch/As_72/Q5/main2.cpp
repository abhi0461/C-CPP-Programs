/*	5. Write generic program to accept N values and reverse the contents.
Input : 10 20 30 10 30 40 10 40 10
Output : 10 40 10 40 30 10 30 20 10 
*/
#include<iostream>
using namespace std;

template <class T>
class Check
{
public:
	int cnt;
public:
	void Frequency(int size,T arr[])
	{
		cnt = 0;	
		T brr[size]; 

		for(int i = size-1, j = 0; i >= 0; i--, j++)
		{
			brr[j] = arr[i];
		}

		cout<<"Array after reversing : ";
		for(int j = 0; j < size; j++)
		{
			cout<<brr[j]<<"\t";
		}
		cout<<"\n";
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
	obj1.Frequency(size,arr);

	Check <double>obj2;
	double brr[size];
	double fvalue = 0;
	cout<<"\nEnter the double values\n";
	for(int i = 0; i < size; i++)
	{
		cin>>brr[i];
	}
	obj2.Frequency(size,brr);

	Check <char>obj3;
	char crr[size];
	char ch = 0;
	cout<<"\nEnter the character values\n";
	for(int i = 0; i < size; i++)
	{
		cin>>crr[i];
	}
	obj3.Frequency(size,crr);

	return 0;
}