#include<stdio.h>

void print(int(*matrix)[100], int N)
{
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf(" %d", matrix[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int N;
	int matrix[100][100] = { 0 };
	int row = 0, col = -1;
	int direction = 1;
	int i;

	scanf("%d", &N);

	i = 1;
	while (i <= N * N)
	{
		col += direction;
		for (int j = 0; j < N; j++)
		{
			matrix[row][col] = i++;
			col += direction;
		}
		direction *= -1;
		row++;
	}

	print(matrix, N);

	return (0);
}
