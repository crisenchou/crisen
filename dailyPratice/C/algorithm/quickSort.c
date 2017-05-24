#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 10


//快速排序算法
void quickSort(int *a, int low, int hign){
    if(low>=hign){
        return ;
    }
    int i = low;
    int j = hign;
    int key = a[i];
    while(i<j){
        while(i < j && key <= a[j])
        {
            j--;
        }
         
        a[i] = a[j];
        while(i < j && key >= a[i])
        {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    quickSort(a, low, i-1);
    quickSort(a, i+1, hign);
}


//随机数自动给数组赋值
int mtrand(int *a, int max){
    int i;
    srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
    for(i=0;i<L;i++){
        a[i] = rand() % max; 
    }
}

//打印数组
void printArray(int *a, int length){
    int i;
    for(i=0;i<length;i++){
        printf("%d,",a[i]);
    }
    printf("\n");
}

int main(){
    int i,j,a[L];
    printf("generate the default data:\n");
    mtrand(a, 30);
    printf("the default data is bellow:\n");
    printArray(a, L);
    quickSort(a, 0, L-1);
    printf("the sort data is bellow:\n");
    printArray(a, L);
    //getche();
}