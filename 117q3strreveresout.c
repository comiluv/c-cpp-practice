/* 
a.txt 에 문자열을 입력 받아서 b.txt 에 그 문자열을 역으로 출력하는 프로그램을 만들어보세요
 */
#include <stdio.h>
int getFileSize(FILE *file);
void rcopyFileOP(FILE *dst, FILE *src);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("사용법 : %s source_filename dest_filename\n", argv[0]);
		return 1;
	}
	FILE *dstFile = fopen(argv[2], "w+");
	FILE *srcFile = fopen(argv[1], "r");
	if (dstFile == NULL || srcFile == NULL)
	{
		printf("진행 못함\n");
		return 1;
	}

	rcopyFileOP(dstFile, srcFile);

	printf("끝.\n");
	fclose(dstFile);
	fclose(srcFile);
	return 0;
}

void rcopyFileOP(FILE *dst, FILE *src)
{
	int i = 1;
	int i2 = 1;
	int j = ++i;
	int j2 = i2++;
	printf("j:%d   j2:%d\n",j,j2);

	char p;
	int srcSize = getFileSize(src);
	int index = 0;
	while (srcSize-- > 0) 
	{
		fseek(src, srcSize, SEEK_SET);
		p = fgetc(src);
		printf(" %d:%d",srcSize,p);
		// index++;
		fputc(p, dst);
	}
	// fputc(0xA, dst); // ascii 0xA == line feed;
}

int getFileSize(FILE *file)
{
	int counter = 0;
	char p;
	while ((p = fgetc(file)) != EOF)
	{
		counter++;
		printf(" %d:%d",counter, p);
	}
	// 가장 마지막에 LF(아스키 코드 10)이 붙음
	printf("길이:%d\n",counter);
	return counter;
}