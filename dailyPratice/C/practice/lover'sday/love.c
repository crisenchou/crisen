#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
    
    printf("请输入你的姓名:");
    scanf("%s",&you.name);
    
    printf("请输入你的年龄:");
    scanf("%d",&you.age);
    
    printf("请选择你的性别:\n");
    printf("0:女 1:男 2:其他\n");
    scanf("%d",&you.sex);
    
    if(you.sex !=1 && you.sex != 0){
        printf("外星人不约,出门请左转");
        getche();
        return 0;
    }
    
    printf("请选择你的情感状态:\n");
    printf("0:虐狗中 1:单身\n");
    scanf("%d",&you.single);

    printf("请输入对方的姓名:");
    scanf("%s",&other.name);
    
    printf("请输入对方的年龄:");
    scanf("%d",&other.age);
    
    printf("请选择对方的性别\n");
    printf("0:女 1:男 2:其他 \n");
    scanf("%d",&other.sex);
    
    printf("请选择对方的情感状态:\n");
    printf("0:虐狗中 1:单身\n");
    scanf("%d",&other.single);
    
    
    if(you.sex == 0){
        girl = you;
        boy = other;
    }else{
        boy = you;
        girl = other;
    }
    meet(boy,girl) && realize(boy,girl) && fallInLove(boy,girl) && takeCare(boy,girl);//相遇 相知 相守 相爱
    getche();
    return 0;
}



int meet(Boy boy, Girl girl){
    if(0 == girl.single || 0 == boy.single ){
        printf("正确的时间遇到错误的人,这叫有缘无份");
        return 0;
    }else{
        printf("%s与%s 相遇\n",boy.name,girl.name);
        return 1;
    }
    
}

int realize(Boy boy, Girl girl){
    if(3 >= abs(girl.age - boy.age)){
         printf("%s与%s 相知\n",boy.name,girl.name);
         return 1;
    }else{
        printf("虽然年龄不是距离,但是前路太难了");
        return 0;
    }
}

int fallInLove(Boy boy, Girl girl){
    if(boy.sex == girl.sex){
        printf("性别相同才是真爱啊,太佩服你了,祝你们幸福");
    }else{
        printf("%s与%s 相爱\n",boy.name,girl.name);
    }
}

int takeCare(Boy boy, Girl girl){
    if(!strcmp(boy.name,"crisen")){
        printf("%s与%s 相守\n",boy.name,girl.name);
    }else{
        printf("对不起，%s没有主角光环，所以你们走不到一起");
    }
}