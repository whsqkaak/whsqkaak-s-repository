#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char*, char*);

int main(int argc, char const *argv[]){
	char* a = "Hello,";
	char* b = "World!";
	char* string = concat(a,b);
	printf("%s\n", string);
}

char* concat(char* a, char*b){
	int i = 0;
	char* temp = (char*)malloc(strlen(a) + strlen(b)+1);
	for(i = 0; i < strlen(a); ++i){
		*(temp+i) = *(a+i);
	}
	for(int j = 0; j < strlen(b)+1; ++j){
		*(temp+i) = *(b+j);
		++i;
	}
	return temp;
}
