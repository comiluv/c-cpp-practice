/* 
구조체를 arguments로
warning 없애려면 char *charname 대신 const char *charname
 */
#include <stdio.h>
struct TEST
{
	int age, gender;
	char name[20];
};

int copy_str(char *dst,  char *src);
int set_human(struct TEST *a, int age, int gender,  char *name);

int main()
{
	struct TEST human;
	set_human(&human, 10, 1, "Kim");
	printf("Name: %s // Age: %d // Gender: %d\n", human.name, human.age, human.gender);
	return 0;
}

int set_human(struct TEST *a, int age, int gender,  char *name)
{
	a->age = age;
	a->gender = gender;
	copy_str(a->name, name);
	return 0;
}

int copy_str(char *dst,  char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
}