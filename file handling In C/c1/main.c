/*                                              File handling in C                       

Accept two file name from user and write info of student into the file.

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
//#include<io.h>

// Function is Used to open and read whole data of the file.

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
    }


    close(fd);

}

void FileRead(char *name)
{
    int fd = 0;
    int ret,i = 0;
    int size = 0;
    struct student sobj;
    
    fd = open(name,O_RDONLY);
    
    if (fd == -1)
    {
        printf("Unable to open the file\n");
        return;
    }

    while((ret = read(fd,&sobj,sizeof(sobj))) != 0)
    {
        printf("roll no : %d\n",sobj.rollno);

        printf("name of students : %s\n",sobj.name);

        printf("marks : %d\n",sobj.marks);

        //write(fd,&sobj,sizeof(sobj));
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
