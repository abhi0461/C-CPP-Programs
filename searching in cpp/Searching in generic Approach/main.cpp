//			Display array : Genaric approach

#include <iostream>
using namespace std;

template <class T>
class Array
{
public:
	T *Arr;
	int size;

	Array(int length = 5)
	{
		cout<<"Inside constructor\n";
		Arr = new T[length];
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

	bool SearchNDisplay(T value)
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
	int size = 0;
	cout<<"Enter the size\n";
	cin>>size;

	int no = 0;
	Array<int>*obj;
	obj = new Array<int>(size);
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

	float fno = 0.0;
	Array <float> *obj1;
	obj1 = new Array<float> (size);

	obj1->Accept();
	obj1->Dislpay();

	cout<<"Enter number to search\n";
	cin>>fno;
	bool fret = false;
	fret = obj1->SearchNDisplay(fno);

	if(fret == true)
	{
		cout<<"Element found\n";
	}
	else
	{
		cout<<"Element not found\n";
	}

	return 0;
}
