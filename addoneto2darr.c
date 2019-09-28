/* 2차원 배열의 각 원소에 1씩 더하는 함수 */
#include <stdio.h>
int printarr(int (*arr)[5]);
int addonetoarray(int (*arr)[5]);

int main()
{
	int i, j;
	int arr[5][5];
	int *parr = &arr[0][0];

	//fill array
	for (i = 0; i < 25; i++)
	{
		*parr = i + 1;
		parr++;
	}

	//print original array
	printarr(arr);

	printf("\n");

	//add one to array
	addonetoarray(arr);

	//print original array
	printarr(arr);

	printf("\n");
}

int addonetoarray(int (*arr)[5])
{
	printf("더합니닷!\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j]++;
		}
	}
}

int printarr(int (*arr)[5])
{
	int(*parr)[5] = arr;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("[%d][%d] = %d  ", i, j, parr[i][j]);
		}
	}
}