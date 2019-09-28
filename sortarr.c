/* 입력받은 배열을 큰 순서대로 출력 */
#include <stdio.h>

/* max_number : argument로 전달받은 크기 10인 배열로부터 최대값을 구하는 함수 */
int max_number(int *parr);
int sort_arr(int *parr, int size, int starting_point);
int swap(int *a, int *b);

int main()
{
	int arr[10];
	int i;

	/* 사용자로부터 원소를 입력받는다 */
	printf("원소를 입력하시오\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d번째 원소 : ", i + 1);
		scanf("%d", &arr[i]);
	}

	sort_arr(arr, 10, 0);
	// printf("최대값 : %d\n", max_number(arr));

	for (i = 0; i < 10; i++)
	{
		printf("%d번째 원소 : %d\n", i + 1, arr[i]);
	}
}

/* do selection sort */
int sort_arr(int *parr, int size, int starting_point)
{
	int i = 0;
	int tempmaxindex = starting_point;
	for (i = starting_point + 1; i < size; i++)
	{
		if (parr[tempmaxindex] < parr[i])
		{
			tempmaxindex = i;
		}
	}
	swap(&parr[starting_point], &parr[tempmaxindex]);
	if (starting_point < size)
	{
		sort_arr(parr, size, starting_point + 1);
	}
}

/* swaps variable a and b */
int swap(int *a, int *b)
{
	if (a != b)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}

/* get the max number in an array */
int max_number(int *parr)
{
	int i;
	int tempMax = 0;
	for (i = 0; i < 10; i++)
	{
		tempMax = tempMax < parr[i] ? parr[i] : tempMax;
	}
	return tempMax;
}