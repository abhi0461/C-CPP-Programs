/*
  Write a program which accept string from user and copy capital
characters of that string into another string.
Input : “Marvellous Multi OS”
Output : “MMOS”  
 */
	
#include<stdio.h>

char StringCopy(char str[],char qtr[])
{
     int i=0,k =0,l =0,j = 0;
     int iTemp = 0;
	while(str[i] != '\0')		
	{ 
		qtr[j] = str[i];
		i++;
		j++;
	}
	i =k;
	qtr[j] = '\0';
	printf("%s\n",qtr);
	 i = 0, j = 0;
	while(str[i] != '\0')		
	{
		
	//	str[i] = qtr[i];
		i++;
		//str++;
	}
	i--;
	while (j < i)
	{
		iTemp = str[j];
		 str[j] = str[i];
		 str[i] = iTemp;
		 j++;
		 i--;
	}
	printf("%s\n",str);
	return qtr;
	
	  // qtr[j]='\0';
	    
		//printf("Your string is %s %s\n",str,qtr);
}

int main()
{
	char arr[30];
	char drr[30];
 //   int iNo=0;	
	
	printf("Enter the first string\n");
    scanf("%[^'\n']s",arr);

	//printf("Enter the second string\n");
    //scanf(" %[^'\n']s",drr);
	
   // printf("Enter the number\n");
	//	scanf("%d",&iNo);
	
	StringCopy(arr,drr);
	if (arr == drr)
	{
		printf("pali");
	}
	else
	{
		printf("not pal");
	}
	
	
	//printf("%s",drr);
	return 0;
}