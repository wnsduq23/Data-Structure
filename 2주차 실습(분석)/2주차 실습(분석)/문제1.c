#include <stdio.h>
#pragma warning(disable: 4996)

unsigned int modulo(unsigned int a, unsigned int b)
{
	if (a == 0)
		return (a);
	else if (a < b)
		return (a);
	else
	{
		while (a >= b)
			a -= b;
		return (a);
	}
}

int	main(void)
{
	unsigned int	a;
	unsigned int	b;

	scanf("%u %u", &a, &b);
	printf("%u", modulo(a, b));
	return (0);
}