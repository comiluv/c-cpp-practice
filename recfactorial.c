#include <stdio.h>
int factorial(int);

int main()
{
	int x;
	int ans = 0;
	printf("팩토리얼 할 수를 입력하시오 : ");
	scanf("%d", &x);
	ans = factorial(x);
	printf("%d! = %d\n", x, ans);

	return 0;
}

int factorial(int i)
{
	if (i == 1)
	{
		return 1;
	}
	return (i * factorial(i - 1));
}