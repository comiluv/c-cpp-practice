/* 에라스토스테네스의 체를 이용해 1부터 N까지의 소수를 구한다 */
#include <stdio.h>
int erastosthenes(int *nums, int size, int gcd);

int main()
{
	int N;
	printf("몇까지? ");
	scanf("%d", &N);
	int nums[N];
	for (int i = 1; i <= N; i++)
	{
		nums[i] = 1;
	}
	for (int i = 2; i <= N / 2; i++)
	{
		if (nums[i] == 1)
		{
			erastosthenes(nums, N, i);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (nums[i] != 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

int erastosthenes(int *nums, int size, int gcd)
{
	int i;
	for (i = gcd * gcd; i < size; i += gcd)
	{
		nums[i] = 0;
	}
}
