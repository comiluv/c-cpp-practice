/* 
길이가 최대 100 인 문자열을 하나 입력 받아서 문자열을 역순으로 출력하는 함수
https://modoocode.com/33
 */
#include <stdio.h>
int reverseStr(char *a);

int main()
{
	char userinput[100];
	printf("길이가 최대 100인 문자열 띄어쓰기 금지\n:");
	scanf("%s", userinput);
	reverseStr(userinput);
	return 0;
}

int reverseStr(char *a)
{
	while (*a)
	{
		a++;
	}
	do
	{
		a--;
		printf("%c", *a);
	} while (*a);
	printf("\n");
}