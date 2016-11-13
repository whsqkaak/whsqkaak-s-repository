#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *, int);
void swap(int *, int *);
void print_array(int *, int);

int main(int argc, char const* argv[]){
	int a[argc-1];
	for (int i = 1; i < argc; i++){
		a[i-1] = atoi(argv[i]);
	}
	int n = sizeof(a)/sizeof(int);
	
	selection_sort(a,n);
	
	printf("\n	After Selection Sort : \n\n");
	for(int j = 0; j < n; ++j)
		printf("%5d", a[j]);
	printf("\n\n");
	return 0;
}

void selection_sort(int a[], int n){
	for(int i = 0; i < n; i++){
		int *min = a+i; 
		for(int j = i; j < n; j++){
			if(*min > *(a+j)){
				min = a+j;
				swap(min, a+i);
			}
			print_array(a, n);
		}
	}		
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_array(int *a, int n){
	for(int i = 0; i < n; ++i)
		printf("%5d", a[i]);
	putchar('\n');
}
