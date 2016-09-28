#include <stdio.h>
#define N 10


int main(){
	int i,j,a[N],t;
	printf("请给数组赋值 \n");
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=N-1;i++){
		for(j=0;j<N-i;j++){
		    if(a[j] > a[j+1]){
			    t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	
	printf("请给数组赋值 \n");
	for(t=0;t<N;t++){
		printf("%d\n",a[t]);
	}
}
