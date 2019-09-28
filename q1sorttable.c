/* 5명의 수학 국어 영어 점수 입력 후 평균으로 정렬, 평균 이상은 합격 아니면 불합격 */
#include <stdio.h>
int receiveScore(int studentNumber, int subjectNumber);
int swapArr(int (*parr)[4], int indexA, int indexB);
int sortArray(int (*parr)[4], int startIndex, int repIndex);
int printScore(int (*parr)[4], int numStu, int totalAvg);

int main()
{
	int scores[5][4] = {0};
	int average;
	int totalavg = 0;
	int i, j = 0;
	for (i = 0; i < 5; i++)
	{
		scores[i][3] = 0;
		for (j = 0; j < 3; j++)
		{
			scores[i][j] = receiveScore(i, j);
			scores[i][3] += scores[i][j];
		}
		totalavg += (scores[i][3] /= 3);
		printf("평균 점수 : %d\n", scores[i][3]);
	}
	totalavg /= 5;
	printf("평균 : %d\n", totalavg);

	printf("정렬 시작\n");
	sortArray(scores, 0, 3);
	printf("정렬 끝\n");

	for (i = 0; i < 5; i++)
	{
		printScore(scores, i, totalavg);
	}
}

int printScore(int (*parr)[4], int numStu, int totalAvg)
{
	int i = numStu;
	printf("학생 %d { ", i + 1);
	for (int j = 0; j < 4; j++)
	{
		switch (j)
		{
		case 0:
			printf("수학 :");
			break;
		case 1:
			printf("국어 :");
			break;
		case 2:
			printf("영어 :");
			break;
		case 3:
			printf("} 평균 :");
			break;
		}
		printf("%d ", parr[i][j]);
	}
	if (parr[i][3] >= totalAvg)
	{
		printf("합격\n");
	}
	else
	{
		printf("불합격\n");
	}
}

int sortArray(int (*parr)[4], int startIndex, int repIndex)
{
	int maxscoreIndex = startIndex;
	for (int i = startIndex+1; i < 5; i++)
	{
		if (parr[maxscoreIndex][repIndex] < parr[i][repIndex])
		{
			maxscoreIndex = i;
		}
	}
	swapArr(parr, maxscoreIndex, startIndex);
	if (startIndex < 5)
	{
		sortArray(parr, startIndex + 1, repIndex);
	}
}

int swapArr(int (*parr)[4], int indexA, int indexB)
{
	int tempVal;
	for (int i = 0; i < 4; i++)
	{
		tempVal = parr[indexA][i];
		parr[indexA][i] = parr[indexB][i];
		parr[indexB][i] = tempVal;
	}
}

int receiveScore(int studentNumber, int subjectNumber)
{
	int score = 0;
	printf("%d번 학생의 ", studentNumber + 1);
	switch (subjectNumber)
	{
	case 0:
		printf("수학 ");
		break;
	case 1:
		printf("국어 ");
		break;
	case 2:
		printf("영어 ");
		break;
	}
	printf("점수 : ");
	scanf("%d", &score);
	return score;
}