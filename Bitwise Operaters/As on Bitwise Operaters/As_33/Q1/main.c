/*   problem Statement : 1.Write a program which accept one number from user and off 7th bit of that
number if it is on. Return modified number.
Input : 79
Output : 15 

*/

#include<stdio.h>

int CheckBit(int iNo)
{	
	int iMask = 0x00000001;
	int iResult = 0;

	while(iNo < 0)
	{
		iNo = -iNo;
	}
	iMask = iMask << 6;
	iResult = iNo ^ iMask;

	return iResult;
}



int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter the Number\n");
	scanf("%d",&iValue);

	iRet = CheckBit(iValue);

	printf("Modified number is %d\n",iRet);
	
	return 0;
}


