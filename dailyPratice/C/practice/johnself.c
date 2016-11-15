#include <stdio.h>


struct node{
    int flag;
    int next;
}array[31];

int main(){
    int i,j,k;
    
    printf("s:0,b:1");
    
    for(i=1;i<=30;i++){
        array[i].flag=1;
        array[i].next=i+1;
    }
    
    array[30].next=1;
    j=30;
    for(i=0;i<15;i++){
        for(k=0;;){
            if(k<9){
                j=array[j].next;
                k+=array[j].flag;
            }else{
                break;
            }
            
        }
        array[j].flag=0;
    }
    
    for(i=1;i<=30;i++){
        printf("%c",array[i].flag ? 'b':'s');
    }
}