/*
Write a program that reads two positive integers n1 and n2 from the user. It also reads the
operation to be performed on n1 and n2 as a character. The possible operations are ‘a’ for
addition, ‘m’ for multiplication, ‘g’ for finding the GCD and ‘l’ for finding the LCM of n1
and n2. Based on the operation entered, a switch case construct will be used to call the
appropriate function whose prototypes are shown below.
*/

#include<stdio.h>
int Addition(int no1, int no2)
{
    return no1+no2;
}
int Multiplication(int no1, int no2)
{
    return no1*no2;
}
int GCD(int no1, int no2)
{
    int gcd = 1;
    for(int i = 2; i <= no1; i++)
    {
        if((no1 % i == 0)&&(no2 % i == 0))
        {
            gcd = i;
        }
    }
    return gcd;
}
int LCM(int no1, int no2)
{
    if(no1 < no2)
    {
        int temp = 0;
        temp = no1;
        no1 = no2;
        no2 = temp;
    }
    for(int i = no1;; i++)
    {
        if((i % no1 == 0)&&(i % no2 == 0))
        {
            return i;
        }
    }    
}

int main()
{
    int no1 = 0,no2 = 0;
    int ret = 0;
    printf("Enter two numbers\n");
    scanf("%d %d",&no1,&no2);

    int choice = 0;
    printf("Select the operation you want do done\n");
    printf("1 : Addition\n2 : Multiplication\n3 : GCD\n4 : LCM\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            ret = Addition(no1,no2);
            printf("Addition of %d and %d is : %d\n",no1,no2,ret);
            break;
        case 2:
            ret = Multiplication(no1,no2);
            printf("Multiplication of %d and %d is : %d\n",no1,no2,ret);
            break;
        case 3:
            ret = GCD(no1,no2);
            printf("GCD of %d and %d is : %d\n",no1,no2,ret);
            break;
        case 4:
            ret = LCM(no1,no2);
            printf("LCM of %d and %d is : %d\n",no1,no2,ret);
            break;
        default :
            printf("Wrong input\n");
    }
    return 0;
}