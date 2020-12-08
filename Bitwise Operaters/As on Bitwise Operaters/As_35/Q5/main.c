/*   problem Statement : 4.  Write a program which accept one number from user and range of
positions from user. Toggle all bits from that range.
Input : 897 9 13
Toggle all bits from position 9 to 13 of input number ie 879.   
*/

#include<stdio.h>
typedef unsigned int UINT;
/*typedef int BOOL;
#define TRUE 1
#define FALSE 0*/

int CheckBit(UINT iNo1,int iStart,int iEnd)
{		
	int iMask1 = 0x00000001;
	//int iMask2 = 0x00000001;
	int i = 0;
	//int iResult = 0;
	while(iNo1 < 0)
	{
		iNo1 = -iNo1;
	}
	if(iStart > iEnd)
	{
		return -1;
	}
	iMask1 = iMask1 << (iStart -1);
	while(i != ((iEnd - iStart)+1))
	{
		iNo1 = iNo1 ^ iMask1;
		iMask1 = iMask1 << 1;	
		i++;
		//printf("%d\t",iNo1);
	}	
	//printf("\n%d\t",iNo1);
	return iNo1;
}

int main()
{
	UINT iValue1 = 0;
	int iPos1,iPos2 = 0;
	//int bRet = FALSE;
	
	printf("Enter Number\n");
	scanf("%d",&iValue1);

	printf("Enter starting position\n");
	scanf("%d",&iPos1);

	printf("Enter last position\n");
	scanf("%d",&iPos2);
	
	int iRet = CheckBit(iValue1,iPos1,iPos2);
	
	printf("Number after toggling the bits in given range is %d\n",iRet);
	
	return 0;
}


