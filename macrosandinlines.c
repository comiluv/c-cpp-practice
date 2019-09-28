/* 
매크로 함수
https://modoocode.com/99
 */
#include <stdio.h>
#define square(x) x *x
#define square2(x) (x) * (x)
#define PrintVariableName(var) printf(#var "\n");
#define getVariableNameAsString(v) (#v)
#define addName(x, y) ((x##y))
// 위에서 #define addName(x, y) ((x)##(y)) 하면 에러를 뿜어냄 : error: pasting ")" and "(" does not give a valid preprocessing token

// __inline int doubler(int x) { return x * 2; }
// this also works
inline int doubler(int x) { return x * 2; }
/* https://stackoverflow.com/questions/2765164/inline-vs-inline-vs-inline-vs-forceinline */

int main(int argc, char **argv)
{
	// 아래는 매크로에 의해 printf("square(3) : %d \n", 3 + 1 * 3 + 1);가 돼서 7이 나온다.
	printf("square(3) : %d \n", square(3 + 1));
	// 아래는 잘 나옴
	printf("square(3) : %d \n", square2(3 + 1));

	int a;
	PrintVariableName(a);

	int bababbb;
	printf("%s\n", getVariableNameAsString(bababbb));

	int addName(x, y);
	xy = 3;
	printf("%d\n", xy);

	printf("%d\n", doubler(100));
	return 0;
}