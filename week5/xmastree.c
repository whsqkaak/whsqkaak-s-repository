#include <stdio.h>
int main(void){
	int size;
	printf("Christmas tree. How large? ");
	scanf("%d", &size);
	for(int i=0; i<size ;i++){
		for(int j=0; j<size-i-1; j++){
			printf(" ");
		}
		for(int j=0; j<2*i+1; j++){
			printf("*");
		}
		for(int j=0; j<size-i; j++){
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}
