#include<stdio.h>

void print(int(*matrix)[100], int N, int M)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
			printf(" %d", matrix[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int N, M, i;
	int matrix[100][100] = { 0 };
	int row = 0, col = -1;
	int direction = 1;
	int rbound, cbound;

	scanf("%d %d", &N, &M);

	rbound = N - 1;
	cbound = M;

	i = 1;
	while (i <= N * M)
	{
		for (int j = 0; j < cbound; j++)
		{
			col += direction;
			matrix[row][col] = i++;
		}
		cbound--;

		for (int j = 0; j < rbound; j++)
		{
			row += direction;
			matrix[row][col] = i++;
		}
		rbound--;
		direction *= -1;
	}

	print(matrix, N, M);

	return (0);
}