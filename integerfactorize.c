#include <stdio.h>

int main()
{
	int N;
	printf("임의의 자연수 N을 입력하지롱! : ");
	scanf("%9d", &N);
	int n = 2;
	int notFirst;
	printf("소인수 분해 결과지롱!\n");
	if (N < 1)
	{
		printf("자연수가 아니네!");
	}
	else if (N <= 2)
	{
		printf("%d", N);
	}
	else
	{
		while (n <= N)
		{
			if (N % n == 0)
			{
				if (notFirst == 1)
				{
					printf(" * ");
				}
				printf("%d", n);
				N /= n;
				n = 2;
				notFirst = 1;
			}
			else
			{
				n++;
			}
		}
	}
	printf("\n");
}