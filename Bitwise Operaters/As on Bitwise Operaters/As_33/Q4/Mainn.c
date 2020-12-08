/*   problem Statement :  Write a program which accept one number from user and toggle 7th and
10th bit of that number. Return modified number.
Input : 137
Output : 713 
*/

#include<stdio.h>

int CheckBit(int iNo)
{	
	int iMask = 0x00000009;
	//int iMask1 = 0x00000001;
	int iResult = 0;

	while(iNo < 0)
	{
		iNo = -iNo;
	}
	iMask = iMask << 6;
	//iMask1 = iMask1 << 9;
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


