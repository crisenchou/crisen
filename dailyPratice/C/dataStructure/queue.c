#include "stdio.h"
#include "stdlib.h"

typedef char ElemType;

typedef struct Node{
    ElemType data;
    ElemType *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;


void initQueue(LinkQueue *q){
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
    if(!q->front)  exit(0);
    q->front->next = NULL;
}

void EnQueue(LinkQueue *q,ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!q->front) exit(0);
    p->data = e;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
}

void DeQueue(LinkQueue *q, ElemType *e){
    QueuePtr p;
    if(q->front == q->rear) return;
    p=q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;
    free(p);
}

void DestroyQueue(LinkQueue *q){
    while(q->front){
        q->rear=q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}

int main(){
    ElemType e;
    LinkQueue q;
    initQueue(&q);
    printf("pelease input a string to queue");
    scanf("%c",&e);
    while(e!='@'){
        EnQueue(&q,e);
        scanf("%c",&e);
    }
    printf("the string into the queue is \n");
    while(q.front != q.rear){
        DeQueue(&q,&e);
        printf("%c",e);
    }
    
    printf("\n");
    DestroyQueue(&q);
    getche();
}

