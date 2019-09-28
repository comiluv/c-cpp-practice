/*
   struct 와 파일 입출력으로 사람목록 프로그램 만들기
   how people actually pronounce these cryptic function names
   http://computer-programming-forum.com/47-c-language/d09e6b7b9483a60c.htm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __PROGRAMSAVEFILENAME__ "humanlist.txt"

typedef struct 
{
	char name[50];
	char alias[50];
	char password[50];
	int age;
	int height;
	int weight;
	int gender;
	int onVacation;
} Human;
enum
{
	MALE,
	FEMALE
};

int return_human(Human *human_list);
int register_human(Human *human_list, int *nth);
int search_human(Human *human_list, int num_total_human);
int borrow_human(Human *human_list);
void flush_stdin(void);
unsigned char compare(char *a, char *b);
int print_human_list(Human *humanlist, int totalNumberHumans, char *output);
int load_human_list(Human **human_list, int *num_total_human);

int main(int argc, char **argv)
{
	unsigned char user_choice = 0;
	int num_total_human = 0;
	Human *human_list;
	printf("시작\n");
	for (user_choice = 0; user_choice < 1 || user_choice > 200;)
	{
		printf("사람 목록의 최대 보관 수를 설정해 주세요: ");
		scanf("%d", &user_choice);
		// user_choice = 2;
	}

	human_list = (Human *)malloc(sizeof(Human) * user_choice);
	// flush_stdin();

	// https://stackoverflow.com/questions/885908/while-1-vs-for-is-there-a-speed-difference
	for (user_choice = 0; user_choice != '8';)
	{
		for (user_choice = 0; user_choice < '1' || user_choice > '8';)
		{
			printf("사람 목록 프로그램\n");
			printf("현재 사람 목록 크기 : %d\n", num_total_human);
			printf("메뉴를 선택하세요\n");
			printf("1. 사람 하나 추가하기\n");
			printf("2. 사람 검색하기\n");
			printf("3. 사람 휴가보내기\n");
			printf("4. 사람 반납하기\n");
			printf("5. 사람 목록 전체 출력\n");
			printf("6. 사람 목록을 " __PROGRAMSAVEFILENAME__ "에서 입력\n");
			printf("7. 사람 목록을 " __PROGRAMSAVEFILENAME__ "에 출력\n");
			printf("8. 프로그램 종료\n");
			printf("당신의 선택은 : ");
			// why there is a space before %c
			// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
			scanf(" %c", &user_choice);
			// flush_stdin으로 남은 \n 처리
			flush_stdin();
		}

		switch (user_choice)
		{
		case '1':
			register_human(human_list, &num_total_human);
			break;
		case '2':
			search_human(human_list, num_total_human);
			break;
		case '3':
			borrow_human(human_list);
			break;
		case '4':
			return_human(human_list);
			break;
		case '5':
			print_human_list(human_list, num_total_human, "SCREEN");
			// 화면에 출력
			/* for (int i = 0; i < num_total_human; ++i)
			   {
			        Human *h = &human_list[i];
			        printf("번호 : %d\t", i);
			        printf("이름 : %s\t", h->name);
			        printf("별명 : %s\t", h->alias);
			        printf("나이 : %d\t", h->age);
			        printf("키 : %d\t", h->height);
			        printf("체중 : %d\t", h->weight);
			        printf("성별 %s\t", h->gender == MALE ? "남성" : "여성");
			        printf("%s\n", h->onVacation == 1 ? "휴가중" : "현업");
			   } */
			break;
		case '6':
			load_human_list(&human_list, &num_total_human);
			break;
		case '7':
			print_human_list(human_list, num_total_human, "FILE");
			break;
		case '8':
			break;
		}
	}
	free(human_list);
	return 0;
}

