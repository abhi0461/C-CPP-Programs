/*   problem Statement : 2. Write a program which accept 2 strings from user and check whether
contents of two strings are equal or not. (Implement strcmp()
function).
Input : “Marvellous Infosystems”
 “Marvellous Infosystems”
Output : TRUE  
*/

#include<stdio.h>
typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL StrNCatX(char *arr, char *brr)
{
	if (arr ,brr == NULL)
	{
		return -1;
	}
		
	while((*arr != '\0')&&(*brr != '\0'))
	{	
		
		*arr == *brr;
		if(*arr != *brr)
		{
			break;
		}
		arr++;
		brr++;
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
	
	printf("Enter first string\n");
	scanf("%[^'\n']s",arr);

	printf("Enter second string\n");
	scanf(" %[^'\n']s",brr);

	BOOL bRet =	StrNCatX(arr,brr);

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