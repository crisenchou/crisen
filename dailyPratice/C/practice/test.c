#include <stdio.h>


int main(){
    int a[10],i;
    
    //printf("the position of i is %x\n", &i);
    
    for(i=0;i<=10;i++){
        printf("the position of a%d is %x\n",i, &a[i]);
        printf("the value of i is %d\n",i);
        a[i]=0;
    }
    printf("the value of i is %d",i);
    printf("test function");
    getche();
}