/* 2차원 행렬과 포인터
https://modoocode.com/25 */

#include <stdio.h>

int main()
{
	int i = 0, j = 0;
	//
	// arr[cols][rows]
	/* 
	  int arr[2][3] = {1, 2,
				      3, 4,
					  5, 6};

	 */
	int arr[2][3] = {1, 2, 3,
					 4, 5, 6};

	// 2차원 행렬을 가리키는 포인터는 column 갯수마다 증가해야 row가 하나 증가하므로 column 갯수를 표기해서 선언해야 한다
	int(*parr)[3] = arr;

	// 아니면 첫번째 원소 ([0][0])을 가리키는 포인터를 만든다
	int *ptr = &arr[0][0];

	// using void* (1 byte)
	void *vptr = ptr;

	// [row][col]이 아닌 [col][row]라는 방식으로 생각한다면 (즉 Cartesian plane 의 x, y 처럼)
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 2; i++)
		{
			printf("%d : ", i + j * 2);
			printf("ptr: %d  ", *(ptr + i + j * 2));
			// arr[i][j] = baseAddress + [(i x no_of_cols + j) x size_of_data_type]
			// convert void* to int* then reference by *
			printf("vptr: %d // ", *(int *)(vptr + (i + j * 2) * sizeof(int)));
		}
		printf("\n");
	}
	// 위처럼 iteration을 하면 12/34/56으로 나오지만
	printf("arr[1][1] = %d\n", arr[1][1]);
	// 위처럼 row 2 column 2에 있는 원소를 직접 선택하면 5가 나온다. (4가 아니라)
	printf("\n");

	printf("arr : %p\n", arr);
	printf("parr: %p\n", parr);

	printf("arr[0]     : %p\n", arr[0]);
	printf("&arr[0][0] : %p\n", &arr[0][0]);

	printf("arr[1]     : %p\n", arr[1]);
	printf("&arr[1][0] : %p\n", &arr[1][0]);

	printf("전체 크기       : %lu\n", sizeof(arr));
	printf("element 개수  : %lu\n", sizeof(arr) / sizeof(int));
	printf("총 row 개수    : %lu\n", sizeof(arr) / sizeof(arr[0]));
	printf("총 column 개수 : %lu\n", sizeof(arr[0]) / sizeof(arr[0][0]));

	return 0;
}