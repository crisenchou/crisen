#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//递归
int feiboRecursive(int n){
    if(n==1 || n==2){
        return 1;
    }else{
        return feiboRecursive(n-1)+feiboRecursive(n-2);
    }
    
}


//迭代
int feiboIteration(int n){
    if(n<0){
        return 0;
    }
    if(n==1 || n==2){
        return 1;
    }
    int feibo,feibo1=1,feibo2=1,i;
    for(i=3;i<=n;i++){
        feibo = feibo1+feibo2;
        feibo1 = feibo2;
        feibo2 = feibo;
    }
    return feibo;
    
}


//尾递归
int feiboTailRecursive(int n,int feibo1, int feibo2){
    if(n==1){
        return feibo1;
    }else if(n==2){
        return feibo2;
    }else{
        int feibo;
        feibo = feibo1+feibo2;
        feibo1 = feibo2;
        feibo2 = feibo;
        --n;
        return feiboTailRecursive(n, feibo1, feibo2);
    }
}


//公式法 ps用公式法求第二项和第三项有bug 用PHP都没有这样的问题 令人匪夷所思
int feibo(int n){
    if(n==2){
        return 1;
    }
    if(n==3){
        return 2;
    }
    return (pow((sqrt(5)+1)/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5);
}

int main(){
    
    int n,i;
    printf("please enter a number:");
    scanf("%d",&n);
    
    if(n>48){
        printf("the number will bo overflow!");
        return 0;
    }
    
    for(i=1;i<=n;i++){
        printf("the %dth element of feibo is %d  -----Iteration\n",i,feiboIteration(i));
    }
    
    
    for(i=1;i<=n;i++){
        printf("the %dth element of feibo is %d  -----Recursive\n",i,feiboRecursive(i));
    }
    
    for(i=1;i<=n;i++){
        printf("the %dth element of feibo is %d  -----TailRecursive\n",i,feiboTailRecursive(i,1,1));
    }
  
  
    for(i=1;i<=n;i++){
        printf("the %dth element of feibo is %d  -----math\n",i,feibo(i));
    }
    getche();
    return 0;
    
}