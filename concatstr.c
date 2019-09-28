/* 
문자열 합치기
https://modoocode.com/33
 */
#include <stdio.h>
int concat_str(char *a, char *b);

int main()
{
	char hello[100] = {"hello "};
	char hi[] = {"hi"};
	concat_str(hello, hi);
	printf("%s\n", hello);
}

int concat_str(char *a, char *b)
{
	while (*a)
	{
		printf("%c\n", *a);
		a++;
	}
	while (*b)
	{
		printf("%c\n", *b);
		*a = *b;
		a++;
		b++;
	}

	// NULL 추가
	*a = (char)NULL;
}
