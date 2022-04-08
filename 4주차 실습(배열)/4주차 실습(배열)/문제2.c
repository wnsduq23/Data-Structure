#include<stdio.h>
#pragma warning(disable:4996)

int main(void)
{
	int N;
	int rev_num;
	int ar[100];
	int swap_idx;
	int a, b;
	int tmp, prev;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);

	scanf("%d", &rev_num);
	scanf("%d", &a);
	prev = ar[a];
	for (int i = 1; i < rev_num; i++)
	{
		scanf("%d", &swap_idx);
		tmp = ar[swap_idx];
		ar[swap_idx] = prev;
		prev = tmp;
	}

	for (int i = 0; i < N; i++)
		printf(" %d", ar[i]);
	return (0);
}