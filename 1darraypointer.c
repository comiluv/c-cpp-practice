#include <stdio.h>

int main()
{
	int arr[10] = {60, 58, 77, 55, 79, 46, 82, 16, 10, 49};
	int *parr;
	int sum = 0;

	parr = arr;

	printf("니 시험 점수\n");
	while (parr - arr <= 9)
	{
		printf(" %d ", *parr);
		sum += *parr;
		parr++;
	}
	printf("\n");
	printf("니 시험 점수 평균 : %3.2f\n", sum * 0.1);

	return 0;
}