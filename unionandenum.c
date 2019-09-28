/* 
공용체와 열거형
https://modoocode.com/71
 */
#include <stdio.h>
enum colorpalette
{
	RED = 1,   // set RED = 1
	BLUE,	  // BLUE is automatically 2
	WHITE, 		// if set WHITE to 1, then
	BLACK	  // BLACK is automatically 2
};
union A {
	int i;
	char j;
	short k;
};

/* 
https://en.wikipedia.org/wiki/Endianness
 */
int main()
{
	union A a;
	a.i = 0x12345678;
	//	              ~~
	printf("%x\n", a.j);
	printf("%x\n", a.k);

	int palette = BLACK;
	switch (palette)
	{
	case RED:
		printf("Palette is red, %d\n",RED);
		break;
	case BLUE:
		printf("Palette is blue, %d\n",BLUE);
		break;
	case WHITE:
		printf("Palette is white, %d\n",WHITE);
		break;
	case BLACK:
		printf("Palette is black, %d\n",BLACK);
		break;
	default:
		printf("unknown palette color definition\n");
		break;
	}
	printf("Palette is %d\n", palette);

	return 0;
}
