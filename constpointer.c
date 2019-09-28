#include <stdio.h>

int main(){
	int a = 1;
	int b;
	const int* pa=&a;
	printf("*pa is : %d \n",*pa);
	// *pa = 3;
	a = 2;
	printf("*pa is : %d \n",*pa);
	pa = &b;

	return 0;
}