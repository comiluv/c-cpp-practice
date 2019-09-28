#include <stdio.h>

int main()
{
	int i, j;
	int arr[2][3] = {1, 2, 3, 4, 5, 6};
	//rows
	for (i = 0; i < 2; i++)
	{
		//columns
		for (j = 0; j < 3; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n\nReverse column & row\n");

	for (j = 0; j < 3; j++)
	{
		//columns
		for (i = 0; i < 2; i++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}