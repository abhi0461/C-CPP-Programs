/* Problem Statement : Accept String from user and also accept character and if that Character is present in the 
						string then drop that char nd continue the strig.
	Input :  Marvellous infosystems  			
	            v
	Output : Marellous infosystems 				   
*/
#include<stdio.h>

void CheckChar(char *arr, char ch)
{
	int i =0,cValue = 0;
    //printf("ahjhds %d\n",cValue);
	while (arr[i] != '\0')
	{
		if (arr[i] != ch)
		{
			printf("%s",arr[i]);

		} 
	/*	else if( arr[i] == ch)
		{
			i--;
		}

		i++; */
	}
	//printf("%d\n",cValue);
	
}

int main()
{
	char brr[30];
	char cChar = '\0';
	//int iRet = 0;

	printf("Enter String from user:\n");
	scanf("%[^'\n']s",brr);

	printf("Enter Your char:\n");
	scanf(" %c",cChar);

	CheckChar(brr,cChar);
	//printf("Second last Occurance is :%d",iRet);

	return 0;
}

