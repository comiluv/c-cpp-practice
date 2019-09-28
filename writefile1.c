/* 
a.txt에 내용 기록하기
https://modoocode.com/117
 */
#include <stdio.h>

int main(int argc, char **argv)
{
	FILE *fp;
	fp = fopen("a.txt", "w");

	if (fp == NULL)
	{
		printf("Write error!\n");
		return 1;
	}

	fputs("Hello World!\n", fp);
	fclose(fp);

	return 0;
}