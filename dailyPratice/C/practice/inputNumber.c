#include <stdio.h>

//从终端输入10个数  输出最大的数

int main()
{
    int i,maxVal=-1000,a;
    for(i=1;i<=10;i++){
        scanf("%d",&a);
        if(a>maxVal){
            maxVal = a;
        }
    }
    
    printf("the max number is %d",maxVal);
    getche();
}