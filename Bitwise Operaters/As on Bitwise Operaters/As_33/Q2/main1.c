/*
    Problem statement :
 1.Write a program which accept one number from user and off 7th bit of that
number if it is on. Return modified number. 
Input : 79
Output : 15 
 */
#include<stdio.h>
//typedef int BOOL;
//# define TRUE 1
//#define FALSE 0

void CheckBit(int iNo)
{
	int iRem = 0;
	int j = 0;
	int k = 1;
	int i = 0;

    if(iNo < 0)
    {
        iNo = -iNo;
    }
    while (iNo != 0)      
	{
		iRem  = iNo % 2;    
		iNo = iNo /2; 
		
		i++;
		if ((i == 7)&&(iRem == 1))
		{
			iRem = ~(iRem);
		}
        if ((i == 10)&&(iRem == 1))
		{
			iRem = ~(iRem);
		}
		printf("%d",iRem);
		
		if(iRem == 1)
		{
			j = k+j;   
		}
		k = k*2;
	}
	
	printf("\n%d\n",j);
	
	
}
int main()
{
    int iNo = 0;
    //BOOL bRet = FALSE;
    
    printf("Enter number\n");
    scanf("%d",&iNo);
    	
    CheckBit(iNo);
    
    return 0;
}
















/*
    Binary to Hexadecimal conversion
 
    Integer size = 4 bytes      ie 32 bits
 
    Hexadecimal cha base : 16
    Hexadecimal chi range is 0  to 15

Decomal             Binary              Hexadecimal
 0                      0000                        0
1                       0001                        1
2                       0010                        2
 3                      0011                        3
 4                      0100                        4
 5                      0101                        5
 6                      0110                        6
 7                      0111                        7
 8                      1000                        8
 9                      1001                        9
 10                    1010                        a
 11                    1011                        b
 12                    1100                        c
 13                    1101                        d
 14                    1110                        e
 15                    1111                        f
 
    For the 16 we requre 4 bits from binary.                (1111)
 
 
 Number re[resentation in Hexadecimal
 
 Number : 86
    
 
 
        0000    0000    0000    0000    0000    0000     0101   0110
        0           0           0           0       0           0           5       6
 
Hexadecimal : 0X00000056
 
 */

/*
    Mask designing :
 
 As we want to check the status of fourth bit we just create the mask whose fourth bit is on.
 
 Mask :  0000       0000            0000            0000        0000            0000       0000        1000
                0           0                   0                   0           0                   0           0              8
 
 Hexadecimal mask : 0X00000008
 
 0X01000000
 */