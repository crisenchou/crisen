#include <stdio.h>
typedef int bool;


/**
Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
*/
bool checkPossibility(int* nums, int numsSize);

int main(){
    int case1[3] = {4,2,1};//false
    int case2[5] = {3,2,1,4,5};//false
    int case3[8] = {1,5,4,6,7,10,8,9};//false
    int result1 = checkPossibility(case1, 3);
    int result2 = checkPossibility(case2, 5);
    int result3 = checkPossibility(case3, 8);
    printf("%d,%d,%d",result1,result2,result3);
    return 0;
}

bool checkPossibility(int* nums, int numsSize) {
    if(numsSize<=2) return 1;
    int i,modified=0;
    for(i=1;i<numsSize;i++){
        if(nums[i] < nums[i-1]){
            if(modified) return 0;
            modified++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i]){
                nums[i - 1] = nums[i]; 
            }else {
                nums[i] = nums[i - 1];
            }
        }
    }
    return 1;
}