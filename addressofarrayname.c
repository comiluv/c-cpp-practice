/* 
https://modoocode.com/25
 */
#include <stdio.h>

int main()
{
	int arr[3] = {16, 22, 35};

	// 이것은 parr 라는 변수를 선언하는 것이다. (*parr)[3]라는 변수를 선언하는 것이 아님에 주의
	// 즉 (*parr)[n]에 3 대신 다른 값을 넣어 컴파일 해보면 int (*)[3]을 int (*)[other n]으로 initialize 할 수 없다고 나온다
	// cannot convert ‘int (*)[3]’ to ‘int (*)[other n]’ in initialization
	int(*parr)[3];
	parr = &arr;
	// parr라는 변수는 포인터이므로 POSIX상 동일한 크기를 갖게 된다
	printf("sizeof parr: %lu\n", sizeof(parr));
	printf("\n");

	// arr[n] = (*parr)[n] 임을 보인다
	printf("arr[1]     : %d\n", arr[1]);
	printf("(*parr)[1] : %d\n", (*parr)[1]);

	// 여기서 y[x] = *(y+x)이므로 (*parr)[n] = *((*parr) + n) 일까?
	printf("*(*parr+1) : %d\n", *((*parr) + 1));

	printf("&arr       : %p\n", &arr);
	// arr는 &array[0] 이다
	printf("arr        : %p\n", arr);
	// &arr[1] 은 &arr[0] 와 int 의 크기 만큼의 차이가 있다
	printf("&arr[1]    : %p\n", &arr[1]);
	// printf("&parr      : %p\n", &parr);
	printf("parr       : %p\n", parr);
	printf("parr[0]    : %p\n", parr[0]);
	// parr와 parr[0]이 같은 것을 볼 수 있는데 parr[0] = *(parr+0) = *parr인지 확인한다
	printf("*parr      : %p\n", *parr);
	// 그리고 가리키는 값은 항상 &arr[0]이다
	// 그럼 *(*parr)는 될까?
	printf("*(*parr)   : %d\n", *(*parr));
	// array[0]의 값이 나온다. 확인
	printf("arr[0]     : %d\n", arr[0]);

	printf("\n");
	printf("밑의 값들은 [] operator가 y[x] = *(y+x) 이기 때문에 표기 되는 것이지 실제론 엉뚱한 주소를 가리키고 있다\n");
	printf("parr[1]    : %p\n", parr[1]);
	printf("parr[2]    : %p\n", parr[2]);

	return 0;
}