/* 사람을 추가하는 함수 */
int
register_human(Human *human_list, int *nth)
{
	Human *h = &human_list[*nth];
	printf("사람의 이름: ");
	// printf("%d", sizeof(h->name));
	fgets(h->name, sizeof(h->name), stdin);
	// printf("%s", h->name);
	// flush_stdin();
	printf("사람의 별명: ");
	fgets(h->alias, sizeof(h->alias), stdin);
	// printf("%s", h->alias);
	// flush_stdin();
	// https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c
	/* error: invalid conversion from ‘char’ to ‘const char*’ [-fpermissive]
	   h->name[strcspn(h->name,'\n')] = '\0'; */
	/* error: cannot convert ‘char (*)[50]’ to ‘const char*’ for argument ‘1’ to ‘size_t strcspn(const char*, const char*)’
	   h->name[strcspn(&h->name,'\n')] = '\0'; */
	// above errors are due to strcspn's second parameter should be string i.e "" not a single character i.e ''
	// https://beej.us/guide/bgc/html/multi/strspn.html
	h->name[strcspn(h->name, "\n")] = '\0';
	h->alias[strcspn(h->alias, "\n")] = '\0';
	printf("사람의 비밀번호: ");
	scanf("%s", h->password);
	printf("사람의 나이: ");
	scanf("%d", &h->age);
	printf("사람의 키: ");
	scanf("%d", &h->height);
	printf("사람의 체중: ");
	scanf("%d", &h->weight);
	printf("사람의 성별 (0:남 1:녀): ");
	scanf("%d", &h->gender);
	h->onVacation = 0;
	// *nth++; 가 아니라 (*nth)++;임에 유의
	// https://en.cppreference.com/w/c/language/operator_precedence
	// https://en.cppreference.com/w/cpp/language/operator_precedence
	(*nth)++;
	return 0;
}

/* 사람을 검색하는 함수 */
int
search_human(Human *human_list, int num_total_human)
{
	unsigned char user_input;
	int i;
	char user_search[30];
	// flush_stdin();
	do
	{
		printf("어느 것으로 검색할까요?\n");
		printf("1. 이름으로 검색\n");
		printf("2. 별명으로 검색\n");
		scanf(" %c", &user_input);
		flush_stdin();
	} while (user_input < '1' || user_input > '2');
	printf("검색할 단어를 입력해 주세요:");
	// scanf("%s", user_search);
	fgets(user_search, 30, stdin);
	user_search[strcspn(user_search, "\n")] = '\0';
	switch (user_input)
	{
	case '1':
		printf("검색 결과:\n");
		for (i = 0; i < num_total_human; ++i)
		{
			Human *h = &human_list[i];
			if (compare(h->name, user_search))
			{
				// 멋있는 \ 를 이용한 붙이기를 써먹는다
				// 멋있는 \ 를 이용한 붙이기는 preprocessor에서 쓰는것임 (eg. https://github.com/coreutils/coreutils/blob/master/src/cat.c)
				// 해서 printf("리터럴1""리터럴2"); 했다가 https://stackoverflow.com/questions/1752079/in-c-can-a-long-printf-statement-be-broken-up-into-multiple-lines
				// 에서 하지 말라고 해서 밑에처럼 씀
				printf("번호 : %d\t", i);
				printf("이름 : %s\t", h->name);
				printf("별명 : %s\t", h->alias);
				printf("나이 : %d\t", h->age);
				printf("키 : %d\t", h->height);
				printf("체중 : %d\t", h->weight);
				printf("성별 %s\t", h->gender == MALE ? "남성" : "여성");
				printf("%s\n", h->onVacation == 1 ? "휴가중" : "현업");
			}
		}
		break;
	case '2':
		printf("검색 결과:\n");
		for (i = 0; i < num_total_human; ++i)
		{
			Human *h = &human_list[i];
			if (compare(h->alias, user_search))
			{
				printf("번호 : %d\t", i);
				printf("이름 : %s\t", h->name);
				printf("별명 : %s\t", h->alias);
				printf("나이 : %d\t", h->age);
				printf("키 : %d\t", h->height);
				printf("체중 : %d\t", h->weight);
				printf("성별 %s\t", h->gender == MALE ? "남성" : "여성");
				printf("%s\n", h->onVacation == 1 ? "휴가중" : "현업");
			}
		}
		break;
	}
	return 0;
}

unsigned char
compare(char *a, char *b)
{
	// printf("\ncomparing %s and %s\n", a, b);
	while (*a)
	{
		if (*a != *b)
			return 0;
		a++;
		b++;
	}
	if ((*b) == '\0')
		return 1;
	return 0;
}

int
borrow_human(Human *human_list)
{
	int human_num;
	printf("휴가보낼 사람의 번호를 입력해 주세요 :");
	scanf("%d", &human_num);
	if (human_list[human_num].onVacation == 1)
	{
		printf("이미 휴가간 사람입니다!\n");
	}
	else
	{
		human_list[human_num].onVacation = 1;
		printf("휴가보냈습니다!\n");
	}
	return 0;
}

