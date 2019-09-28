/*
   구조체 포인터
   Q1 and Q2
 */
#include <stdio.h>
void flushinput(void);

struct DD
{
	int f,g;
};

struct test
{
	int a, b;
	// https://stackoverflow.com/questions/6287479/how-to-use-a-struct-inside-another-struct
	struct CC{
		int d,e;
	};
	// CC와 DD는 vscode extension에서 에러로 나옴 (identifier is undefined) 하지만 컴파일은 잘됨
	CC test2;
	DD test3;
	struct EE{
		int h,i;
	}test4;
	struct DD test5;
	struct CC test6;
};

int main()
{
	struct test asdf;
	struct test *ptr;
	// char keypressed;

	ptr = &asdf;
	while (1)
	{
		(*ptr).a = 5;
		(*ptr).b = 6;
		(*ptr).test2.d = 7;
		(*ptr).test2.e = 8;
		(*ptr).test3.f = 9;
		(*ptr).test3.g = 10;
		(*ptr).test4.h = 11;
		(*ptr).test4.i = 12;
		(*ptr).test5.f = 13;
		(*ptr).test5.g = 14;
		(*ptr).test6.d = 15;
		(*ptr).test6.e = 16;

		printf("asdf 의 a멤버 : %d\n", asdf.a);
		printf("asdf 의 b멤버 : %d\n", asdf.b);
		printf("asdf 의 C struct인 test2의 d : %d\n", asdf.test2.d);
		printf("asdf 의 C struct인 test2의 e : %d\n", asdf.test2.e);
		printf("asdf 의 D struct인 test3의 f : %d\n", asdf.test3.f);
		printf("asdf 의 D struct인 test3의 g : %d\n", asdf.test3.g);
		printf("asdf 의 E struct인 test4의 h : %d\n", asdf.test4.h);
		printf("asdf 의 E struct인 test4의 i : %d\n", asdf.test4.i);
		printf("asdf 의 D struct인 test5의 f : %d\n", asdf.test5.f);
		printf("asdf 의 D struct인 test5의 g : %d\n", asdf.test5.g);
		printf("asdf 의 C struct인 test6의 d : %d\n", asdf.test6.d);
		printf("asdf 의 C struct인 test6의 e : %d\n", asdf.test6.e);

		// press enter to continue
		while (getchar() != '\n');
		ptr->a = 11;
		ptr->b = 12;
		ptr->test2.d = 13;
		ptr->test2.e = 14;
		ptr->test3.f = 15;
		ptr->test3.g = 16;
		ptr->test4.h = 17;
		ptr->test4.i = 18;
		ptr->test5.f = 19;
		ptr->test5.g = 20;
		ptr->test6.d = 21;
		ptr->test6.e = 22;

		printf("asdf 의 a멤버 : %d\n", asdf.a);
		printf("asdf 의 b멤버 : %d\n", asdf.b);
		printf("asdf 의 C struct인 test2의 d : %d\n", asdf.test2.d);
		printf("asdf 의 C struct인 test2의 e : %d\n", asdf.test2.e);
		printf("asdf 의 D struct인 test3의 f : %d\n", asdf.test3.f);
		printf("asdf 의 D struct인 test3의 g : %d\n", asdf.test3.g);
		printf("asdf 의 E struct인 test4의 h : %d\n", asdf.test4.h);
		printf("asdf 의 E struct인 test4의 i : %d\n", asdf.test4.i);
		printf("asdf 의 D struct인 test5의 f : %d\n", asdf.test5.f);
		printf("asdf 의 D struct인 test5의 g : %d\n", asdf.test5.g);
		printf("asdf 의 C struct인 test6의 d : %d\n", asdf.test6.d);
		printf("asdf 의 C struct인 test6의 e : %d\n", asdf.test6.e);
		// press enter to continue
		while (getchar() != '\n');
	}
	return 0;
}

void flushinput(void)
{
	int a;
	do
	{
		a = getchar();
	} while (a != '\n' && a != EOF);
}
