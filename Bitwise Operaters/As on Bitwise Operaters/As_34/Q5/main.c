/*   problem Statement :  Write a program which accept one number from user and toggle contents
of first and last nibble of the number. Return modified number. (Nibble is a group of four bits) 
*/

#include<stdio.h>
typedef unsigned int UINT;

int CheckBit(UINT iNo)
{	
	UINT iMask = 0xF000000F;
	int iResult = 0;
	
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	iResult = iNo ^ iMask;
	
	return iResult;	
}

int main()
{
	UINT iValue = 0;
	int iRet = 0;
	
	printf("Enter the Number\n");
	scanf("%d",&iValue);

	iRet = CheckBit(iValue);
	
	printf("Modified value is %d\n",iRet);

	return 0;
}


