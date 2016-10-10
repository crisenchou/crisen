#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])//整数类型主函数(整数类型统计参数个数,字符类型*数组指针至字符[])
{

    int c;
    /* process arguments */
    while (-1 != (c = getopt(argc, argv,
          "a"  /* access mask for unix socket */
          "b"  /* enable admin shutdown commannd */
          "c:"  /* TCP port number to listen on */
        ))) {
            switch(c){
                case 'a' :
                    printf("the param is a\n");
                    break;
                case 'b' :
                    printf("the param is b\n");
                    break;
                case 'c' :
                    //printf("option=c, optopt=%c, optarg=%s\n", optopt, optarg);
                    printf("the param c is %s\n", optarg);
                    break;
                case ':' :
                    printf("missing value");
                    break;
                case '?' :
                    printf("illegal params");
                    break;
                default : 
                    printf("illegal params");
                    return 1;
            }
        }
    return 0;//返回0;正常退出
}