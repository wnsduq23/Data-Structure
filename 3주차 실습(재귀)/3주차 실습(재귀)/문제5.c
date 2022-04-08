#include<stdio.h>

void hanoi(char from, char by, char to, int n)
{
	if (n == 1)
	{
		printf("%c %c\n", from, to);
		return;
	}
	hanoi(from, to, by, n - 1);
	printf("%c %c\n", from, to);
	hanoi(by, from, to, n - 1);
}

int main()
{
	int n;

	scanf("%d", &n);
	hanoi('A', 'B', 'C', n);

	return 0;
}