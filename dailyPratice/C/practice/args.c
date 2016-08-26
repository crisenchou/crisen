#include <stdio.h>

int main(int argc,char* argv[])//整数类型主函数(整数类型统计参数个数,字符类型*数组指针至字符[])
{
    printf("%d\n",argc);//格式化输出
    while(argc)//当(统计参数个数)
    printf("%s\n",argv[--argc]);//格式化输出
    return 0;//返回0;正常退出
}