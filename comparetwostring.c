/* 문자열 두개를 비교
https://modoocode.com/29 */
#include <stdio.h>
int compareStr(const char *a, const char *b);
int lengthStr(const char *str);
int compare_str(char *a, char *b);

int main()
{
	char textA[] = {"abcsfawefawfaweffsafsfdf"};
	const char textB[] = {"abcsfawefawfaweffsdfsfdf"};

	char *ptrA = textA;
	const char *ptrB = textB;

	if (compareStr(textA, textB) == 1)
	{
		printf("Same text\n");
	}
	else
	{
		printf("Different text\n");
	}
}

// 이건 C 적인 감각이 아니야!
int compareStr(const char *a, const char *b)
{
	int alen = lengthStr(a);
	int blen = lengthStr(b);
	if (alen != blen)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < alen; i++)
		{
			if (a[i] != b[i])
			{
				return 0;
			}
		}
		return 1;
	}
}

int lengthStr(const char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

// 이게 바로 C적인 감각이지!
int compare_str(char *a, char *b)
{
	while (*a)
	{
		if (*a != *b)
		{
			return 1;
		}
		a++;
		b++;
	}
	if (*b == (char)NULL){
		return 0;
	}
	return 1;
}