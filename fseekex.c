/* 
fopen, fscanf 등등
https://modoocode.com/123
 */
/*

쓰기 - 읽기 모드 전환을 위해서는 무조건
fseek 함수와 같은 파일 위치 지정자 설정 함수들을
호출해야 한다.

*/
#include <stdio.h>
#include <stdlib.h>
void flipCapital(FILE *f);
void clean_stdin(void);

int main()
{
	// declare as an array
	FILE **filearray; // or FILE *filearray[2];

	int numberOfFiles = 2;

	filearray = (FILE **)malloc(numberOfFiles * sizeof(FILE *));

	printf("used super-cool dynamic array of files\n");

	// use it like an array
	filearray[0] = fopen("some_data.txt", "a+");
	filearray[1] = fopen("loremipsum.txt", "r+");

	// these are supposed to be pointers
	FILE *fp = filearray[0];
	FILE *fp2 = filearray[1];
	char data[100];
	char c;

	if (fp == NULL || fp2 == NULL)
	{
		printf("file open error!\n");
		return 0;
	}

	fgets(data, 100, fp);
	printf("현재 파일에 있는 내용 : %s\n", data);
	c = fgetc(fp);
	printf("그 다음에 입력받은 문자 : %c\n", c);

	fseek(fp, -1, SEEK_CUR);

	c = fgetc(fp);
	printf("그렇다면 무슨 문자가? : %c\n", c);

	fseek(fp, -2, SEEK_END);
	c = fgetc(fp);
	printf("마지막 파일의 문자 : %c\n", c);

	fseek(fp, 5, SEEK_SET);
	// fputs("is nothing on this file", fp);

	char t;
	while ((t = fgetc(fp2)) != EOF)
	{
		printf("%c", t);
	}
	printf("\n");

	// flipCapital(fp);
	fseek(fp, 0, SEEK_END);
	fputs("is ADDED HAHHAHAAAAHAH", fp);
	fseek(fp, 0, SEEK_SET);
	while (fscanf(fp, "%s", data) != EOF)
	{
		printf("%s\n", data);
	}

	flipCapital(fp2);

	fclose(fp);
	fclose(fp2);
	free(filearray);
	return 0;
}

void flipCapital(FILE *f)
{
	// printf("processing\n");
	fseek(f, 0, SEEK_SET);
	char c;
	int charcounter = 0;
	while ((c = fgetc(f)) != EOF)
	{
		// printf("%d ",charcounter);
		// 대문자인 경우
		if (c >= 65 && c <= 90)
		{
			// 한칸 뒤
			fseek(f, -1, SEEK_CUR);
			// 소문자로 바꿈
			fputc(c + 32, f);
			/*

				쓰기 - 읽기 모드 전환을 위해서는 무조건
				fseek 함수와 같은 파일 위치 지정자 설정 함수들을
				호출해야 한다. fflush, rewind etc.

			*/
			// fseek(f, 0, SEEK_CUR);
			fflush(f);
		}
		else if (c >= 97 && c <= 122)
		{
			fseek(f, -1, SEEK_CUR);
			fputc(c - 32, f);
			fseek(f, 0, SEEK_CUR);
			// fflush(f);
			// rewind(f); // doesn't work
		}
		charcounter++;
	}
}

// this doesn't work, it works for scanf but not in this scenario
void clean_stdin(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}