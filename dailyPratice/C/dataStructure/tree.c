#include <stdio.h>
#include <stdlib.h>



typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

CreateBitree(BiTree *T){
    char c;
    scanf("%c",&c);
    if(c == ' ')  *T = NULL;
    else{
        *T = (BiTNode * )malloc(sizeof(BiTNode));
        (*T)->data = c;
        CreateBitree(&((*T)->lchild));
        CreateBitree(&((*T)->rchild));
    }
}


visit(char c, int level){
    if(c =='D')
        printf("%c is at %d level of the tree",c,level);
}

//先序遍历
PreOrderTraverse(BiTree T,int level){
    if(T){
        visit(T->data,level);
        PreOrderTraverse(T->lchild,level);
        PreOrderTraverse(T->rchild,level);
    }
}

//先序遍历
InOrderTraverse(BiTree T,int level){
    if(T){
        PreOrderTraverse(T->lchild,level);
        visit(T->data,level);
        PreOrderTraverse(T->rchild,level);
    }
}


//先序遍历
PosOrderTraverse(BiTree T,int level){
    if(T){
        PreOrderTraverse(T->lchild,level);
        PreOrderTraverse(T->rchild,level);
        visit(T->data,level);
    }
}

int main(){
    int level=1;
    BiTree T = NULL;
    CreateBitree(&T);
    PosOrderTraverse(T,level);
    getche();
}