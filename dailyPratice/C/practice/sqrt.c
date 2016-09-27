#include <stdio.h>
#include <math.h>

//牛顿法求平方根  X(n+1)=[ X(n) +p/X(n) ]/2
double fuckNewton(double n)
{
	double y=1.0;
	while(fabs((1.0/2.0*(y+n/y)-y))>=0.000001){
	    y=1.0/2.0*(y+n/y);
	}
	return y;
}



int main()
{
	double n;
    printf("pelease enter a number:");


	scanf("%lf", &n);

    printf("the number's square is %lf",fuckNewton(n));

	getche();
	return 0;
}
