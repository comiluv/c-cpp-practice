/* human.c */
#include <stdio.h>
#include "str.h"
#include "human.h"

struct Human Create_Human(char *name, int age, int gender)
{
	struct Human human;

	human.age = age;
	human.gender = gender;
	copy_str(human.name, name);

	return human;
}
int Print_Human(struct Human *human)
{
	printf("Name : %s \n", human->name);
	printf("Age : %d \n", human->age);
	if (human->gender == MALE)
	{
		printf("Gender : Male \n");
	}
	else if (human->gender == FEMALE)
	{
		printf("Gender : Female \n");
	}

	return 0;
}