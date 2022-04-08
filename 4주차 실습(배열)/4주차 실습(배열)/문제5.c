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
	int N, M, i, j;
	int matrix[100][100] = { 0 };
	int row = 0, col = 0;
	int init_row, init_col;

	scanf("%d %d", &N, &M);

	i = 1;
	init_row = 0;
	for (init_col = 0; init_col < M; init_col++)
	{
		row = init_row, col = init_col;
		while (col >= 0 && row < N)
			matrix[row++][col--] = i++;
	}
	init_col--;// init_col == M - 1
	for (init_row = 1; init_row < N; init_row++) // 0행이 다 채워졌을 경우
	{
		row = init_row, col = init_col;
		while (col >= 0 && row < N)
			matrix[row++][col--] = i++;
	}

	print(matrix, N, M);

	return (0);
}