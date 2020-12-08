#include<stdio.h>
#include<stdlib.h>

int FormIP(int no1, int no2, int no3, int no4)
{
    int ret = 0;
    no1 = no1 & 0x000000ff;
    no2 = no2 & 0x000000ff;
    no3 = no3 & 0x000000ff;
    no4 = no4 & 0x000000ff;

    no1 = no1<<24;
    no2 = no2<<16;
    no3 = no3<<8;

    ret = no1 | no2 | no3| no4;

    return ret;
}

void SpiltIP(int no)
{
    int a,b,c,d;
    a = no & 0xff000000;
    b = no & 0x00ff0000;
    c = no & 0x0000ff00;
    d = no & 0x000000ff;

    a = a >> 24;
    b = b >> 16;
    c = c >> 8;

    printf("First number : %d\n",a);    
    printf("Second number : %d\n",b);
    printf("Third number : %d\n",c);
    printf("Fourth number : %d\n",d);
}

int main()
{
    int a,b,c,d;

    printf("Enter IP address : \n");

    printf("First value : ");
    scanf("%d",&a);

    printf("Second value : ");
    scanf("%d",&b);

    printf("Third value : ");
    scanf("%d",&c);

    printf("Fourth value : ");
    scanf("%d",&d);

    int iret = FormIP(a,b,c,d);
    printf("IP address in one form is : %d\n",iret);

    SpiltIP(iret);

    return 0;
}