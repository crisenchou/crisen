#include <stdio.h>

/*
ptintf 格式化输出
%d 十进制有符号整数
%ld 输出长整型数据。
%u 十进制无符号整数
%f 浮点数
%lf  双精度浮点数
%s 字符串
%c 单个字符
%p 指针的值
%e 指数形式的浮点数
%x, %X 无符号以十六进制表示的整数
%0 无符号以八进制表示的整数
%g 自动选择合适的表示法 
*/

unsigned int fact(int n){
    if(n == 1)
        return 1; 
    return n*fact(n-1);
}

int main(){
    int n;
    printf("please enter a number:");
    scanf("%d",&n);
    printf("the fact of %d is %g",n,fact(n));
}