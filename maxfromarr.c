/* 입력받은 배열의 원소 중 최대값을 출력 */
#include <stdio.h>

/* max_number : argument로 전달받은 크기 10인 배열로부터 최대값을 구하는 함수 */
int max_number(int *parr);

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

	printf("최대값 : %d\n", max_number(arr));
}

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