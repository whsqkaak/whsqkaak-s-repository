#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char*);

int main(int argc, char const *argv[]){
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	printf("%s\n", reverse(str));
	return 0;
}

char* reverse(char* s){
	int j = 0;
	char* temp = (char*)malloc(strlen(s)+1);
	for(int i = strlen(s)-1; i > -1; i--){
		*(temp+j) = *(s+i);
		j++;
	}
	return temp;
}
