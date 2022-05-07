#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct	s_stack
{
	char* stack;
	int		top;
	int		size;
}				t_stack;

void	init_stack(t_stack* s, int n)
{
	s->size = n;
	s->stack = (char*)malloc(sizeof(char) * (s->size + 1));
	s->stack[s->size] = 0;
	if (!s->stack)
		return;
	s->top = -1;
}

// return value top of the stack
char	pop(t_stack* s)
{
	char p;
	if (s->top < 0)
	{
		printf("Stack Empty\n");
		return (0);
	}
	p = s->stack[s->top];
	s->stack[s->top] = 0;
	s->top--;
	return (p);
}

// insert in stack
void	push(t_stack* s, char el)
{
	s->top++;
	if (s->top < s->size)
		s->stack[s->top] = el;
	else
	{
		printf("Stack FULL\n");
		s->top--;
	}
}

//see what is in top of stack
void	peek(t_stack* s)
{
	if (s->top < 0)
		printf("Stack Empty\n");
	else
		printf("%c\n", s->stack[s->top]);
}

//duplicate top value of the stack
void	duplicate(t_stack* s)
{
	char	elem;

	elem = pop(s);
	push(s, elem);
	push(s, elem);
}

// 3 2 1 (top) --> 1 3 2
// go to top direction
//top value goes to bottom
void	upRotate(t_stack* s, int n)
{
	char	elem;
	char* tmp;
	int		j;

	if (n > s->top + 1)
		return;
	elem = pop(s);
	tmp = (char*)malloc(sizeof(char) * (n - 1));
	for (j = 0; j < n - 1; j++)
		*(tmp + j) = pop(s);
	push(s, elem);
	for (j = j - 1; j >= 0; j--)
		push(s, *(tmp + j));
	free(tmp);
}

// 3 2 1(top) --> 2 1 3
// go to bottom direction
//bottom value goes to top
void	downRotate(t_stack* s, int n)
{
	char	elem;
	char* tmp;
	int		j;

	if (n > s->top + 1)
		return;
	tmp = (char*)malloc(sizeof(char) * (n - 1));
	for (j = 0; j < n - 1; j++)
		*(tmp + j) = pop(s);
	elem = pop(s);
	for (j = j - 1; j >= 0; j--)
		push(s, *(tmp + j));
	push(s, elem);
	free(tmp);
}

void print(t_stack* s)
{
	for (int i = s->top; 0 <= i; i--)
		printf("%c", s->stack[i]);
	printf("\n");
}

void	free_stack(t_stack* s)
{
	free(s->stack);
	free(s);
}

int main(void)
{
	t_stack* s;
	int		n, cnt;
	int		cn;
	char	c[6] = { 0 };//command detail
	char	elem;//element

	scanf("%d", &n);  // stack size
	scanf("%d", &cnt);//command count

	//init stack
	s = (t_stack*)malloc(sizeof(t_stack));
	if (!s)
		return (-1);
	init_stack(s, n);

	for (int i = 0; i < cnt; i++)
	{
		scanf("%s", c);
		if (!strcmp(c, "POP"))
			pop(s);
		else if (!strcmp(c, "PUSH"))
		{
			getchar();
			scanf("%c", &elem);
			push(s, elem);
		}
		else if (!strcmp(c, "PEEK"))
			peek(s);
		else if (!strcmp(c, "DUP"))
			duplicate(s);
		else if (!strcmp(c, "UpR"))
		{
			scanf("%d", &cn);
			upRotate(s, cn);
		}
		else if (!strcmp(c, "DownR"))
		{
			scanf("%d", &cn);
			downRotate(s, cn);
		}
		else if (!strcmp(c, "PRINT"))
			print(s);
	}
	free_stack(s);
	return (0);
}
