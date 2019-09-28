/* 
사용자로 부터 경로를 입력 받아서 그 곳에 파일을 생성하고 a 를 입력해놓는 프로그램을 만들어보세요
https://modoocode.com/117
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LOREMIPSUM "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.\n"

int main()
{
	FILE *userfile;
	char *userpath;
	
	printf("파일명을 포함한 경로를 입력하시요여.:");
	scanf("%s", userpath);

	userfile = fopen(userpath, "w");

	if (userfile == NULL)
	{
		printf("못만듬. 에러!\n");
		return 1;
	}

	fputs(LOREMIPSUM, userfile);

	fclose(userfile);

	return 0;
}