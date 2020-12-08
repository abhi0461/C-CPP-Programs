/* problem statement : Write a program which checks wheter 7th , 15th , 21th , 28th bit is on or off

*/
#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL CheckBit(int iNo)
{
	int iMask = 0X08104040; 
	int iResult = 0;
	if (iNo < 0)
	{
		iNo = -iNo;
	}

	iResult = iMask & iNo;

	if (iResult == iMask)
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
	int iValue = 0;
	BOOL bRet = FALSE;

	printf("Enter the Number\n");
	scanf("%d",&iValue);

	bRet = CheckBit(iValue);

	if(bRet == TRUE)
	{
		printf("Bits are on\n");
	}
	else
	{
		printf("Bits are off\n");
	}
	
	return 0;
}