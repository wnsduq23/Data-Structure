#include<stdio.h>

void	print_high(int N)
{

	if (N == 0)
		return;
	else
	{

		print_high(N / 10);
		printf("%d\n", N % 10);
	}

}

int main(void)
{
	int N;

	scanf("%d", &N);
	print_high(N);
	return (0);
}