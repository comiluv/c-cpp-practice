#include <stdio.h>

int main()
{
	int a = 1, b = 2, c = 3;
	int *ptr[3];
	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;

	printf("a : %d, *ptr[0] : %d\n", a, *ptr[0]);
	printf("b : %d, *ptr[1] : %d\n", b, *ptr[1]);
	printf("c : %d, *ptr[2] : %d\n", c, *ptr[2]);

	printf("&a : %p, ptr[0] : %p\n", &a, ptr[0]);

	return 0;
}