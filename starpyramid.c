#include <stdio.h>

int main()
{
	int N;
	int i, j, k;
	printf("몇 줄? : ");
	scanf("%d", &N);
	for (i = 0; i < N; i++)
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

	return 0;
}