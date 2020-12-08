/*
    Problem statement :
 Accept number from user and check whether fourth bit is on or off.
 
 Input :   43                     Binary :    1   0   1   0   1   1       (1+2+8+32)
 Output : TRUE
 
 Input :   35                     Binary :    1   0   0   0   1   1       (1+2+32)
 Output : FALSE
 
 */
#include<stdio.h>
typedef int BOOL;
# define TRUE 1
#define FALSE 0

BOOL CheckBit(int iNo)
{
    int iMask1 = 0X00000001;
    int iMask2 = 0X80000000;
    int iResult1 = 0;
	int iResult2 = 0;
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    iResult1 = iNo & iMask1;
    iResult2 = iNo & iMask2;
    if((iResult1 == iMask1)&&(iResult2 == iMask2))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
int main()
{
    int iNo = 0;
    BOOL bRet = FALSE;
    
    printf("Enter number\n");
    scanf("%d",&iNo);
    	
    bRet = CheckBit(iNo);
    if(bRet == TRUE)
    {
        printf("Fifteenth bit is on\n");
    }
    else
    {
        printf("Fifteenth bit is Off\n");
    }
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