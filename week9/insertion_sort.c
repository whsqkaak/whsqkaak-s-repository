#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *, int);
void swap(int *, int *);
void print_array(int *, int);

int main(int argc, char const* argv[]){
	int a[argc-1];
	for (int i = 1; i < argc; i++){
		a[i-1] = atoi(argv[i]);
	}
	int n = sizeof(a)/sizeof(int);

	insertion_sort(a,n);

	printf("\n	After Insertion Sort : \n\n");
	for(int j = 0; j < n; ++j)
		printf("%5d", a[j]);
	printf("\n\n");
	return 0;
}

void insertion_sort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = i; j >0 ; j--){
			if(*(a+j) < *(a+j-1)){
				swap(a+j, a+j-1);
				print_array(a, n);
			}
		}
	}
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int *a, int n){
	for(int i=0; i < n; ++i)
		printf("%5d", a[i]);
	putchar('\n');
}
