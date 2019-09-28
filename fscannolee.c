/* 
파일에서 this와 that을 교환하기
 */

#include <stdio.h>
#include <string.h>

void printFile(FILE *f)
{
	char c;
	fseek(f, 0, SEEK_SET);
	while ((c = fgetc(f)) != EOF)
	{
		printf("%c", c);
	}
	fseek(f, 0, SEEK_SET);
}

int main(int argc, char **argv)
{
	FILE *fp = fopen("this_data.txt", "r+");
	char data[200];

	if (fp == NULL)
	{
		printf("파일 읽기 오류!\n");
		return 1;
	}
	printFile(fp);

	while (fscanf(fp, "%s", data) != EOF)
	{
		if (strcmp(data, "this") == 0)
		{
			fseek(fp, -(long)strlen("this"), SEEK_CUR);
			fputs("that", fp);
			fflush(fp);
		}
		if (strcmp(data, "that") == 0)
		{
			fseek(fp, -(long)strlen("that"), SEEK_CUR);
			fputs("this", fp);
			fflush(fp);
		}
	}
	fclose(fp);

	return 0;
}