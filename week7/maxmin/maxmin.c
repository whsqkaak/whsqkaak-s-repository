#include <stdio.h>

int max(int);
int min(int);

int maxcount = 0;
int mincount = 0;
int main(int argc, char const *argv[]){
	int i;
	for( i = 0; i < 15; i++)
		max(i);
	for( i = 20; i > 1; i--)
		min(i);
	printf("max() called %d times\n", maxcount);
	printf("min() called %d times\n", mincount);
	printf("max() called %d times, maxval : %d\n", maxcount, max(5));
	printf("min() called %d times, minval : %d\n", mincount, min(10));
	return 0;
}

int max(int n){
	static int max_num = 0;
	if( n > max_num)
		max_num = n;
	maxcount++;
	return max_num;
}

int min(int n){
	static int min_num = 100;
	if(n < min_num)
		min_num = n;
	mincount++;
	return min_num;
}

