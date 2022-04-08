#include<stdio.h>

void	print_low(int N)
{

	if (N == 0)
		return;
	else
	{
		printf("%d\n", N % 10);
		print_low(N / 10);
	}

}

int main(void)
{
	int N;

	scanf("%d", &N);
	print_low(N);
	return (0);
}