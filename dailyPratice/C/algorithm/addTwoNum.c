#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target);
void printArr(int* nums, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\n",nums[i]);
    }
}

int main(){
    int nums[4] = {1,3,4,8};
    int target = 7;
    int *p;
    //int res[2];
    //printf("%d",sizeof(int));
    p = twoSum(nums,4,target);
    printArr(p,2);
    //printf("%d\n",*p);
    //printf("%d\n",*(p+1));
    //free(p);
    getche();
}


int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *p;
    p=(int *)malloc(sizeof(int)*2);  
    for(i=0;i<numsSize-1;i++)
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j] == target){
                *p=i;
                *(p+1)=j;
                return p;
            }
        }
    return NULL; 
}