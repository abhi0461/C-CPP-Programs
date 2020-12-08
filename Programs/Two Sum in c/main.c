#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int returnSize)
{
    int i, j, test = 0;
    int* arr;
    arr= (int*)malloc(sizeof(int)*returnSize);
    for(i = 0; i < numsSize; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if(nums[i]+nums[j] == target)
            {
                test = 1;
                arr[0] = i;
                arr[1] = j;
                break;
            }
        }
    }
    if(test != 0){
    return arr;
    }
    else{
        printf("condition not completed\n");
    }
}

int main()
{
    int* arr;
    int* brr;
    int size, i, sum = 0;
    printf("Enter the size of array\n");
    scanf("%d",&size);
    arr = (int*)malloc(sizeof(int)*size);
    brr = (int*)malloc(sizeof(int)*2);
    printf("Enter the elements in the array\n");
    
    for(i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the sum you want\n");
    scanf("%d",&sum);
    brr = twoSum(arr,size,sum,2);

    printf("Index are : %d , %d\n", brr[0], brr[1]);
    
    
}