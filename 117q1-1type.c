/* 
도스용 type 명령어 모방 프로그램
https://github.com/coreutils/coreutils/blob/master/src/cat.c
 */
#include <stdio.h>
#include <string.h>
void printfile(FILE *file, int pause);

int main(int argc, char **argv)
{
	int filecount = 0;
	int printerror = 0;
	int pausepage = 0;
	FILE *userfile;
	int i;
	for (i = 1; i < argc; ++i)
	{
		char c = argv[i][0];
		// 옵션 처리
		if (c == '/')
		{
			// /p 옵션만 지원
			if (strcmp(argv[i], "/p") == 0)
			{
				pausepage++;
			}
			else
			{
				printerror++;
				break;
			}
		}
		else
		{
			// 파일명일 것임
			filecount++;
			if (filecount > 1)
			{
				printerror++;
				break;
			}
			else
			{
				userfile = fopen(argv[i], "r");
			}
		}
	}
	if (printerror != 0 || userfile == NULL)
	{
		if (userfile != NULL)
		{
			fclose(userfile);
		}
		else
		{
			printf("그런 파일 없음\n");
		}
		printf("사용법 : type 파일명 [/p]\n");
		return 1;
	}

	printfile(userfile, pausepage);
	fclose(userfile);
	return 0;
}

void printfile(FILE *file, int pause)
{
	char parser = fgetc(file);
	int lfcount = 1;
	while (parser != EOF)
	{
		if (parser == '\n')
			lfcount++;
		printf("%c", parser);
		if (lfcount % 30 == 0)
		{
			// 1억 줄 넘어가면 다시 리셋
			if (lfcount > 100000000)
			{
				lfcount = 0;
			}
			getchar();
		}
		parser = fgetc(file);
	}
}