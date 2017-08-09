#include <stdio.h>



int searchInsert(int* nums, int numsSize, int target);

int main(){
    int arr[] = {1,3};
    int num=2;
    int size =2;
    int pos = searchInsert(arr, size, num);
    printf("%d",pos);
    getche();
}


int searchInsert(int* nums, int numsSize, int target){
    if(numsSize == 0){
        return 0;
    }
    if(numsSize == 1){
        return nums[0] >= target ? 0:1;
    }
    
    int low=0,high=numsSize-1,mid;
    while (low <= high) {
        mid = low + (high-low)/2;
        if (nums[mid] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return low;
}