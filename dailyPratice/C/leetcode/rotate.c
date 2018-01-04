#include <stdio.h>


/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

void printArr(int* nums, int numsSize);
void rotate(int* nums, int numsSize, int k);
void reverse(int* nums, int start, int end);

int main(){
    int testCase[2] = {1,2};
    rotate(testCase,2,3);
    printArr(testCase,2);
}

void printArr(int* nums, int numsSize){
    int i;
    for(i=0;i<numsSize;i++)
        printf("%d ",nums[i]);
    printf("\n");
}

void rotate(int* nums, int numsSize, int k) {
    if(k>=numsSize){
        return ;
    }
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
    reverse(nums,0,numsSize-1);
}
void reverse(int* nums, int start, int end){
    int temp;
    while(start<end){
        temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}