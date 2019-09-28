/* 계산기 1: +, 2:-, 3:*, 4:/ */
#include <stdio.h>
int calcMain(float *in_, int *op_, float *res_);

int main()
{
	float in = 0, res = 0;
	int op;
	printf("단순 계산기 1.0\n");
	printf("--------------\n");
	printf("사용법\n");
	printf("더하기:1, 빼기:3,\n");
	printf("곱하기:2, 나누기:4\n");
	printf("되돌리기:5\n");
	printf("--------------\n");
	calcMain(&in, &op, &res);
}

int calcMain(float *in_, int *op_, float *res_)
{

	int op;
	printf("								in%f op%d res%f\n",*in_,*op_,*res_);
	printf("다음값:");
	scanf("%f", in_);
	printf("								in%f op%d res%f\n",*in_,*op_,*res_);
	switch (*op_)
	{
	case 1:
		//더하기
		*res_ += *in_;
		break;
	case 2:
		//곱하기
		*res_ *= *in_;
		break;
	case 3:
		//빼기
		*res_ -= *in_;
		break;
	case 4:
		//나누기
		*res_ /= *in_;
		break;
	}
	printf("현재값 : %f\n", *res_);
	printf("								in%f op%d res%f\n",*in_,*op_,*res_);
	do
	{
		printf("연산자입력:");
		scanf("%d", &op);
	} while (op < 0 && op > 5);
	printf("								in%f op%d res%f\n",*in_,*op_,*res_);
	if (op == 5)
	{
		*op_ = 4 - *op_;
		calcMain(res_, op_, in_);
	}
	else
	{
		*op_ = op;
		calcMain(in_, op_, res_);
	}
}