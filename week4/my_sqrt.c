#include <stdio.h>
#include <math.h>

double my_sqrt(double number){
	double sqrt;
	sqrt = 1.0;
	for(int i=0; i<50; i++){
		sqrt = (sqrt + number/sqrt)/2;
	}
	return sqrt;
}

int main(int argc, char const *argv[]){
	double integer;
	printf("Tell me non-negative number X: ");
	scanf("%lf", &integer);
	printf("\nsqrt(x)	= %10lf, sqrt(x)^2	= %.30e\n"
		"my_sqrt(x) = %10lf, my_sqrt(x)^2 = %.30e \n",
		sqrt(integer), sqrt(integer)*sqrt(integer),
		my_sqrt(integer), my_sqrt(integer)*my_sqrt(integer));

	return 0;
}
