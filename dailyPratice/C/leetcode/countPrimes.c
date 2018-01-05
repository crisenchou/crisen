#include <stdio.h>

/*
Count the number of prime numbers less than a non-negative number, n.
给定一个n  找出n以内所有的素数的数量
*/

int countPrimes(int n);
int isPrime(int n);


int main(){
    int n=4;
    printf("%d",countPrimes(n));
}

int countPrimes(int n) {
    int i,count=0;
    if(i<2){
        return 0;
    }
    for(i=2;i<n;i++){
        if(isPrime(i)){
            count++;
        }
    }
    return count;
}

int isPrime(int n){
    int i;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}