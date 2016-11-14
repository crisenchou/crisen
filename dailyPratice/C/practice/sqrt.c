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

//求平方根 速度比牛顿法更快

float Q_rsqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;
	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;        
	i  = 0x5f3759df - ( i >> 1 ); 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) ); 
	// y  = y * ( threehalfs - ( x2 * y * y ) ); 
	#ifndef Q3_VM
	#ifdef __linux__
	assert( !isnan(y) ); 
	#endif
	#endif
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
