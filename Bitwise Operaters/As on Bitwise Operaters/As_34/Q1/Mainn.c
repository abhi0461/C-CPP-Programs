/*   problem Statement : Write a program which accept one number and position from user and
check whether bit at that position is on or off. If bit is one return TURE
otherwise return FALSE.
Input : 10 2
Output : TRUE 
*/

#include<stdio.h>
typedef unsigned int UINT;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL CheckBit(UINT iNo,int iPos)
{	
	int iMask = 0x00000001;
	int iResult = 0;

	while(iNo < 0)
	{
		iNo = -iNo;
	}
	if((iPos < 1)||(iPos > 32))
	{
		return FALSE;
	}
	
	iMask = iMask << (iPos -1);
	iResult = iNo & iMask;

	if(iResult == iMask)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


int main()
{
	UINT iValue = 0;
	BOOL bRet = FALSE;
	int iNo = 0;

	printf("Enter the Number\n");
	scanf("%d",&iValue);

	printf("Enter the Position of Bit Whose Condition you have to check\n");
	scanf("%d",&iNo);

	bRet = CheckBit(iValue,iNo);

	if(bRet == TRUE)
	{
		printf("Given bit is On\n");
	}
	else
	{
		printf("Given bit is Off\n");
	}
	
	return 0;
}


