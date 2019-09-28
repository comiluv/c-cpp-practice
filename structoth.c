/* 
struct와 union, enum
https://modoocode.com/71
 */
#include <stdio.h>
struct AA
{
	int i;
	struct BB
	{
		int k;
	} b;
};

struct OBJ
{
	int x, y;
	char name[20];
} Ball;

struct FOO
{
	char *bar;
};

struct HUMAN
{
	int age, height, weight, gender;
};

struct AA structReturner(int j);

int printHuman(struct HUMAN h)
{
	if (h.gender == 0)
	{
		printf("MALE \n");
	}
	else
	{
		printf("FEMALE \n");
	}

	printf("AGE : %d / Height : %d / Weight : %d \n", h.age, h.height,
		   h.weight);

	if (h.gender == 0 && h.height >= 180)
	{
		printf("HE IS A WINNER!! \n");
	}
	else if (h.gender == 0 && h.height < 180)
	{
		printf("HE IS A LOSER!! \n");
	}

	printf("------------------------------------------- \n");

	return 0;
}

char copy_str(char *dst, const char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return 1;
}

int printObjectStatus(struct OBJ obj)
{
	printf("Location of %s\n", obj.name);
	printf("( %d , %d )\n", obj.x, obj.y);
	return 0;
}

int main()
{
	struct AA a;

	a = structReturner(10);
	printf("a.i: %d\n", a.i);

	Ball.x = 3;
	Ball.y = 4;
	copy_str(Ball.name, "Blue Ball");

	struct OBJ Dall = {10, 20, "Yellow Ball"};

	// below throws error {sorry, unimplemented: non-trivial designated initializers not supported}
	/* struct OBJ Eall = {y : 40, x : 30, name : "Green Ball"};
	struct OBJ Eall = {.y = 40, .x = 30, .name = "Green Ball"}; */

	// C99 designator ‘name’ outside aggregate initializer
	/* struct OBJ Eall = {.name = "Green Ball", .x = 30, .y = 40};
	struct OBJ Eall = {name : "Green Ball", x : 30, y : 40}; */

	// see this example
	// #include <stdio.h>
	// struct my_struct
	// {
	// 	const char *str;
	// };
	// int main()
	// {
	// 	struct my_struct s1;
	// 	s1.str = "string literal";
	// 	/* or */
	// 	struct my_struct s2 = {"string literal"};
	// 	printf("%s\n", s1.str);
	// }
	// which is from https://stackoverflow.com/questions/5071796/string-literal-inside-struct-c
	// and consider declaring string variable inside structs as char*s

	struct FOO foo = {bar : "FUS-RO-DAH"};  // or {.bar = "FUS-RO-DAH"};
	printf("%s\n", foo.bar);

	// changing order of struct to set name in the last in the order and initializing like this works
	struct OBJ Eall = {.x = 30, .y = 40};

	printObjectStatus(Ball);
	printObjectStatus(Dall);
	printObjectStatus(Eall);

	struct HUMAN Adam = {31, 182, 75, 0};
	struct HUMAN Eve = {27, 166, 48, 1};
	struct HUMAN Bdam = {25, 170, 64, 0};

	printHuman(Adam);
	printHuman(Eve);
	printHuman(Bdam);

	return 0;
}

struct AA structReturner(int j)
{
	struct AA a;
	a.i = j;

	return a;
}
