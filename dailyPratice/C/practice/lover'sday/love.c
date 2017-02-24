#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define true 1;
#define false 0;

typedef struct{
    char name[50];
    int age;
    int single;
    int sex;
}Boy,Girl,Person;
int meet(Boy boy, Girl girl);
int realize(Boy boy, Girl girl);
int fallInLove(Boy boy, Girl girl);
int takeCare(Boy boy, Girl girl);


int main(){
    Boy boy;
    Girl girl;
    Person you;
    Person other;
    
    printf("�������������:");
    scanf("%s",&you.name);
    
    printf("�������������:");
    scanf("%d",&you.age);
    
    if(you.age < 18){
        printf("δ�����˲�Ҫ��������!");
        getche();
        return 0;
    }
    
    if(you.age > 40){
        printf("���Ѿ���ô���ˣ����ǰѻ����ø������˰�!");
        getche();
        return 0;
    }
    
    
    
    printf("��ѡ������Ա�:\n");
    printf("0:Ů 1:�� 2:����\n");
    scanf("%d",&you.sex);
    
    if(you.sex !=1 && you.sex != 0){
        printf("�����˲�Լ,��������ת");
        getche();
        return 0;
    }
    
    printf("��ѡ��������״̬:\n");
    printf("0:Ű���� 1:����\n");
    scanf("%d",&you.single);

    printf("������Է�������:");
    scanf("%s",&other.name);
    
    printf("������Է�������:");
    scanf("%d",&other.age);
    
    printf("��ѡ��Է����Ա�\n");
    printf("0:Ů 1:�� 2:���� \n");
    scanf("%d",&other.sex);
    
    printf("��ѡ��Է������״̬:\n");
    printf("0:Ű���� 1:����\n");
    scanf("%d",&other.single);
    
    
    if(you.sex == 0){
        girl = you;
        boy = other;
    }else{
        boy = you;
        girl = other;
    }
    meet(boy,girl) && realize(boy,girl) && fallInLove(boy,girl) && takeCare(boy,girl);//���� ��֪ ���� �మ
    getche();
    return 0;
}



int meet(Boy boy, Girl girl){
    if(0 == girl.single || 0 == boy.single ){
        printf("��ȷ��ʱ�������������,�����Ե�޷�");
        return false;
    }else{
        printf("%s��%s ����\n",boy.name,girl.name);
        return true;
    }
    
}

int realize(Boy boy, Girl girl){
    if(3 >= abs(girl.age - boy.age)){
         printf("%s��%s ��֪\n",boy.name,girl.name);
         return true;
    }else{
        printf("��Ȼ���䲻�Ǿ���,����ǰ·̫����");
        return false;
    }
}

int fallInLove(Boy boy, Girl girl){
    if(boy.sex == girl.sex){
        printf("�Ա���ͬ�����氮��,̫�������,ף�����Ҹ�");
        return false;
    }else{
        printf("%s��%s �మ\n",boy.name,girl.name);
        return true;
    }
}

int takeCare(Boy boy, Girl girl){
    if(!strcmp(boy.name,"crisen")){
        printf("%s��%s ����\n",boy.name,girl.name);
        return true;
    }else{
        printf("�Բ���,%sû�����ǹ⻷,���������߲���һ��",boy.name);
        return false;
    }
}