/* 
reverse letter size eg. A -> a, z -> Z
https://modoocode.com/33
 */
#include <stdio.h>
int reverseLetter(char *word);

int main()
{
	char someword[100];

	printf("크기가 100 미만인 문자열 입력 알파벳만요\n:");
	scanf("%s", someword);
	printf("%s", someword);
	reverseLetter(someword);
	printf("변환 완료!\n");
	printf("%s\n", someword);
}

int reverseLetter(char *word)
{
	while (*word)
	{
		*word = *word < 0x5b ? *word + 0x20 : *word - 0x20;
		word++;
	}
}