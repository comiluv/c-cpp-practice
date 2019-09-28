/* 
2차원 동적 할당 배열 연습
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getAverage(int **arr, int numStu, int numSubj)
{
	int i, j, sum, avg;
	for (i = 0; i < numStu; ++i)
	{
		sum = 0;
		for (j = 0; j < numSubj - 1; ++j)
		{
			sum += arr[i][j];
		}
		// 밑에서 에러가 난 이유는 여기서 index out of bound 가 났기 때문
		arr[i][numSubj-1] = sum / (numSubj-1);
		printf("학생 %d의 평균 점수 : %d\n", i + 1, arr[i][numSubj-1]);
	}
}

void printRank(int **arr, int numStu, int numSubj)
{
	int i, j, rank;
	for (i = 0; i < numStu; ++i)
	{
		rank = 1;
		for (j = 0; j < numStu; ++j)
		{
			if (arr[i][numSubj] < arr[j][numSubj])
				rank++;
		}
		printf("학생 %d의 등수 : %d\n", i + 1, rank);
	}
}

int randInt(int min, int maxv)
{
	float r = (float)rand() / (float)RAND_MAX * (float)maxv;
	return min + (int)r;
}

int main(int argc, char **argv)
{
	/* https://stackoverflow.com/questions/29031373/is-there-a-command-that-tells-the-compiler-to-print-its-version */
#ifdef __clang_major__
	printf("clang detected version %d.%d\n", __clang_major__, __clang_minor__);
#endif
#ifdef __GNUC__
	// note that clang 3.7 declares itself as a gcc 4.2"
	printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif
	/* https://stackoverflow.com/questions/8666378/detect-windows-or-linux-in-c-c */
#ifdef __unix__
	printf("This was built using linux!\n");
#endif
#ifdef _WIN32
	printf("This was built using win32!\n");
#endif
#ifdef _WIN64
	printf("This was built using win64!\n");
#endif
	/* if (argc != 4)
	{
		printf("Usage : [학생 수] [과목 수] [최대점수]\n");
		return 1;
	} */
	srand(time(NULL));
	int i, j, input, sum = 0;
	/* int subject = atoi(argv[2]) + 1;
	int students = atoi(argv[1]);
	int maxscore = atoi(argv[3]); */
	int subject = 6;
	int students = 5;
	int maxscore = 100;
	int **arr;

	printf("학생 수: %d // 과목 수: %d\n", students, subject - 1);

	arr = (int **)malloc(sizeof(int *) * students);
	for (i = 0; i < students; ++i)
	{
		arr[i] = (int *)malloc(sizeof(int) * subject);
	}
	for (i = 0; i < students; ++i)
	{
		printf("학생 %d 의 점수 ------------\n", i + 1);
		for (j = 0; j < subject - 1; ++j)
		{
			// scanf("%d", &input);
			input = randInt(0, maxscore);
			printf("과목 %d 점수 입력 : %d\n", j + 1, input);
			arr[i][j] = input;
		}
	}

	getAverage(arr, students, subject);
	//printRank(arr, students, subject);

	for (i = 0; i < students; i++)
	{
		/* 여기서 5x5 배열로 만든 경우 C error: munmap_chunk(): invalid pointer 가 발생함
		이상하게 2x2나 3x3에서는 발생 안하고 5x5 외에도 다른 경우에도 가끔 발생함 */
		printf("freeing index student %d\n", i);
		free(arr[i]);
	}
	free(arr);

	return 1;
}
