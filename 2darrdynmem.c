/* 
2차원 배열의 동적 할당
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("usage: [num_rows] [num_cols]\n");
		return 1;
	}
	int i;
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	printf("x : %d // y : %d\n", x, y);
	printf("필요한 메모리 양 : %lu bytes\n", x * y * sizeof(int *) * sizeof(int));
	int **arr;

	// 더블 포인터이므로 int*의 size를 계산한다는걸 잊지 말것 즉 8바이트씩임 (64bit에서)
	arr = (int **)malloc(sizeof(int *) * x);

	for (i = 0; i < x; ++i)
	{
		arr[i] = (int *)malloc(sizeof(int) * y); // 여기는 4byte씩임 (int이므로)
	}
	printf("생성 완료!\n");
	for (i = 0; i < x; ++i)
	{
		free(arr[i]);
	}
	free(arr);
	return 1;
}