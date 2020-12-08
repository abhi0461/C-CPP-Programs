/*   problem Statement : Write a program which accept one number from user and count number of
ON (1) bits in it without using % and / operator.
Input : 11
Output : 3 
*/

#include<stdio.h>
typedef unsigned int UINT;

int CheckBit(UINT iNo)
{	
	
	int iCnt = 0;
	int i = 0;
	while(iNo < 0)
	{
		iNo = -iNo;
	}
	
	while(iNo != 0)
	{
		i = iNo & 1;
		
		if(i == 1)
		{
			iCnt++;
		}

		iNo = iNo >> 1;

	}
	return iCnt;	
}

int main()
{
	UINT iValue = 0;
	int iRet = 0;
	
	printf("Enter the Number\n");
	scanf("%d",&iValue);

	iRet = CheckBit(iValue);
	
	printf("The number of Ones are %d\n",iRet);

	return 0;
}


