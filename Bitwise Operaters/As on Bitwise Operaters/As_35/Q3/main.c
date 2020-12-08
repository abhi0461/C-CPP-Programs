/*   problem Statement :  Write a program which accept one number from user and check whether
9th or 12th bit is on or off.
Input : 257
Output : TRUE 
*/

#include<stdio.h>
typedef unsigned int UINT;
typedef int BOOL;
#define TRUE 1
#define FALSE 0;

BOOL CheckBit(UINT iNo1)
{		
	int iMask = 0x00000900;
	//int i = 0;
	int iResult = 0;
	while(iNo1 < 0)
	{
		iNo1 = -iNo1;
	}

	iResult = iNo1 & iMask;
	
	if((iResult==256)||(iResult==2048)||(iResult==2304))
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
	UINT iValue1 = 0;
	//UINT iValue2 = 0;
	BOOL bRet = FALSE;
	
	printf("Enter Number\n");
	scanf("%d",&iValue1);
	
	bRet = CheckBit(iValue1);
	
	if (bRet == TRUE)
	{
		printf("9th or 12th bit is on\n");
	}
	else
	{
		printf("9th or 12th bit is off\n");
	}
	return 0;
}