int
return_human(Human *human_list)
{
	int human_num;
	printf("복귀할 사람의 번호를 입력해 주세요 :");
	scanf("%d", &human_num);
	if (human_list[human_num].onVacation == 0)
	{
		printf("이미 복귀한 사람입니다!\n");
	}
	else
	{
		human_list[human_num].onVacation = 0;
		printf("휴가짤랐습니다!\n");
	}
	return 0;
}

void
flush_stdin(void)
{
	int a;
	do
	{
		a = getchar();
	} while (a != '\n' && a != '\0');
}

int
print_human_list(Human *humanlist, int totalNumberHumans, char* outputLoc)
{
	FILE *f;
	if (strcmp(outputLoc, "FILE") == 0)
	{
		f = fopen(__PROGRAMSAVEFILENAME__, "w+");
		if (f == NULL)
		{
			printf("출력 오류!");
			return -1;
		}
	}
	else if (strcmp(outputLoc, "SCREEN") == 0)
	{
		f = stdout;
	}
	fprintf(f, "%d\n", totalNumberHumans);
	fprintf(f, "이름\t별명\t비밀번호\t나이\t키\t체중\t성별\t휴가\n");
	int i;
	for (i = 0; i < totalNumberHumans; ++i)
	{
		Human *h = &humanlist[i];
		fprintf(f, "%s\t%s\t%s\t%d\t%d\t%d"
		        , h->name, h->alias, h->password, h->age, h->height, h->weight);
		fprintf(f, "\t%s", h->gender == 0 ? "MALE" : "FEMALE");
		fprintf(f, "\t%s\n", h->onVacation == 0 ? "WORK" : "ABSENT");
	}
	if (f != stdout)
	{
		fclose(f);
	}
}

/* 다른 함수에서 또다른 함수 내부에서 정의된 변수의 값을 바꾸기 위해서는 그 변수의 포인터를 인자로 전달해야 한다 
	위의 borrow_Human과의 차이점은 여기선 main 함수에서 선언한 타입 Human*인 human_list 자체를 free 할 것이라는게 차이점임
*/
int
load_human_list(Human **human_list, int *num_total_human)
{
	FILE *f = fopen(__PROGRAMSAVEFILENAME__, "r");
	if (f == NULL)
	{
		printf("파일을 열 수 없습니다\n");
		return -1;
	}
	int totalNum;
	int i;
	char str[10];
	int parseStart;

	fscanf(f, "%d", &totalNum);
	*num_total_human = totalNum;

	/* 기존의 human_list 삭제 */
	printf("기존의 human_list 삭제\n");
	free(*human_list);

	printf("malloc으로 재할당 %d\n", sizeof(Human) * totalNum);
	/* malloc으로 재할당 */
	*human_list = (Human*)malloc(sizeof(Human) * totalNum);

	if (*human_list == NULL)
	{
		printf("메모리 얼로케이션 에러!\n");
		return -1;
	}
	// 테이블 첫 row를 넘긴다
	char c = fgetc(f);
	// 다음줄 시작부터 '\n'까지 넘긴다
	while ((c = fgetc(f)) != '\n');
	// 현재 위치는 3번째 줄 시작부분임
	printf("현재 위치:%d\n", ftell(f));
	printf("파싱 시작\n");
	/* "이름/별명/비밀번호/나이/키/체중/성별/휴가\n"); */
	Human *h;
	for (i = 0; i < totalNum; ++i)
	{
		// fscanf로 입력할때 스트링(char*) 등을 제외한 integer 등은 memory of (&)로 받아야 함에 유의
		// h 라는 포인터로 (*human_list)[i] 의 주소를 가리킨다
		// 만약 h->property 로 하지 않는다면 (*h)[i].property같은
		h = &(*human_list)[i];
		fscanf(f, "%s", h->name);
		fscanf(f, "%s", h->alias);
		fscanf(f, "%s", h->password);
		fscanf(f, "%d", &h->age);
		fscanf(f, "%d", &h->height);
		fscanf(f, "%d", &h->weight);
		fscanf(f, "%s", str);
		if (strcmp(str, "MALE") == 0)
		{
			h->gender = 0;
		}
		else if (strcmp(str, "FEMALE") == 0)
		{
			h->gender = 1;
		}
		fscanf(f, "%s", str);
		if (strcmp(str, "WORK") == 0)
		{
			h->onVacation = 0;
		}
		else if (strcmp(str, "ABSENT") == 0)
		{
			h->onVacation = 1;
		}
	}
	fclose(f);
	return 0;
}