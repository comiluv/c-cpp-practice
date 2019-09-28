#include <stdio.h>

int main()
{
	int N;
	int i, j, k;
	printf("역삼각형 몇 줄? : ");
	scanf("%d", &N);
	for (i = N - 1; i >= 0; i--)
	{
		for (j = N - i; j > 0; j--)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i + 1; k++)
		{
			printf("*");
			if (k == 2 * i + 1)
			{
				printf("\n");
			}
		}
	}
}