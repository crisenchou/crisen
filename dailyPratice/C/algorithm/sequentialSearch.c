#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct User{
    int id;
    char name[10];
    int status;
}User;


void printUser(User *user){
    //printf("the %dth user is %s,and the status is %d",user.id,user.name,user.status);
    printf("the %dth user is %s,and the status is %d",user->id,user->name,user->status);
}

//线性查找
int search(User user[], int n, int key){
    int i;
    for(i=0; i<n; i++){
        if(user[i].id == key)
            return i;
    }
    return -1;
}


int main(){
    
    User user[3] = {{1,"crisen1",0},{3,"crisen2",0},{7,"crisen3",1}};
    int addr;
    addr = search(user,3,3);
    if(addr == -1){
        printf("no data record\n");
        return 0;
    }
    
    printUser(&user[addr]);
    
    getche();
}
