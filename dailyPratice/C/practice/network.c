#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

int main(int argc, int *args[])
{
    //网络字节序与主机字节序的转换 也就是大小端转换
    // htonl -- host to network long
    // htons -- host to network short
    // ntohl -- network to host long
    // ntohs -- network to host short
    printf("host to network short is %d\n",htons(1));//256=0x100  
    printf("host to network long  is %d\n",htonl(1));//16777216=   0x1000000
    printf("network to host short is %d\n",ntohs(1));
    printf("network to host long %d\n",ntohl(1));
}