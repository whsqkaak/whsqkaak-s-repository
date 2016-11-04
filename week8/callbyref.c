#include <stdio.h>

void swap(int*, int*);

int main(void){
	int i = 3, j = 5;
	swap(&i,&j);
	printf("%d %d\n", i, j);
	return 0;
}

void swap(int *p, int *q){
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}
