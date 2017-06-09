#include <stdio.h>


void printArr(int *p, int length){
	while(length){
		printf("the string is %d\n",*p);
		p++;
		length--;
	}
}

int main(){
	int *p;
	int a[] = {1,2,3,4,5,6};
	printArr(a,6);
	getche();
}