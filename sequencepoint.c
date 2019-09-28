/*
   http://www.jiniya.net/wp/archives/2235
   https://stackoverflow.com/questions/39900469/undefined-behavior-in-c-c-i-i-vs-i-i
 */
#include <stdio.h>

int
main(int argc, char **argv)
{
	int a = 0;
	int b[10];
	int c = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 10;
	int m = 0;
	for (; k < 10; ++k)
	{
		b[k] = 0;
	}

	a = ++i + i++;
	b[j] = ++j;

	printf("a=%d\n", a);

	while (l--)
	{
		printf("b[%d]=%d\n", l, b[l]);
	}

	c = m++ + ++m;
	printf("c=%d\n", c);

	return 0;
}