/* 
a.txt 에 어떠한 긴 글이 들어 있는데, 이 글을 입력 받아서 특정한 문자열을 검색하는 프로그램을 만들어보세요
 */

#include <stdio.h>
void scanTheFile(char *needle, FILE *haystack);

int main(int argc, char **argv)
{
	FILE *theFile;
	char needle[120];
	if (argc != 2)
	{
		printf("사용법: %s 파일명\n", argv[0]);
		return 1;
	}
	theFile = fopen(argv[1], "r");
	if (theFile == NULL)
	{
		printf("file not found\n");
		return 1;
	}

	printf("찾으려는 문자열을 입력하시요: ");
	// char needle[120] 즉 배열이므로 바로 scanf 때린다
	// 바로 char *needle 하고 scanf 때리면 안되는 이유
	// https://stackoverflow.com/questions/4900394/char-p-and-scanf
	scanf("%s", needle);
	printf("입력받은 값: %s\n", needle);

	scanTheFile(needle, theFile);

	fclose(theFile);

	return 0;
}

void scanTheFile(char *needle, FILE *haystack)
{
	int i, index = 1, found;
	char parser= fgetc(haystack);
	while ((parser ) != EOF)
	{
		if (parser == needle[0])
		{
			found = 1;
			for (i = 1; i < sizeof(needle) && needle[i] != '\0'; ++i)
			{
				parser = fgetc(haystack);
				// printf("\n여기까지는 실행됨 %d %c %c\n", index, parser, needle[i]);
				if (parser != needle[i])
				{
					found = 0;
					break;
				}
			}
			if (found == 0)
			{
				found = 1;
			}
			else
			{
				printf("i:%d ", index-1);
			}
			fseek(haystack, index, SEEK_SET);
		}
		index++;
		parser = fgetc(haystack);
	}
	printf("\n탐색 종료\n");
}