/* N진법에서 M진법으로 변환 */
#include <stdio.h>
#define CHAR_SET "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

int nextDigit(int *num, int *base, int *convbase);

int main()
{
	int numinbaseten =0;
	int num;
	int base;
	int convnum;
	int convbase;
	printf("숫자 입력 : ");
	scanf("%d", &num);
	printf("진법: ");
	scanf("%d", &base);
	printf("대상 진법(37진법까지): ");
	scanf("%d", &convbase);
	if (convbase > 37 || convbase < 2)
	{
		return 1;
	}
	printf("%d(%d) = ", num, base);
	convnum = num;
	nextDigit(&convnum, &base, &convbase);
	printf("(%d)(reversed)\n", convbase);
}



int nextDigit(int *num, int *base, int *convbase)
{
	int remainder = *num % *convbase;
	char remainderChar = CHAR_SET[remainder];
	printf("%c",remainderChar);
	*num /= *convbase;
	if(*num >= *convbase){
		nextDigit(num, base, convbase);
	} else
	{
		printf("%c",CHAR_SET[*num]);
	}	
}
