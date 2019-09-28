#include <stdio.h>

int main()
{
	unsigned int N, i;
	double total = 1;
	printf("1부터 N까지 자연수를 곱할거지롱! 입력하지롱! : ");
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
	{
		total *= i;
	}
	if (total < 100000000)
	{
		printf("답은 %.0f 이지롱!\n", total);
	}
	else
	{
		printf("답은 %e 이지롱!\n", total);
	}

	return 0;
}