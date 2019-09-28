/*
   N진법에서 M진법으로 변환
 */
#include <stdio.h>
#include <string.h>

// 수 참조 표 마지막의 a는 36진법 사용시 z를 valid input으로 다루기 위한 것
static const unsigned char digitTable[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZa";

int checkInputVal(unsigned char *s, unsigned char inputBase);
unsigned char charToNum(unsigned char c);
void toUpperCase(unsigned char *s);
unsigned int convToBaseTen(unsigned char *iVal, unsigned char input_base);
unsigned char numToChar(unsigned int i);
int convFromBaseTen(unsigned char *dVal, unsigned int iVal, unsigned char dBase);
void flush_stdin(void);

int
main(int argc, char** argv)
{
	// 1kb씩 할당한다
	unsigned char input_val[1024];
	unsigned char input_base;
	unsigned char dest_base = 0;
	unsigned int input_base_ten;
	unsigned char dest_val[1024];

	printf("진법 변환은 2에서 36진법까지\n");
	printf("입력 숫자는 최대 9자리까지만 가능\n");

	do
	{
		input_base = 0;
		printf("몇 진법의 수? : ");
		// 입력받을 수의 진법을 unsigned int 형태로 받는다
		scanf("%3u", &input_base);
		// 받고 난 다음의 문자를 전부 제거한다
		flush_stdin();
	} while (input_base < 2 || input_base > 36);

	do
	{
		printf("수 입력 : ");
		scanf("%s", input_val);
		toUpperCase(input_val);
	} while (strlen((char*)input_val) > 9 || checkInputVal(input_val, input_base) != 0);

	do
	{
		printf("변환하고자 하는 대상 진법은? : ");
		scanf("%3u", &dest_base);
		// 받고 난 다음의 문자를 전부 제거한다
		flush_stdin();
	} while ( dest_base < 2 || dest_base > 37);

	// 일단 10진법으로 변환
	input_base_ten = convToBaseTen(input_val, input_base);
	printf("10진법으로 : %u\n", input_base_ten);
	// 10진법에서 목표 진법으로 변환
	convFromBaseTen(dest_val, input_base_ten, dest_base);
	// 결과 출력
	printf("%u진법으로 : %s\n", dest_base, dest_val);

	return 0;
}

/**
 * 10진법의 수인 unsigned int iVal과 변경 대상의 진법인 unsigned char dBase를 파라메터로 받아
 * 역시 파라메터로 받은 문자열인 unsigned char* dVal에 포인터를 사용해 표시한다
 */
int
convFromBaseTen(unsigned char* dVal, unsigned int iVal, unsigned char dBase)
{
	unsigned int temp;
	unsigned char temp_string[1024];
	unsigned int index = 0;
	// 입력값을 목표 진법으로 나눈 나머지를 임시 string에 순서대로 저장한다
	while (iVal)
	{
		temp = iVal % dBase;
		temp_string[index] = numToChar(temp);
		iVal /= dBase;
		index++;
	}
	// 임시 string 뒤집기
	while (index)
	{
		*dVal = temp_string[--index];
		dVal++;
	}
	// null 문자 추가
	*dVal = '\0';
	return 0;
}

/**
 * 문자열로 된 숫자인 unsigned char* iVal과 해당 수의 표기된 진법인 unsigned char input_base를 파라메터로
 * 10진법으로 변환 뒤 10진법으로 변환된 값을 unsigned int로 리턴한다
 */
unsigned int
convToBaseTen(unsigned char* iVal, unsigned char input_base)
{
	unsigned int baseTen = 0;
	unsigned char counter = 0;
	unsigned int powerOfTen = 1;
	while (*iVal)
	{
		iVal++;
		counter++;
	}

	// 여기서 *iVal == '\0'이고 역순으로 계산한다
	while (counter--)
	{
		baseTen += charToNum(*(--iVal)) * powerOfTen;
		powerOfTen *= input_base;
	}
	return baseTen;
}

/**
 * 문자열 s를 파라메터로 받아 처음부터 끝까지 탐색해
 * 포인터를 사용해 소문자인 경우 대문자로 변경한다
 */
void
toUpperCase(unsigned char* s)
{
	printf("대문자변환 시작\n");
	while (*s)
	{
		// ASCII 테이블에서 0x60~0x7B인 소문자인 경우 0x20 빼면 대문자가 됨
		if (*s > 0x60 && *s < 0x7B)
			*s -= 0x20;
		s++;
	}
}

/**
 * 파라메터 unsigned int i를 참조해 문자를 리턴한다
 * 즉 i == 12일 경우 'C'를 리턴한다
 */
unsigned char
numToChar(unsigned int i)
{
	return digitTable[i];
}

/**
 * 파라메터 unsigned char c를 참조해 수를 리턴한다
 * 즉 c == 'C'일 경우 12를 리턴한다
 */
unsigned char
charToNum(unsigned char c)
{
	for (int i = 0; digitTable[i]; ++i)
		if (digitTable[i] == c)
			return i;
}

/**
 * 파라메터 char* s와 진법을 가리키는 inputBase를 통해 digitTable을 참조해
 * 올바른 입력이면 0, 아니면 1을 리턴한다
 */
int
checkInputVal(unsigned char* s, unsigned char inputBase)
{
	printf("숫자 오류 확인 시작\n");
	while (*s)
	{

		// 0x30인 0보다 작거나 0x39인 9부터 0x41인 A사이거나 0x5A인 Z부터 0x61인 a사이거나 0x7A인 z보다 큰 경우, 즉
		//    0~9이거나 A~Z또는 a~z가 아닌 경우
		if (*s < 0x30 || (*s > 0x39 && *s < 0x41) || (*s > 0x5A && *s < 0x61) || *s > 0x7A)
		{
			printf("'%c' : 잘못된 문자가 입력됐습니다\n", *s);
			return 1;
		}

		// 입력값을 인덱스로 하는 digitTable의 값이 n진법을 가리키는 inputBase를 인덱스로 하는 digitTable의 값보다
		// 크거나 같으면 잘못된 입력임 (eg 8진법인데 8이 들어가면 안됨)
		if (*s >= digitTable[inputBase])
		{
			printf("진법 허용 범위를 초과한 입력입니다\n");
			return 1;
		}
		s++;
	}
	return 0;
}

/**
 * stdin 스트림을 null 문자나 new line 문자가 나올때까지 비우고 동시에
 * null 문자와 new line 문자도 제거한다
 */
void
flush_stdin(void)
{
	char c;
	do {
		c = getchar();
	} while (c != '\0' && c != '\n' && !feof(stdin));
}