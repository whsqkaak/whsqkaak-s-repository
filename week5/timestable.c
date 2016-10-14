#include <stdio.h>
int main(void){
	int k;
	int result;
	printf("Enter the level of times table : ");
	scanf("%d", &k);
	for(int i=1; i<11; i++){
		printf("%d * %d = %d\n", k, i, k*i);
	}
	return 0;
}
