/* 
구조체의 도입
https://modoocode.com/71
 */
#include <stdio.h>
int inputString(char *dest, char *src);
struct Human
{
	char name[20];
	int age;	// 나이
	int height; // 키
	int weight; // 몸무게
};				// ;를 붙여야함 ㅠㅠ

int main()
{
	struct Human you;

	int iamaboy;
	char tempname[20];
	
	// struct 내부 string이든 main string이든 포인터 만들 필요 없음

	printf("당신의 이름은 무엇입니까?\n:");
	scanf("%s", you.name);

	// inputString(you.name, tempname);
	you.age = 99;
	you.height = 300;
	you.weight = 500;

	printf("you에 관한 정보\n");
	printf("이름 : %s\n", you.name);
	printf("나이 : %d\n", you.age);
	printf("키  : %d\n", you.height);
	printf("몸무게: %d\n", you.weight);

	return 0;
}

int inputString(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}