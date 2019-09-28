#include <stdio.h>

int main()
{
	char sentence[26] = {"a very very long sentence"};
	char *str = sentence;

	printf("%s\n", str);

	return 0;
}