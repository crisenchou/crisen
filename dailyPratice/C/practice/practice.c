#include "stdio.h"

int feibo();

int main(){
    int n=10;
    for(n=3;n<=10;n++){
        printf("the %dth feibo number is %d\n",n,feibo(n));
    }
}


//��Ǯ��ټ�
hundredChicken(){
    int cock,hen,chicken;
    for(cock=0;cock<=20;cock++){
        for(hen=0;hen<=33;hen++){
            chicken = 100-cock-hen;
            if(cock*5+hen*3+chicken/3.0==100)
                printf("cock %d  hen%d chicken%d \n",cock,hen,chicken); 
        }
    }
    return;
}

//12345 ����ϳɶ��ٲ�ͬ����λ��
combineNum(){
    int a,b,c,i=0;
    for(a=1;a<=5;a++)
        for(b=1;b<=5;b++)
            for(c=1;c<=5;c++)
                if(a!=b&&b!=c&&a!=c){
                    i++;
                    printf("the number is %d%d%d\n",a,b,c);
                }
    printf("the amout is %d",i);
}

//4λ������ȫƽ���� ����ǰ��λ��ͬ  ����λ��ͬ  �ұ�������������
squarenum(){
    int a,b,i,temp,num;
    for(a=1;a<=9;a++)
        for(b=1;b<=9;b++)
            if(a!=b){
                num=a*1000+a*100+b*10+b;
                for(temp=31;temp<=99;temp++)
                    if(num==temp*temp)
                        printf("the number is %d%d%d%d",a,a,b,b);
            }
}



//feibo 쳲���������
int feibo(int n){
    if(n==1||n==2){
        return 1;
    }else{
        return feibo(n-1)+feibo(n-2);
    }
}
