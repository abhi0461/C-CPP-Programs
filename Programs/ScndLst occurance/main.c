/* Problem Statement : Accept String from userand also accept character and return index of second last occurance 
					   of that character from that string.
	Input :  Marvellous infosystems  			
	            s
	Output :    18 				   
*/
#include<stdio.h>

int CheckScndLast(char *arr, char ch)
{
	int i =0,cValue = 0;
   // printf("ahjhds\n");
	while (arr[i] != '\0')
	{
		if (arr[i] == ch)
		{
			cValue = i; 
		}

		i++;
	}
	printf("%d\n",cValue);
	i = 0;int k = 0;
	while (i < cValue)
	{
		if (arr[i] == ch)
		{
			k = i;
			
		}

		i++;
	}
    printf("%d\n",k);
	return k;
}


int main ()
{
	char brr[30];
	char cChar = '\0';
	int iRet = 0;

	printf("Enter String from user:\n");
	scanf("%[^'\n']s",brr);

	printf("Enter Your char:\n");
	scanf(" %c",&cChar);

	 iRet = CheckScndLast(brr,cChar);
	printf("Second last Occurance is :%d",iRet);

	return 0;
}

