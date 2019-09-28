/* 
한가지 수식만 계산하는 계산기
 */
#include <stdio.h>
#include <stdlib.h>

int atoi2(char *c)
{
	/* int i = 0;
	int totaldigit = 0;
	char *d = c;
	while (*d)
	{
		totaldigit++;
		d++;
	}
	while (*c)
	{
		int a = *c - 48;
		for (int j = 1; j < totaldigit; j++)
		{
			a *= 10;
		}
		i += a;
		c++;
		totaldigit--;
	}
	return i; */
	int i = 0;
	int num = 0;
	int multiplier = 1;
	while (c[i])
		i++;

	/* https://stackoverflow.com/questions/1812990/incrementing-in-c-when-to-use-x-or-x */
	while (--i > -1)
	{
		num += (c[i] - '0') * multiplier;
		multiplier *= 10;
	}
	return num;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printf("사용법: operand1 operator operand2\noperand에는 정수만 허용\n");
		return 1;
	}
	/* int로 타입캐스팅을 하면 cast from ‘char*’ to ‘int’ loses precision 에러가 나면서 컴파일이 안됨
	왜냐면 64비트에선 char*가 8바이트이고 int가 4바이트이기 때문임
	https://stackoverflow.com/questions/12417378/cast-from-char-to-int-loses-precision */

	int a = atoi(argv[1]);
	int b = (int)(*argv[2]);
	int c = atoi2(argv[3]);
	/* printf("operand1 : %d\n", a);
	printf("operator : %c\n", (char)b);
	printf("operand2 : %d\n", c); */
	int d;
	switch (b)
	{
	case (int)'+':
		d = a + c;
		break;
	case (int)'-':
		d = a - c;
		break;
	case (int)'*':
		d = a * c;
		break;
	case (int)'/':
		if (c == 0)
		{
			printf("division by zero\n");
			return 1;
		}
		d = a / c;
		break;
	default:
		printf("잘못된 입력\n");
		return 1;
		break;
	}
	printf("%d\n", d);
	return 0;
}