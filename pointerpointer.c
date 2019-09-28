#include <stdio.h>

int main()
{
	int a;
	a = 2;
	int *b;
	int *c;
	int **d;
	int ***e;

	b = &a;
	// 아래 라인은 컴파일 에러 cannot convert 'int**' to 'int*' in assignment
	// c = &b;
	d = &b;
	e = &d;

	printf("int a의 값 a = 2 에서 a (integer)        : %d\n", a);
	printf("int *b의 값 b = &a 에서 b (pointer)      : %p\n", b);
	printf("int *b의 값 b = &a 에서 *b (integer)     : %d\n", *b);
	printf("int *c의 값 c = &b <- error (NULL)       : %p\n", c);
	printf("int **d의 값 d = &b 에서 d (pointer)     : %p\n", d);
	printf("int **d의 값 d = &b 에서 *d (pointer)    : %p\n", *d);
	printf("int **d의 값 d = &b 에서 **d (integer)   : %d\n", **d);
	printf("int ***e의 값 e = &d 에서 e (pointer)    : %p\n", e);
	printf("int ***e의 값 e = &d 에서 *e (pointer)   : %p\n", *e);
	printf("int ***e의 값 e = &d 에서 **e (pointer)  : %p\n", **e);
	printf("int ***e의 값 e = &d 에서 ***e (integer) : %d\n", ***e);

	return 0;
}
