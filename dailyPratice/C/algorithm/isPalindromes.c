#include <stdio.h>
#include <math.h>
#define true 1;
#define false 0;

int getLength(int n){
	int i=0;
	while(n!=0){
		n=n/10;
		i++;
	}
	return i;
}


int isPalindromes(int n){
	if(n<0){
		return false;
	}
	if(n==0){
		return true;
	}
	
	int l = getLength(n);
	while(l>1){
		printf("l is %d\n",l);
		int head = n/pow(10,l-1);
		printf("head is %d\n",head);
		int tail = n%10;
		printf("tail is %d\n",tail);
		if(head != tail){
			return false;
		}
		n = (n-head*pow(10,l-1))/10;
		printf("n is %d\n",n);
		l=l-2;
	}
	return true;
}





int main(){
	int n;
	start:
	printf("please enter a number:");
	scanf("%d", &n);
	if(isPalindromes(n)){
		printf("the number is a palindromes\n");
	}else{
		printf("the number is not a palindromes\n");
	}
	goto start;
	return 0;
}