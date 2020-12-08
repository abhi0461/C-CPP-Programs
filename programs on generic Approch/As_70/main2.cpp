/*
   assignmnt no 70 
*/
#include<iostream>
using namespace std;

class Array
{
public:
	int size;
	int *arr;

public:
	Array(int no = 5)
	{
		cout<<"Inside default constructor\n";
		this->size = no;
		this->arr = new arr[size];
	}
	Array(Array &ref)
	{
		 cout<<"Inside copy constructor\n";

		 this->size = ref.size;
		 this->arr = new int[this->size];

		 for(int i = 0; i<size; i++)
		 {
		 	this->arr[i] = ref.arr[i];
	 	 }
	}
	~Array()
	{
		cout<<"Inside destructor\n";
		delete []arr;
	}

	void Accept()
	{
		cout<<"Enter the elements in the array\n";
		for(int i = 0; i < this->size; i++)
		{
			cin>>arr[i];
		}
	}
	void Display()
	{
		cout<<"Entered elements are : ";
		for(int i = 0; i < this->size; i++)
		{
			cout<<arr[i]<<"\t";
		}
		cout<<"\n";
	}

	int Frequency(int value)
	{
		int icnt = 0;
		for(int i = 0; i < size; i++)
		{
			if(arr[i] == value)
			{
				icnt++;
			}
		}
		if(icnt != 0)
		{
			return icnt;
		}
		else
		{
			cout<<"No matching element!!!";
		}
	}
	int SearchFirst(int value)
	{
		int test = 0;
		for(int i = 0; i < size; i++)
		{
			if(arr[i] == value)
			{
				test++;
				break;
			}
		}
		if(test != 0)
		{
			return i+1;
		}
		else
		{
			cout<<"No matching element!!!\n";
		}
	}
	int SearchLast(int value)
	{
		int icnt = 0;
		for(int i = 0; i < size; i++)
		{
			if(arr[i] == value)
			{
				icnt = i+1;
			}
		}
		if(icnt != 0)
		{
			return icnt;
		}
		else
		{
			cout<<"No matching element!!!\n";
		}
	}
	int EvenCount()
	{
		int icnt = 0;
		for(int i = 0; i < size; i++)
		{
			if(arr[i]%2 == 0)
			{
				icnt++;
			}
		}
		if(icnt != 0)
		{
			return icnt;
		}
		else
		{
			cout<<"No even element!!!\n";
		}
	}
	int OddCount()
	{
		int icnt = 0;
		for(int i = 0; i < size; i++)
		{
			if(arr[i]%2 != 0)
			{
				icnt++;
			}
		}
		if(icnt != 0)
		{
			return icnt;
		}
		else
		{
			cout<<"No odd element!!!\n";
		}
	}
	int SumAll()
	{
		int sum = 0;
		for(int i = 0; i < size; i++)
		{
			sum = arr[i] + sum;
		}
		return sum;
	}
	
};

int main()
{
	int size ,freq, iret ,fst, last= 0;
	cout<<"Enter the size of array\n";
	cin>>size;
	Array obj(size);

	obj.Accept();
	obj.Display();
	Array sobj(&ref obj);
	cout<<"\nEnter element for frequency count\n";
	cin>>freq;
	iret = sobj.Frequency(freq);
	cout<<"\nFrequency of given element is : "<<iret;

	cout<<"\nEnter element for search first occurance \n";
	cin>>fst;
	iret = sobj.SearchFirst(fst);
	cout<<"\nFirst occurance of given element is : "<<iret;

	cout<<"\nEnter element for search last occurance \n";
	cin>>last;
	iret = sobj.SearchLast(last);
	cout<<"\nLast occurance of given element is : "<<iret;

	iret = sobj.EvenCount();
	cout<<"\nEven count is : "<<iret;

	iret = sobj.OddCount();
	cout<<"\nOdd count is : "<<iret;

	return 0;
}