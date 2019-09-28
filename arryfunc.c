#include <stdio.h>

int add_number(int *inputArray);

int main()
{
	int arr[3];
	int i;

	/* 사용자에게서 3개의 숫자를 입력받는다 */
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		printf("%d번째 숫자를 입력하시오 : ", i + 1);
		scanf("%d", &arr[i]);
	}

	printf("배열의 각 원소 : %d  %d  %d\n", arr[0], arr[1], arr[2]);

	add_number(arr);

	printf("배열의 각 원소 : %d  %d  %d\n", arr[0], arr[1], arr[2]);

	return 0;
}

int add_number(int *inputArray)
{
	for (int i = 0; i < 3; i++)
	{
		inputArray[i]++;
	}
}