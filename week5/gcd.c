#include <stdio.h>
int gcd(int a, int b){
	int r;
	while((r=a%b) != 0){
		a = b;
		b = r;
	}
	return b;
}

int main(void){
	printf("gcd(10,15) = %d\n", gcd(10,15));
	printf("gcd(125,13) = %d\n", gcd(125,13));
	printf("gcd(625,225) = %d\n", gcd(625,225));
	printf("gcd(6840,324) = %d\n", gcd(6840,324));
	return 0;
}
