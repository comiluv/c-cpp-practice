/* 
한글자씩 파일 읽기
 */
#include <stdio.h>

int main()
{
	FILE *fp = fopen("a.txt", "r");
	if (fp == NULL)
	{
		printf("read error!\n");
		return 1;
	}
	int size = 0;
	char c;

	while ((c = fgetc(fp)) != EOF)
	{
		size++;
		printf("%c", c);
	}

	// 다시 처음부터 읽기
	fseek(fp, 0, SEEK_SET);
	// 공백 문자까지
	while ((c = fgetc(fp)) != ' ')
	{
		printf("%c\n", c);
	}

	fclose(fp);
	printf("이 파일의 크기는 : %d bytes\n", size);

	return 0;
}