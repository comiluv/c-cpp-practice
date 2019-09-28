#include <stdio.h>

int main()
{
	int N = 1000;
	int a = 3, b = 5;
	int total = 0, i;
	printf("멋있게 %d 이하의 자연수중  %d 또는 %d 의 배수인 수의 합을 구한다.\n", N, a, b);
	for (i = 1; i <= N; i++)
	{
		if (i % a == 0)
		{
			// printf("%d는 %d의 배수이지롱!\n", i, a);
			total++;
		}
		else if (i % b == 0)
		{
			// printf("%d는 %d의 배수이지롱!\n", i, b);
			total++;
		}
	}
	printf("답은 %d 이지롱!\n", total);
	return 0;
}