/* int findstrindex(str, substr)
str에서 substr의 첫 index를 리턴한다 못찾으면 관례상 -1
https://modoocode.com/33
 */
#include <stdio.h>
int findstrindex(char *str, char *substr);

int main()
{
	char str[100];
	char substr[100];
	printf("원본 스트링 스페이스 안됨ㅇ ㅏ직 못배움\n:");
	scanf("%s", str);
	printf("찾고싶은 서브스트링 스페이스 안댐 알지?\n:");
	scanf("%s", substr);
	/* 	char str[100] = {"I_am_a_boy"};
	char substr[100] = {"am"}; */
	printf("%d\n", findstrindex(str, substr));
}

int findstrindex(char *str, char *substr)
{
	int index = 0;
	char *strPos = str;
	char *substrPos = substr;
	while (*str)
	{
		if (*str == *substr)
		{
			while (*substr)
			{
				if (*str != *substr)
				{
					substr = substrPos;
					break;
				}
				str++;
				substr++;
				if (*substr == (char)NULL)
				{
					return index;
				}
			}
			str = strPos;
		}
		str++;
		index++;
		strPos++;
	}
	return -1;
}