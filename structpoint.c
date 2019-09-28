/* 
구조체와 포인터
 */
#include <stdio.h>

struct TEST
{
	int c;
	int *pointer;
};

int main()
{
	struct TEST t;
	struct TEST *ptr = &t;

	int i = 0;
	printf("i = %d\n", i);

	/* t.pointer는 i */
	t.pointer = &i;

	*t.pointer = 1;

	printf("i = %d\n", i);

	/* ptr이 가리키는 struct의 변수 pointer가 가라키는 변수 */
	*ptr->pointer = 2;

	printf("i = %d\n", i);

	return 0;
}