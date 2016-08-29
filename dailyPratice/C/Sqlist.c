#include <stdio.h>

#define MaxSize 100

/*
* 插入数据
*/
void insertElem(int Sqlist[], int *len, int i, int x)
{
    int t;
    if(*len==MaxSize || i<1 || i>*len+1){
        printf("ellegal insert");
        return;
    }
    for(t=*len-1;t>=i-1;t--)
        Sqlist[t+1]=Sqlist[t];
    Sqlist[i-1]=x;
    *len = *len+1;
}


void DelElem(int Sqlist[], int *len, int i)
{
    int j;
    if(i<1 || i>*len)
    {
        printf("ellegal delete");
        return;
    }
    for(j=i;j<=*len-1;j++)
        Sqlist[j-1]=Sqlist[j];
    *len = *len-1;
}

void printElem(int Sqlist[], int len)
{
    int i;
    printf("the list is bellow\n");
    for(i=0;i<len;i++){
        printf(" %d \n",Sqlist[i]);
    }
}

int main(){
    int Sqlist[MaxSize];
    int len;
    int i;
    printf("Please enter 5 numbers");

    for(i=0;i<5;i++){
        scanf("%d",&Sqlist[i]);
    }
    
    len=5;
    printf("ths left spare is %d", MaxSize - len);
    printElem(Sqlist,len);
    insertElem(Sqlist,&len,3,0);
    
    printf("ths left spare is %d", MaxSize - len);
    printElem(Sqlist,len);
    DelElem(Sqlist,5);
    printElem(Sqlist,len);
}