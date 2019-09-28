#include <stdio.h>

int main()
{
	int *p;
	int a;

	p = &a;
	a = 2;
	printf("int *p = &a where int a = 2\n\n");

	printf("a의 값 a : %d \n", a);
	printf("a의 주소 &a : %p \n", &a);
	printf("p의 값 p : %p \n", p);
	printf("p의 주소 &p : %p \n", &p);
	printf("*p의 값 *p : %d \n", *p);
	printf("*p = 3 을 입력\n");
	*p = 3;
	printf("a의 값 a : %d \n", a);

	return 0;
}
