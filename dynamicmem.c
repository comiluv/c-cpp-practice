/* 
동적 메모리 할당
https://modoocode.com/98
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int sizeofarray = 0;
	int *arr;
	int i = 0;

	printf("만들고 싶은 배열의 원소 수: :");
	scanf("%d", &sizeofarray);

	arr = (int *)malloc(sizeof(int) * sizeofarray);
	for (i = 0; i < sizeofarray; ++i)
	{
		arr[i] = i + 1;
	}
	for (i = 0; i < sizeofarray; ++i)
	{
		printf("arr의 %d번째 원소 : %d\n", i + 1, arr[i]);
	}
	free(arr);
	return 0;
}