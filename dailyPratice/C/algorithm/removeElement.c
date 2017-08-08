#include <stdio.h>


int removeElement(int *arr, int length, int val);


void printArr(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
    
}

int main(){
    int length=11;
    int arr[11] = {2,1,3,0,1,1,0,3,3,1,3};
    int len = removeElement(arr,length,3);
    printf("%d\n",len);
    printArr(arr,len);
    getche();
}

int removeElement(int* nums, int numsSize, int val) {
    int i,j,len;
    for(i=numsSize-1;i>=0;i--){
        if(nums[i] == val){
            numsSize--;
            for (j = i; j < numsSize; j++){
                nums[j] = nums[j+1];
            }
        }
    }
    return numsSize;
}