//			Display array

#include <iostream>
using namespace std;


class Array
{
public:
	int *Arr;
	int size;

	Array(int length = 5)
	{
		cout<<"Inside constructor\n";
		Arr = new int[length];
		size = length;
	}
	~Array()
	{
		cout<<"Inside destructor\n";
		delete []Arr;
	}
	void Accept()
	{
		cout<<"Enter the elements in the array\n";
		for(int i = 0; i < size; i++)
		{
			cin>>Arr[i]; 
		} 
	}
	void Dislpay()
	{
		cout<<"Entered elements are\n";
		for(int i = 0; i < size; i++)
		{
			cout<<Arr[i]<<"\t";
		}
		cout<<"\n";
	}

	bool SearchNDisplay(int value)
	{
		bool flag = false;
		for(int i = 0; i< size; i++)
		{
			if(Arr[i] == value)
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
};

int main()
{
	int size,no = 0;
	cout<<"Enter the size\n";
	cin>>size;

	Array *obj = new Array(size);

	obj->Accept();
	obj->Dislpay();

	cout<<"Enter number to search\n";
	cin>>no;
	bool bret = false;
	bret = obj->SearchNDisplay(no);

	if(bret == true)
	{
		cout<<"Element found\n";
	}
	else
	{
		cout<<"Element not found\n";
	}

	return 0;
}
