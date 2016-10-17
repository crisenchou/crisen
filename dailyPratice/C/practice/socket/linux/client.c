#include <stdlib.h>   
#include <sys/types.h>   
#include <stdio.h>   
#include <sys/socket.h>   
#include <linux/in.h>   
#include <string.h>   
  
int main()  
{  
    int cfd; /* �ļ������� */  
    int recbytes;  
    int sin_size;  
    char buffer[1024]={0};    /* ���ܻ����� */  
    struct sockaddr_in s_add,c_add; /* �洢����˺ͱ��˵�ip���˿ڵ���Ϣ�ṹ�� */  
    unsigned short portnum=0x8888;  /* �����ʹ�õ�ͨ�Ŷ˿ڣ����Ը��ģ���ͷ������ͬ */  
      
    printf("Hello,welcome to client !\r\n");  
    /* ����socket ʹ����������TCP������ */  
    cfd = socket(AF_INET, SOCK_STREAM, 0);  
    if(-1 == cfd)  
    {
        printf("socket fail ! \r\n");  
        return -1;  
    }
    printf("socket ok !\r\n");  
    /* ����������˵�ip�Ͷ˿���Ϣ������ṹ����Բ����� */  
    bzero(&s_add,sizeof(struct sockaddr_in));  
    s_add.sin_family=AF_INET;  
    s_add.sin_addr.s_addr= inet_addr("192.168.1.104"); /* ipת��Ϊ4�ֽ����Σ�ʹ��ʱ��Ҫ���ݷ����ip���и��� */  
    s_add.sin_port=htons(portnum); /* ����htons�ǽ�short�������ֽ�����������ת��Ϊ�����ͣ���ʵ���� 
        ��2�ֽ����ݵ�ǰ�������ֽڵ������Ͷ�Ӧ��ntohsЧ����ʵ����ͬ��ֻ�������ֲ�ͬ��htonl��ntohl�� 
        ������4�ֽ����Ρ���0x12345678��Ϊ0x78563412�����ֲ�ͬ������������ͬ��һ�����������Ϊ��ˣ� 
        PPC��cpuΪ��ˣ�x86��cpuΪС�ˣ�arm�Ŀ������ô�С�ˣ���Ҫ��֤����ʱ�ֽ�����ȷ�� 
     */  
      
    printf("s_addr = %#x ,port : %#x\r\n",s_add.sin_addr.s_addr,s_add.sin_port); /* �����ӡ������С�� 
        ������ƽʱ���������෴�ġ� */  
      
    /* �ͻ������ӷ���������������Ϊsocket�ļ�����������ַ��Ϣ����ַ�ṹ��С */  
    if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))  
    {  
        printf("connect fail !\r\n");  
        return -1;  
    }  
    printf("connect ok !\r\n");  
    /*���ӳɹ�,�ӷ���˽����ַ�*/  
    if(-1 == (recbytes = read(cfd,buffer,1024)))  
    {  
        printf("read data fail !\r\n");  
        return -1;  
    }  
    printf("read ok\r\nREC:\r\n");  
      
    buffer[recbytes]='\0';  
    printf("%s\r\n",buffer);  
      
    getchar(); /* �˾�Ϊʹ������ͣ�ڴ˴�������ʹ��netstat�鿴��ǰ������ */  
    close(cfd); /* �ر����ӣ�����ͨ����� */  
    return 0;  
}