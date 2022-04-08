#include<stdio.h>

int countchk(char* N, char chk, int cnt)
{

	if (*N == 0)
		return (cnt);
	if (*N == chk)
		return countchk(N + 1, chk, cnt + 1);
	return countchk(N + 1, chk, cnt);
}

int main(void)
{
	char	N[101] = { 0 };
	char	chk = 0;

	scanf("%s", N);
	getchar();
	scanf("%c", &chk);

	printf("%d", countchk(N, chk, 0));
	return (0);
}