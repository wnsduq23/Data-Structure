#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_stack
{
	char			value;
	struct s_stack* prev;// previous input address
}				t_stack;

t_bool isOperand(char s)
{
	if ('A' <= s && s <= 'Z')
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

// make unity of byte ( || => | , && => &) and distinguish unary operator '+','-' && plus '+','-'
void encode(char* str)
{
	char* p, * q;

	if (*str == '+')
		*str = 'p';
	if (*str == '-')
		*str = 'm';
	for (p = str + 1; *p; p++)
	{
		if (*p == '|' || *p == '&')
		{
			for (q = p + 1; *q; q++)
				*(q - 1) = *q;
			*(q - 1) = 0;
		}
	}
	for (p = str + 1; *p; p++)
	{
		if (isOperand(*(p - 1)) == false && *(p - 1) != ')')
		{
			if (*p == '+')
				*p = 'p';
			if (*p == '-')
				*p = 'm';
		}
	}
}

int priority(char c)
{
	if (c == '!' || c == 'p' || c == 'm')
		return (6);
	if (c == '*' || c == '/')
		return (5);
	if (c == '+' || c == '-')
		return (4);
	if (c == '>' || c == '<')
		return (3);
	if (c == '&')
		return (2);
	if (c == '|')
		return (1);
	return (0);
}

void	print(t_stack** top)
{
	char	t;

	t = pop(top);
	if (t == '|' || t == '&')
		printf("%c%c", t, t);
	else if (t == 'p')
		printf("+");
	else if (t == 'm')
		printf("-");
	else
		printf("%c", t);
}

void convert_to_postfix(char* str)
{
	t_stack* top = NULL;
	char* p = str;
	char	s;

	while ((s = *p++))
	{
		if (isOperand(s) == true)
			printf("%c", s);
		else if (s == '(')
			push(s, &top);
		else if (s == ')')
		{
			while (top->value != '(')
				print(&top);
			pop(&top);// pop '('
		}
		else
		{
			// pop priority order 
			while (top != 0 && priority(s) <= priority(top->value))
				print(&top);
			push(s, &top);
		}
	}
	while (top != 0)
		print(&top);
	printf("\n");
}

int main(void)
{
	int		n;
	char	str[101] = { 0 };

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets(str);
		encode(str);
		convert_to_postfix(str);
	}
	return (0);
}
