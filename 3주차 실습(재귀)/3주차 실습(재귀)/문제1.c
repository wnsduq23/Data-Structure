#include<stdio.h>

unsigned int	sum(unsigned int N)
{
	if (N == 1)
		return (1);
	else
		return (N + sum(N - 1));
}

int main(void)
{
	unsigned int N;

	scanf("%u", &N);
	printf("%u", sum(N));
	return (0);
}