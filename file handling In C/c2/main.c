/*                                              File handling in C                       

Problem statement :
5. Write a program which accept file name which contains information of
student and display the studnt names having even number of marks. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

struct student
{
    int rollno;
    char name[20];
    int marks;
};


void FileWrite(char *name)
{
    int fd = 0;
    int ret,i = 0;
    int size = 0;
    struct student sobj;
    
    fd = open(name,O_WRONLY);
    
    if (fd == -1)
    {
        printf("Unable to open the file\n");
        return;
    }

    printf("Enter number of students\n");
    scanf("%d",&size);

    for(i = 1; i <= size ; i++)
    {
        printf("Enter roll no\n");
        scanf("%d",&sobj.rollno);

        printf("Enter name of students\n");
        scanf(" %[^'\n']s",&sobj.name);

        printf("Enter marks\n");
        scanf("%d",&sobj.marks);

        write(fd,&sobj,sizeof(sobj));
        printf("\n");
    }


    close(fd);

}

void FileRead(char *name)
{
    int fd = 0;
    int ret,i = 0;
    int size = 0;
    struct student sobj;
    int Add = 0;
    char stdname[20];
    
    fd = open(name,O_RDONLY);
    
    if (fd == -1)
    {
        printf("Unable to open the file\n");
        return;
    }

    printf("\n");

    while((ret = read(fd,&sobj,sizeof(sobj))) != 0)
    {
         if((i = (sobj.marks % 2)) == 0)
         {
            printf("Students with even marks are :\n");
        
            printf("Roll number : %d\n",sobj.rollno);
            printf("Name : %d\n",sobj.name);
            printf("Marks : %d\n",sobj.marks);
         }
         
    }

    close(fd);
}

int main()
{
    char name1[50] = {'\0'};

    printf("Enter file name\n");
    scanf("%s",name1);

    FileWrite(name1);

    FileRead(name1);

    return 0;
}
