#include <stdio.h>

int main(int argc,char* argv[])//��������������(��������ͳ�Ʋ�������,�ַ�����*����ָ�����ַ�[])
{
    printf("%d\n",argc);//��ʽ�����
    while(argc)//��(ͳ�Ʋ�������)
    printf("%s\n",argv[--argc]);//��ʽ�����
    return 0;//����0;�����˳�
}