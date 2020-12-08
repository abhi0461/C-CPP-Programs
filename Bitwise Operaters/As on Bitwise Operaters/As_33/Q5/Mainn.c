/*   problem Statement :   Write a program which accept one number from user and on its first 4
bits. Return modified number.
Input : 73
Output : 79
*/

#include<stdio.h>
typedef unsigned int UINT;

UINT CheckBit(UINT iNo)
{	
	UINT iMask = 0x0000000F;
	//int iMask1 = 0x00000001;
	UINT iResult = 0;

	while(iNo < 0)
	{
		iNo = -iNo;
	}
	//iMask = iMask << 6;
	//iMask1 = iMask1 << 9;
	iResult = iNo | iMask;

	return iResult;
}



int main()
{
	UINT iValue = 0;
	UINT iRet = 0;

	printf("Enter the Number\n");
	scanf("%d",&iValue);

	iRet = CheckBit(iValue);

	printf("Modified number is %d\n",iRet);
	
	return 0;
}


