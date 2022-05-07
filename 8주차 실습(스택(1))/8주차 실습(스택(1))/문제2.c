#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct	s_stack
{
	char	stack[1001];
	int		top;
	int		size;
}				t_stack;

void	init_stack(t_stack* s, int n)
{
	s->size = n;
	s->stack[s->size] = 0;
	s->top = -1;
}

// return value top of the stack
char	pop(t_stack* s)
{
	char p;
	if (s->top < 0)
		return (0);
	p = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return (p);
}

// insert in stack
void	push(t_stack* s, char elem)
{
	s->top++;
	if (s->top < s->size)
		s->stack[s->top] = elem;
	else
		s->top--;
}

int	main(void)
{
	t_stack* s;
	char str[1001] = { 0 };
	char* p;
	char tmp;
	int n = 0, flag = 1;// n은 괄호의 개수 , flag == 1 : OK , flag == 0 : Wrong

	gets(str);
	s = (t_stack*)malloc(sizeof(t_stack));
	if (!s)
		return (-1);
	init_stack(s, strlen(str));
	p = NULL;
	for (p = str; *p; p++)
	{
		if (*p == '(' || *p == '{' || *p == '[')
		{
			n++;
			push(s, *p);
		}
		if (*p == ')' || *p == '}' || *p == ']')
		{
			n++;
			tmp = pop(s);

			if ((tmp == '(' && *p != ')') || (tmp == '{' && *p != '}') || (tmp == '[' && *p != ']'))
				flag = 0;
		}
	}

	if (s->top != -1 || n % 2 != 0)
		flag = 0;

	if (flag)
		printf("OK_%d", n);
	else
		printf("Wrong_%d", n);
	free(s);
	return (0);
}
