#include <stdio.h>

int main(void){
	char a[4][10] = {"HaHa", "han yang ", "cheese", " Iphone"}; 
	char *(pc[4]) = {a[0], a[1], a[2], a[3]};
	char **ppc = pc;

	printf("%c", *(*(pc))); 
	printf("%c%c", *(*(pc+1)+1), *(*(pc+1)+2));
	printf("%s ", *(ppc+1)+4);
	printf("%c%c%c\n",*(*(pc+2)), *(*(pc+2)+4), *(*(pc+2)+2));

	return 0;
}

// Print "Hanyang cse"
