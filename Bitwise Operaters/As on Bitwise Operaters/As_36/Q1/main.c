/*   problem Statement : 1. Write a program which accepts 2 strings from user and concat N
characters of second string after first string.Value of N should be
accepted from user. (Implement strncat() function).
Note : If third parameter is greater than the size of second string then
concat whole string after first string.
Input : “Marvellous Infosystems”
 “Logic Building”
 5
Output : “Marvellous Infosystems Logic”    
*/

#include<stdio.h>

void StrNCatX(char *arr, char *brr, int iNo)
{
	//int i = 0;
	
	if (arr ,brr == NULL)
	{
		return;
	}
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	while(*arr != '\0')
	{
		arr++;
	}
	
	
	while((iNo != 0)&&(*brr != '\0'))
	{	
		
		*arr = *brr;
		arr++;
		brr++;
		iNo--;
	}
	*arr = '\0';
	
}

int main()
{
	char arr[30];
	char brr[30];
	int iValue = 0;

	printf("Enter first string\n");
	scanf("%[^'\n']s",arr);

	printf("Enter second string\n");
	scanf(" %[^'\n']s",brr);

	printf("Enter Value of N\n");
	scanf("%d",&iValue);

	StrNCatX(arr,brr,iValue);

	printf("String after concatination is %s",arr);
	return 0;
}