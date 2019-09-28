/*
학생 성적 및 등수 출력 with struct
*/
#include <stdio.h>
#include <stdlib.h>
struct Student
{
	int *scores;
	int avg;
};
void getAverage(struct Student *arr, int numStu, int numSubj);
void printRank(struct Student *arr, int numStu, int numSubj);

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Usage : [학생 수] [과목 수]\n");
		return 1;
	}
	struct Student *stus;

	int i, j, input, sum = 0;

	int subject = atoi(argv[2]);
	int students = atoi(argv[1]);
	/* int maxscore = 100;
	int subject = 5;
	int students = 5; */

	printf("학생 수: %d // 과목 수: %d\n", students, subject - 1);

	stus = (struct Student *)malloc(sizeof(struct Student) * students);
	for (i = 0; i < students; ++i)
	{
		(&stus[i])->scores = (int *)malloc(sizeof(int) * subject);
	}
	for (i = 0; i < students; ++i)
	{
		printf("학생 %d 의 점수 ------------\n", i + 1);
		for (j = 0; j < subject; ++j)
		{
			struct Student *A;
			A = &stus[i];
			printf("과목 %d 점수 입력 : ", j + 1);
			scanf("%d", &input);
			A->scores[j] = input;			
		}
	}
	getAverage(stus, students, subject);
	printRank(stus, students, subject);

	for (i = 0; i < students; i++)
	{
		free(stus[i].scores);
	}
	free(stus);

	return 1;
}

void getAverage(struct Student *arr, int numStu, int numSubj)
{
	int i, j, sum, avg;
	for (i = 0; i < numStu; ++i)
	{
		sum = 0;
		for (j = 0; j < numSubj; ++j)
		{
			sum += arr[i].scores[j];
		}
		arr[i].avg = sum / numSubj;
		printf("학생 %d의 평균 점수 : %d\n", i + 1, arr[i].avg);
	}
}

void printRank(struct Student *arr, int numStu, int numSubj)
{
	int i, j, rank;
	for (i = 0; i < numStu; ++i)
	{
		rank = 1;
		for (j = 0; j < numStu; ++j)
		{
			if (arr[i].avg < arr[j].avg)
				rank++;
		}
		printf("학생 %d의 등수 : %d\n", i + 1, rank);
	}
}
