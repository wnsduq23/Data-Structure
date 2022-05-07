#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct	s_set
{
	int			elem;
	struct s_set* next;
}				t_set;

int isEmpty(t_set* s)
{
	if (s == 0 || (s->elem == 0 && s->next == 0))
		return (1);
	return (0);
}

t_set* addElem(t_set* s, int e)
{
	t_set* n;

	n = (t_set*)malloc(sizeof(t_set));
	if (!n)
		return (NULL);
	n->elem = e;
	n->next = NULL;
	s->next = n;

	return (n);
}

void print(t_set* s)
{
	t_set* p;

	if (isEmpty(s))
	{
		printf(" 0\n");
		return;
	}
	for (p = s->next; p->next; p = p->next)
		printf(" %d", p->elem);
	printf(" %d\n", p->elem);
}

t_set unionSet(t_set* A, t_set* B)
{
	t_set C;
	t_set* p;
	t_set* a = A->next, * b = B->next;

	memset(&C, 0, sizeof(t_set));
	p = &C;
	if (isEmpty(A))
		return (*B);
	if (isEmpty(B))
		return (*A);

	while (!isEmpty(a) && !isEmpty(b))
	{
		if (a->elem < b->elem)
		{
			p = addElem(p, a->elem);
			a = a->next;
		}
		else if (a->elem > b->elem)
		{
			p = addElem(p, b->elem);
			b = b->next;
		}
		else
		{
			p = addElem(p, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	while (!isEmpty(a))
	{
		p = addElem(p, a->elem);
		a = a->next;
	}
	while (!isEmpty(b))
	{
		p = addElem(p, b->elem);
		b = b->next;
	}
	return (C);
}

t_set intersect(t_set* A, t_set* B)
{
	t_set C;
	t_set* p;
	t_set* a = A->next, * b = B->next;

	memset(&C, 0, sizeof(t_set));
	p = &C;
	if (isEmpty(A))
		return (C);
	if (isEmpty(B))
		return (C);

	while (!isEmpty(a) && !isEmpty(b))
	{
		if (a->elem < b->elem)
			a = a->next;
		else if (a->elem > b->elem)
			b = b->next;
		else
		{
			p = addElem(p, a->elem);
			a = a->next;
			b = b->next;
		}
	}
	return (C);
}

// list의 첫 번째 노드가 아무것도 아닐 경우
void	free_list(t_set* list)
{
	t_set* dummy;

	list = list->next;
	while (list)
	{
		dummy = list;
		list = list->next;
		free(dummy);
	}
}

int main(void)
{
	int sizeA, sizeB, i, e;
	t_set A, B;
	t_set u, inter;
	t_set* p = NULL, * q = NULL;

	memset(&A, 0, sizeof(t_set));
	memset(&B, 0, sizeof(t_set));
	p = &A;
	q = &B;

	scanf("%d", &sizeA);
	getchar();
	for (i = 0; i < sizeA; i++)
	{
		scanf("%d", &e);
		p = addElem(p, e);
		if (p == NULL)
			return (-1);
	}

	scanf("%d", &sizeB);
	getchar();
	for (i = 0; i < sizeB; i++)
	{
		scanf("%d", &e);
		q = addElem(q, e);
		if (q == NULL)
			return (-1);
	}

	u = unionSet(&A, &B);
	print(&u);
	inter = intersect(&A, &B);
	print(&inter);

	free_list(&u);
	free_list(&inter);
	free_list(&A);
	free_list(&B);
	return (0);
}