#include <stdio.h>

void static_function(void){
	static int cnt = 0;
	++cnt;
	printf("static int cnt is %d.\n", cnt);
}
