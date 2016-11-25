#include <stdio.h>
#include <stdlib.h>

void print_triple_array(const char *title, double p[3][4][3], int x, int y, int z){
	int i,j,k;
	printf("\nPrinting '%s' array\n", title);
	for(i = 0; i < x; i++){
		printf("[ ");
		for(j = 0; j < y; j++){
			printf("{");
			for(k = 0; k < z; k++){
				printf("%3.0f",p[i][j][k]);
			}
			printf("}");
			if(j!=y-1) printf(", ");
		}
		printf(" ]\n");
	}
	printf("\n");
}

int main()
{
	double a[3][4][3] = {
		{{1.0,2.0,3.0},{4.0,5.0,6.0},{7,8,9},{10,11,12}},
		{{13,14,15},{16,17,18},{19,20,21},{22,23,24}},
		{{25,26,27},{28,29,30},{31,32,33},{34,35,36}}
	};

	print_triple_array("a",a,3,4,3);

	double (*b)[4][3];
	double *(*c)[4];
	double ***d;

	int i,j,k;
	
	// Initialize b by a.
	b = &a[0];
	print_triple_array("b",b,3,4,3);
	
	// Initalize c by b. Use double loops.
	c = (double*(*)[4])malloc(sizeof(double*[4][3]));
	for(i = 0; i < 3; i++){
		for(j = 0; j < 4; j++){
			c[i][j] = b[i][j];
		}	
	}
	
	printf("\nAssigned c by b.\n");
	printf("a[2][3] = %p\n", a[2][3]);
	printf("b[2][3] = %p\n", b[2][3]);
	printf("c[2][3] = %p\n", c[2][3]);
	printf("*c[2][3] = %3.0f\n", *c[2][3]);
	
	// Initialize d by c. use one loop.
	d = (double***)malloc(sizeof(double**[3]));
	for(k = 0; k < 3; k++){
		*(d+k) = *(c+k);
	}
	printf("\nAssigned d by c.\n");
	printf("c[2] = %p\n", c[2]);
	printf("**c[2] = %3.0f\n", **c[2]);
	printf("d[2] = %p\n", d[2]);
	printf("**d[2] = %3.0f\n", **d[2]);

	return 0;

}	
