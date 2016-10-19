#include <stdio.h>
#include <stdlib.h>

//获取三个数中的最大值
int max(int a, int b)
{
    a<b && (a=b);
    return a;
}

int main(){
    int i=1,j=2,k=3;
    printf("the max is %d", max(k,max(i,j)));
}