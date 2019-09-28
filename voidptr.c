/* 
포인터 p로부터 byte만큼 읽기
메인 함수의 인자
https://modoocode.com/89
 */
#include <stdio.h>
void read_char(void *p, int byte)
{
	do
	{
		printf("%x\n", *(char *)p);
		byte--;
		p = (char *)p + 1;
	} while (p && byte);
}

int main(int argc, char **argv)
{
	int arr[1] = {0x12345678};

	printf("%x\n", arr[0]);
	read_char(arr, sizeof(arr));

	printf("받은 인자의 갯수 : %d\n", argc);
	printf("이 프로그램의 경로: %s\n", argv[0]);
	for (int i = 0; i < argc; i++)
	{
		printf("인자 %d : %s\n", i + 1, argv[i]);
	}

	return 0;
}