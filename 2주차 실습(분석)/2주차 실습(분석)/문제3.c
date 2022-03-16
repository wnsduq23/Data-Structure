#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

int* prefixAverages1(int* X, int n);
int* prefixAverages2(int* X, int n);

int main(void)
{
	int n;
	int* X;
	int* A;

	scanf("%d", &n);
	X = malloc(sizeof(int) * n);
	if (X == NULL)
		return (-1);
	for (int i = 0; i < n; i++)
		scanf("%d", &X[i]);

	A = malloc(sizeof(int) * n);
	if (A == NULL)
		return (-1);
	A = prefixAverages1(X, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i]);

	free(X);
	free(A);
	return (0);
}

int* prefixAverages1(int* X, int n)
{
	double sum;
	int	i, j;
	int* A;

	A = malloc(sizeof(int) * n);
	if (A == NULL)
		return (-1);

	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = 0; j <= i; j++)
			sum += X[j];
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return (A);
}

int* prefixAverages2(int* X, int n)
{
	double sum;
	int i;
	int* A;

	A = malloc(sizeof(int) * n);
	if (A == NULL)
		return (-1);

	sum = 0;
	for (i = 0;i < n;i++)
	{
		sum += X[i];
		A[i] = (int)(sum / (i + 1) + 0.5);
	}
	return (A);
}