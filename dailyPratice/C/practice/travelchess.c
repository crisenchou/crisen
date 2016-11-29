#include <stdio.h>
#define X 8
#define Y 8
#define true 1
#define false 0
int chess[X][Y];
typedef int bool;




bool nextxy(int *x, int *y, int count)
{
    switch(count){
        //象棋中的马共有8中行走方法
        case 0:
            if(checkEdge(*x+2, *y-1)){
                *x=*x+2;
                *y=*y-1;
                return true;
            }
            break;
        case 1:
            if(checkEdge(*x+2, *y+1)){
                *x=*x+2;
                *y=*y+1;
                return true;
            }
            break;
        case 2:
            if(checkEdge(*x+1, *y-2)){
                *x=*x+1;
                *y=*y-2;
                return true;
            }
            break;
        case 3:
            if(checkEdge(*x+1, *y+2)){
                *x=*x+1;
                *y=*y+2;
                return true;
            }
            break;
        case 4:
            if(checkEdge(*x-2, *y-1)){
                *x=*x-2;
                *y=*y-1;
                return true;
            }
            break;
        case 5:
            if(checkEdge(*x-2, *y+1)){
                *x=*x-2;
                *y=*y+1;
                return true;
            }
            break;
        case 6:
            if(checkEdge(*x-1, *y-2)){
                *x=*x-1;
                *y=*y-2;
                return true;
            }
            break;
        case 7:
            if(checkEdge(*x-1, *y+2)){
                *x=*x-1;
                *y=*y+2;
                return true;
            }
            break;
        default:
            break;
    }
    
    return false;
}

bool checkEdge(int x, int y){
    if(x>=0 && y>=0 && x<=X-1 && y<=Y-1 && chess[x][y]==0){
        return true;
    }
    return false;
}


int TravelChessBoard(int x, int y, int tag){
    int x1 = x,
        y1 = y,
        flag = 0,
        count = 0;
    chess[x][y]=tag;
    if(tag==X*Y)
        return 1;
    flag = nextxy(&x1, &y1,count);
    
    while(flag==0 && count<7){
        count = count+1;
        flag = nextxy(&x1, &y1,count);
    }
    
    while(flag){
        if(TravelChessBoard(x1, y1, tag+1)){
            return 1;
        }
        x1=x;
        y1=y;
        count = count+1;
        flag = nextxy(&x1,&y1,count);
        while(flag==0 && count<7){
            count = count+1;
            flag = nextxy(&x1,&y1,count);
        }
    }
    
    if(flag==0){
        chess[x][y]=0;
    }
    return 0;
}


void initChess(){
    int i,j;
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            chess[i][j]=0;
        }
    }
}


void printChess(){
    int i,j;
    for(i=0;i<X;i++){
        for(j=0;j<Y;j++){
            printf("%d\n",chess[i][j]);
        }
    }
}

int main()
{
    initChess();
    int i,j;
    if(TravelChessBoard(2,0,1)){
        //printChess();
        for(i=0;i<X;i++){
            for(j=0;j<Y;j++){
                printf("%-5d",chess[i][j]);
            }
            printf("\n");
        }
        printf("the horse has traveled the chess board!");
    }else{
        printf("the horse cannot travel the chess board!");
    }
  
}
