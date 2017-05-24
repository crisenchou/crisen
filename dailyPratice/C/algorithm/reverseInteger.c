#include <stdio.h>

int reverse(int x) {
	int res=0;
	while(x!=0){
		res = res*10+x%10;
		x=x/10;
		
	}
	return res;
}

int main(){
	int a;
	start:
	printf("please enter a number:");
	scanf("%d", &a);
	printf("the reverse number is %d\n",reverse(a));
	goto start;
	return 0;
}