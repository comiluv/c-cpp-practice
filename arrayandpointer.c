/* https://modoocode.com/24
배열과 포인터
 */
#include <stdio.h>

int main()
{
	int arr[10];
	int *parr;
	int i;

	parr = &arr[0];

	for (i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}

	printf("sizeof(arr)    : %lu\n", sizeof(arr));
	printf("sizeof(arr[0]) : %lu\n", sizeof(arr[0]));
	printf("sizeof(parr)   : %lu\n", sizeof(parr));
	printf("sizeof(*parr)  : %lu\n", sizeof(*parr));
	printf("\n");

	printf("arr의 정체 arr          = %p\n", arr);
	printf("arr[0]의 주소값 &arr[0] = %p\n", &arr[0]);
	printf("\n");

	printf("arr[3]   : %d\n", arr[3]);
	printf("*(arr+3) : %d\n", *(arr + 3));
	printf("3[arr]   : %d\n", 3 [arr]);
	printf("*(3+arr) : %d\n", *(3 + arr));
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("arr[%d] = %d , *(parr + %d) = %d // ", i, arr[i], i, *(parr + i));
		printf("arr[%d]의 주소 값 : %p ", i, &arr[i]);
		printf("(parr + %d)의 값 : %p ", i, parr + i);

		if (&arr[i] == parr + i)
		{
			// 만일 address of index i of array arr == pointer parr + i 라면
			printf(" --> 일치 \n");
		}
		else
		{
			printf(" --> 불일치 \n");
		}
	}

	return 0;
}