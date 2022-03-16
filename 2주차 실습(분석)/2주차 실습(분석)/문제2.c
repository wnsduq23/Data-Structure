#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int		mostOnes(int** bit, int n);
void	ft_free(int** bit, int n);

int	main(void)
{
	int	n;
	int i;
	int j;
	int max_row;
	int** bit;

	scanf("%d", &n);
	bit = (int**)malloc(sizeof(int*) * n);
	if (bit == NULL)
		return (-1);
	for (i = 0; i < n; i++)
	{
		bit[i] = (int*)malloc(sizeof(int) * n);
		if (bit[i] == NULL)
			return (-1);
		for (j = 0; j < n; j++)
			scanf("%d", &bit[i][j]);
	}
	max_row = mostOnes(bit, n);
	printf("%d", max_row);
	ft_free(bit, n);
	return (0);
}

int	mostOnes(int** bit, int n)
{
	int	max;
	int i = 0;
	int j = 0;

	max = 0;
	while ((i < n) && (j < n))
	{
		if (bit[i][j] == 0)
			i++;
		else
		{
			max = i;
			j++;
		}
	}
	return (max);
}

void	ft_free(int** bit, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		free(bit[i]);
	}
	free(bit);
}