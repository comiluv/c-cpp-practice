/* N개의 자연수의 최대 공약수 */
#include <stdio.h>
int sortArr(int *arr, int size, int start);
int swap(int *a, int *b);
int gcd(int a, int b);
int arrMin(int *arr, int size);

int main()
{
	int n;
	int minNum;
	int i;
	printf("숫자의 개수 : ");
	scanf("%d", &n);
	int nums[n];
	for (i = 0; i < n; i++)
	{
		printf("%d개 중 %d번째 수 : ", n, i + 1);
		scanf("%d", &nums[i]);
	}

	// sortArr(nums, n, 0);
	minNum = nums[0];

	//calculate gcd(a, b, c) = gcd(gcd(a, b), c) = gcd(a, gcd(b, c)) = gcd(gcd(a, c), b)
	for (i = 1; i < n; i++)
	{
		minNum = gcd(minNum > nums[i] ? minNum : nums[i],
					minNum > nums[i] ? nums[i] : minNum);
	}
	printf("답 : %d\n", minNum);

	return 0;
}

int gcd(int a, int b)
{
	while (b)
	{
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int arrMin(int *arr, int size)
{
	int _min = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (_min > arr[i])
		{
			_min = arr[i];
		}
	}
	return _min;
}


int sortArr(int *arr, int size, int start)
{
	int maxIndex = start;
	for (int i = start; i < size; i++)
	{
		if (arr[maxIndex] < arr[i])
		{
			maxIndex = i;
		}
	}
	swap(&arr[maxIndex], &arr[start]);
	if (start < size)
	{
		sortArr(arr, size, start + 1);
	}
}

int swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}