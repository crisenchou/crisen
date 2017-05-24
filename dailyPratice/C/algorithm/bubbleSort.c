#include <stdio.h>
#define N 5


void printArray(int a[], int length){
	int i;
	for(i=0;i<length;i++)
		printf("%3d",a[i]);
}

int BubbleSort(int a[], int length){
	int i,j;
	for(i=0;i<length;i++){
		for(j=i+1;j<length;j++){
			if(a[i]>a[j]){
				a[i] = a[i]^a[j];
				a[j] = a[i]^a[j];
				a[i] = a[i]^a[j];
			}
		}
	}
}


int main(){
	int i,a[N];
	printf("please enter 5 number,divide by \\n \n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	BubbleSort(a, N);
	printArray(a, N);
	getche();
}