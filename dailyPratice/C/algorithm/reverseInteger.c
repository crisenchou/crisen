#include <stdio.h>

int reverse(int x) {
	int res=0;
	while(x!=0){
		int tail = x%10;
		int newRes = res*10+tail;
		if((newRes-tail)/10 !=res){
			return 0;
		}
		res = newRes;
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