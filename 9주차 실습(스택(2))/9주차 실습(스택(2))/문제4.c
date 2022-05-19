#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct s_stack
{
	char			value;
	struct s_stack* prev;
} t_stack;

t_bool isOperand(char s)
{
	if ('0' <= s && s <= '9')
		return (true);
	return (false);
}

void push(char elem, t_stack** top)
{
	t_stack* n;

	n = (t_stack*)malloc(sizeof(t_stack));
	if (!n)
		return;
	n->value = elem;
	n->prev = *top;
	*top = n;
}

char pop(t_stack** top)
{
	char	v;
	t_stack* pr;

	v = (*top)->value;
	pr = (*top)->prev;
	free(*top);
	*top = pr;
	return (v);
}

char doOper(char op, char a, char b)
{
	if (op == '+')
		return (((a - '0') + (b - '0')) + '0');
	else if (op == '-')
		return (((a - '0') - (b - '0')) + '0');
	else if (op == '*')
		return (((a - '0') * (b - '0')) + '0');
	else if (op == '/')
		return (((a - '0') / (b - '0')) + '0');
	else
	{
		printf("it's invalid operator");
		return (0);
	}
}

void evaluate(char* str)
{
	t_stack* top = NULL;
	char* p;
	char s, a, b;

	for (p = str; *p; p++)
	{
		s = *p;
		if (isOperand(s) == true)
			push(s, &top);
		else
		{
			a = pop(&top);
			b = pop(&top);
			push(doOper(s, b, a), &top);
		}
	}
	printf("%d\n", pop(&top) - '0');
}

int main(void)
{
	int n;
	char str[101] = { 0 };

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(str);
		evaluate(str);
	}
	return (0);
}
