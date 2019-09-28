#include <stdio.h>
int swap(int *a, int *b);

int main()
{
	int a = 2, b = 5;
	printf("두 변수의 값을 바꿔주는 함수\n");
	printf("바꾸기 전 a : %d, b : %d\n", a, b);
	swap(&a, &b);
	printf("바꾼 후 a : %d b : %d\n", a, b);
	return 0;
}

int swap(int *a, int *b)
{
	// XOR Swap : https://en.wikipedia.org/wiki/XOR_swap_algorithm
	if (a != b)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}