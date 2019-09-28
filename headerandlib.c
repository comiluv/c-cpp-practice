/* 
라이브러리의 사용
 */
#include <stdio.h>
#include <string.h>
#define VAR 10

int main()
{
	char str1[20] = {"hi"};
	char str2[20] = {"hello every1"};
	char str3[20] = {"hi"};
	char arr[VAR] = {"hi"};

	printf("%s\n",arr);

	if (!strcmp(str1, str2))
	{
		printf("%s and %s is equal\n", str1, str2);
	}
	else
	{
		printf("%s and %s is NOT equal\n", str1, str2);
	}

	if (!strcmp(str1, str3))
	{
		printf("%s and %s is equal\n", str1, str3);
	}
	else
	{
		printf("%s and %s is NOT equal\n", str1, str3);
	}

	return 0;
}