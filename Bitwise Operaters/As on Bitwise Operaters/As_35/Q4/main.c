/*   problem Statement : 4. Write a program which accept one number , two positions from user and
check whether bit at first or bit at second position is ON or OFF.
Input : 10 3 7
Output : TRUE  
*/

#include<stdio.h>
typedef unsigned int UINT;
/*typedef int BOOL;
#define TRUE 1
#define FALSE 0*/

void CheckBit(UINT iNo1,int iPos1,int iPos2)
{		
	int iMask1 = 0x00000001;
	int iMask2 = 0x00000001;
	//int i = 0;
	int iResult1,iResult2 = 0;
	while(iNo1 < 0)
	{
		iNo1 = -iNo1;
	}
	iMask1 = iMask1 << (iPos1 -1);
	iMask2 = iMask2 << (iPos2 -1);

	iResult1 = iNo1 & iMask1;
	iResult2 = iNo1 & iMask2;
	
	if((iResult1 == iMask1)||(iResult2 == iMask2))
	{
		printf("Bits are on\n");
	}
	if((iResult1 == 0)||(iResult2 == 0))
	{
		printf("Bits are off\n");
	}
	
}

int main()
{
	UINT iValue1 = 0;
	int iPos1,iPos2 = 0;
	//int bRet = FALSE;
	
	printf("Enter Number\n");
	scanf("%d",&iValue1);

	printf("Enter first position\n");
	scanf("%d",&iPos1);

	printf("Enter second position\n");
	scanf("%d",&iPos2);
	
	CheckBit(iValue1,iPos1,iPos2);
	
	/*if (bRet == 1)
	{
		printf("Bits are on\n");
	}
	if (bRet == 2)
	{
		printf("Bits are off\n");
	}*/
	
	return 0;
}


