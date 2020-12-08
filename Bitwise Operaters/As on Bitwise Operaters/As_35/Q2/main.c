/*   problem Statement : 2. Write a program which accept two numbers from user and display position
of common ON bits from that two numbers.
Input : 10 15 (1010 1111)
Output : 2 4 
*/

#include<stdio.h>
typedef unsigned int UINT;

void CheckBit(UINT iNo1,UINT iNo2)
{		
	int iCnt = 0;
	int i = 0;
	int iResult = 0;
	while(iNo1 < 0)
	{
		iNo1 = -iNo1;
	}
	while(iNo2 < 0)
	{
		iNo2 = -iNo2;
	}

	iResult = iNo1 & iNo2;
	
	while(iResult != 0)
	{		
		iCnt++;
		i = iResult & 1;
		
		if(i == 1)
		{
			printf("%d\t",iCnt);
		}

		iResult = iResult >> 1;

	}	
}

int main()
{
	UINT iValue1 = 0;
	UINT iValue2 = 0;
	//int iRet = 0;
	
	printf("Enter first Number\n");
	scanf("%d",&iValue1);
	
	printf("Enter second Number\n");
	scanf("%d",&iValue2);

	CheckBit(iValue1,iValue2);
	
	//printf("The number of Ones are %d\n",iRet);

	return 0;
}


