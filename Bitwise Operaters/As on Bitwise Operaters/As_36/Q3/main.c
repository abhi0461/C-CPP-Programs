/*   problem Statement : 3. Write a program which 2 strings from user and check whether first
N contents of two strings are equal or not. (Implement strcmp()
function).
Note : If third parameter is greater than the size of second string then
concat whole string after first string.
Input : “Marvellous Infosystems”
 “Marvellous Logic Building”
 10
Output : TRUE 
*/

#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL StrNCatX(char *arr, char *brr,int iNo)
{
	if (arr ,brr == NULL)
	{
		return -1;
	}
		
	while((*arr != '\0')&&(*brr != '\0')&&(iNo > 1))
	{	
		
		if(*arr == *brr)
		{
		arr++;
		brr++;
		iNo--;
		}
		if(*arr != *brr)
		{
			break;
		}
	}
	if(*arr != *brr)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

int main()
{
	char arr[30] = {'\0'};
	char brr[30] = {'\0'};
	int iValue = 0;
	printf("Enter first string\n");
	scanf("%[^'\n']s",arr);

	printf("Enter second string\n");
	scanf(" %[^'\n']s",brr);

	printf("Enter Value of N\n");
	scanf("%d",&iValue);

	BOOL bRet =	StrNCatX(arr,brr,iValue);

	if(bRet == TRUE)
	{
		printf("Both strings are same\n");
	}
	else
	{
		printf("Strings are different\n");
	}
	
	return 0;
}