#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#define STACK_INIT_SIZE 20
#define STACKINCREAMENT 10

typedef char ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

void initStack(sqStack *s){
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
        s->base = (ElemType *)realloc(s->base, (s->stacksize+STACKINCREAMENT)*sizeof(ElemType));
        if(!s->base)  exit(0);
        s->top = s->base + s->stacksize;
    }
    *(s->top) = e;
        s->top++;
}

void Pop(sqStack *s, ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);
}

int StackLen(sqStack s){
    return (s.top-s.base);
}

void DestroyStack(sqStack *s){
    free(s->base);
    s->base = s->top = NULL;
    s->stacksize =0;
}
//把二进制数转换成十进制数
int main(){
    ElemType c;
    sqStack s;
    int len,i,sum=0;
    printf("peleasr inout a bin digit\n");
    initStack(&s);
    scanf("%c",&c);
    while(c!='#'){
        Push(&s,c);
        scanf("%c",&c);
    }
    getchar();
    len = StackLen(s);
    printf("the stack's length is %d", len);
    
    for(i=0;i<len;i++){
        Pop(&s,&c);
        sum = sum + (c-48)*pow(2,i);
    }
    
    printf("Demical is %d",sum);
    
    DestroyStack(&s);
    getche();
}