// Accept n numbers from array and print the sub array with largest sum among all sub array
/*
LD5 que.2 : Write a C program that will take an integer number n and n floating point numbers as input.
The n floating point numbers should be stored in an array named A. Then, find out the
contiguous sub-array within A which has the largest sum. Your output should display the
number n, the elements of the array A and the largest sum of contiguous sub-array in A.
Assume that the maximum value of n is 20.
*/

#include<stdio.h>

void SubArray(int arr[], int size)
{
    int maxSum = 0,largest = 0;
    int start = 0,end = 0;

    for(int i = 0; i < size; i++)
    {
        maxSum = 0;
        for(int j = i; j < size; j++)
        {
            maxSum = arr[j]+maxSum;
            if(maxSum > largest)
            {
                start = i;
                end = j;
                largest = maxSum;
            }
        }
    }
    printf("\nMaximum sum is : %d\n",largest);
    printf("Array with maximum sum is : \n");
    for(int i = start; i <= end; i++)
    {
        printf("%d\t",arr[i]);
    }
}


int main()
{
    int size = 0;
    printf("Enter the size of the array\n");
    scanf("%d",&size);
    int arr[size]; 
    printf("Now enter the elements in the array\n");
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Entered elements in the array are :\n");
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }

    SubArray(arr, size);

    return 0;
}