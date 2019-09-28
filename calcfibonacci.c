#include <stdio.h>

int main()
{
	int i,j,k,l,m,o,p,q,r,s,t,u;
	// N = 0, N-1 = 1, N-2 = 1 로 initialize
	int c = 0, c_1 = 1, c_2 = 1;
	int total = 0;
	// 홀수 항인 세번째 항부터 시작
	int even = 0;
	int N = 1000000;
	printf("피보나치 수열에서 %d 이하의 수 중 수열 상 짝수 항들의 합을 구할거지롱!\n", N);
	// c가 N보다 커지면 중단
	while (c <= N)
	{
		// c 를 계산하고
		c = c_1 + c_2;
		// N-2번째 항은 N-1번째 항의 값을 받고
		c_2 = c_1;
		// N-1번째 항은 N번째 항의 값을 받고
		c_1 = c;
		// 짝수 항이면 전체값에 더하고
		if (even == 1)
		{
			total += c;
		}
		// 짝수 항이면 홀수 항으로, 홀수 항이면 짝수 항으로 변환
		even = 1 - even;
		// 반복
	}
	printf("답은 %d 이지롱!\n", total);
}