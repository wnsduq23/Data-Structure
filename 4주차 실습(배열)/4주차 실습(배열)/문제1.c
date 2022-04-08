#include<stdio.h>
#pragma warning(disable:4996)

void	reverse(int* ar, int a, int b)
{
	int tmp;
	while (a < b)
	{
		tmp = ar[a];
		ar[a++] = ar[b];
		ar[b--] = tmp;
	}
}
int main(void)
{
	int N;
	int rev_num;
	int ar[100];
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	scanf("%d", &rev_num);
	for (int i = 0; i < rev_num; i++)
	{
		scanf("%d %d", &a, &b);
		reverse(ar, a, b);
	}

	for (int i = 0; i < N; i++)
		printf(" %d", ar[i]);
	return (0);
}