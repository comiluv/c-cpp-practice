/* 
typedef, volatile, pragma 키워드
https://modoocode.com/103
 */
#include <stdio.h>
/* 전처리기 명령에는 ; 를 붙이지 않는다! */
// #pragma pack(1) <- MS compiler에서만 유용. 기본값 : 4

#ifndef WEIRD_H // <- 이렇게 하면 헤더를 두번 불러도 재정의 오류 안 생김
#define WEIRD_H
typedef struct WEIRD
{
	char arr[2];
	int i;
}WEIRD;
#endif
// 아니면 위에서 그냥 #pragma once 라고 해도 됨 (MS 컴파일러에서는)
// gcc에서도 되는 듯 https://en.wikipedia.org/wiki/Pragma_once


struct HUMAN
{
	int age;
	int height;
	int weight;
	int gender;
};
typedef int CAL_TYPO;
typedef struct HUMAN Human;
int Print_Status(Human human);

typedef struct SENSOR
{
	/* 감지 안되면 0, 감지되면 1 이다.*/
	int sensor_flag;
	int data;
} SENSOR;

int main()
{
	CAL_TYPO a = 1;
	Human Adam = {31, 182, 75, 0};
	Human Eve = {27, 166, 48, 1};
	SENSOR SomeSensorFromHardware;
	volatile SENSOR *sensor;
	sensor = &SomeSensorFromHardware;

	printf("%d\n", a);
	Print_Status(Adam);
	Print_Status(Eve);

	while (!(sensor->sensor_flag))
	{
	}									 // sensor.sensor_flag의 값이 0에서 1로 변하면
	printf("Data : %d\n", sensor->data); // 이걸 실행 with volatile keyword

	WEIRD b;
	printf("size of b : %d\n", sizeof(b));
}

int Print_Status(Human human)
{
	if (human.gender == 0)
	{
		printf("MALE \n");
	}
	else
	{
		printf("FEMALE \n");
	}

	printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
		   human.weight);

	if (human.gender == 0 && human.height >= 180)
	{
		printf("HE IS A WINNER!! \n");
	}
	else if (human.gender == 0 && human.height < 180)
	{
		printf("HE IS A LOSER!! \n");
	}

	printf("------------------------------------------- \n");

	return 0;
}