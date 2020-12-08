/*                                              File handling in C                                           */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main()
{
    char name[20] = {'\0'};
    char arr[50] = {'\0'};
    int fd = 0;   
    int ret,length = 0;
                                         // file discripter

    printf("Enter file name\n");
    scanf("%s",name);

    fd = open(name,O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open the file");
    }
    else
    {
        printf("file successfully opened with fd : %d\n",fd);
    }

   
    ret = read(fd,arr,10);

    if(ret == -1)
    {
        printf("Unable to read in the file\n");
    }
    else
    {
        printf("Data successfully read\n");
    }
    printf("Data from file is : %s",arr);
    
    close(fd);

    return 0;
}
