#include <stdio.h>

void removeElement(int *arr, int* length, int val);
int findElement(int *arr, int* length, int val);


void printArr(int *arr, int size){
    int i;
    for(i=0;i<size;i++){
        printf("%d\n",arr[i]);
    }
    
}

int main(){
    int length=6;
    int arr[6] = {1,2,3,4,5,3};
    int l = findElement(arr,&length,3);
    printf("%d\n",l);
    printf("the length is %d\n",length);
    printArr(arr,length);
    getche();
}

int findElement(int *arr, int* length, int val){
    int i,len;
    for(i=0;i<*length;i++){
        if(arr[i] == val){
            removeElement(arr, length, i);
        }
    }
    len= *length;
    return len;
}

void removeElement(int *dat, int *len, int pos){
    int i;
    if (pos < 0 || pos >= *len)
        return;
    
    (*len)--;
    for (i = pos; i < *len; i++)
        dat[i] = dat[i+1];
}
