#include <stdio.h>

int	find_max(int* ar, int n)
{
	if (n == 0)
		return (*ar);
	else
	{
		if (find_max(ar, n - 1) > *(ar + n - 1))
			return (find_max(ar, n - 1));
		else
			return (*(ar + n - 1));
	}
}

int main(void)
{
	int N;
	int ar[20] = { 0 };
	int max;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &ar[i]);
	max = find_max(ar, N);
	printf("%d", max);
	return (0);
}