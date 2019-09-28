/* 문자열 입력을 받는다 */
#include <stdio.h>
int string_size(char *str);

int main()
{
	char txt[60];
	char *ptr = txt;
	printf("60자 미만의 문자열을 입력하세요\n: ");
	scanf("%s", txt);
		printf("%s\n", txt);

	return 0;
}

int string_size(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}