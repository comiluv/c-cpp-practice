/* stdin 버퍼 지우기
https://modoocode.com/32
 */
#include <stdio.h>
void clean_stdin(void);

int main(){
	int num;
	char c;
	printf("숫자를 입력하시오: ");
	scanf("%d",&num);
	// 아래 fflush 함수는 gcc에서 실행되지 않는다
	// fflush(stdin);
	clean_stdin();
	printf("문자를 입력하시오: ");
	scanf("%c",&c);
	printf("숫자 : %d, 문자 : %c\n",num,c);
}

// https://stackoverflow.com/questions/17318886/fflush-is-not-working-in-linux
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}