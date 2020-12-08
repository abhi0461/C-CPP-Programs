/*   problem Statement :  3. Write a program which accept one number and position from user and on
that bit. Return modified number.
Input : 10 3
Output : 14 
*/

#include<stdio.h>
typedef unsigned int UINT;

int CheckBit(UINT iNo,int iPos)
{	
	int iMask = 0x00000001;
	//int iMask1 = 0x00000000;
	int iResult = 0;
	int iResult1 = 0;

	while(iNo < 0)
	{
		iNo = -iNo;
	}
	if((iPos < 1)||(iPos > 32))
	{
		return -1;
	}
	
	iMask = iMask << (iPos -1);

	iResult1 = iNo & iMask;
	iResult = iNo ^ iMask;
	
	if(iResult1 == iMask)
	{
		printf("The Bit you are looking for contains 1 in it\n");
		return 0;
	}
	return iResult;	
}

int main()
{
	UINT iValue = 0;
	int iRet = 0;
	int iNo = 0;

	printf("Enter the Number\n");
	scanf("%d",&iValue);

	printf("Enter the Position of Bit Whose Condition you have to check\n");
	scanf("%d",&iNo);

	iRet = CheckBit(iValue,iNo);
	
	if(iRet == 0)
	{
		return 0;
	}
	printf("Modified value is %d\n",iRet);

	return 0;
}


