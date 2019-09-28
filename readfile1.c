/* 
fgets로 a.txt에서 입력을 받는다
 */
#include <stdio.h>

int main()
{
	FILE *fp = fopen("a.txt", "r");
	char buf[20];
	if (fp == NULL)
	{
		printf("Read error\n");
		return 1;
	}
	fgets(buf, 20, fp);
	printf("입력받은 내용 : %s\n", buf);
	fclose(fp);

	return 0;
}