/* 함수를 가리키는 포인터 */
#include <stdio.h>

int max(int a, int b);

int main()
{
	int i, j;
	int (*pmax)(int, int);
	pmax = max;

	scanf("%d %d", &i, &j);
	printf("max(a,b) : %d\n", max(i, j));
	printf("&max : %p\n",&max);
	printf("pmax : %p\n",pmax);
	printf("pmax(a,b) : %d\n", pmax(i, j));

	return 0;
}

int max(int a, int b)
{
	return a > b ? a : b;
}