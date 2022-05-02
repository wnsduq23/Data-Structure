#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct		s_set
{
	int				elem;
	struct s_set* next;
}					t_set;

int isEmpty(t_set* s)
{
	if (s)
		return (0);
	return (1);
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

int member(t_set* A, int e)
{
	t_set* p = A->next;

	if (isEmpty(p))
		return (0);
	while (1)
	{
		if (p->elem < e)
		{
			if (p->next == NULL)
				return (0);
			p = p->next;
		}
		else if (p->elem > e)
			return (0);
		else
			return (1);
	}
}

int subset(t_set* A, t_set* B)
{
	t_set* a = A->next;

	if (isEmpty(a))
		return (0);
	while (1)
	{
		if (member(B, a->elem))
		{
			if (a->next == NULL)
				return (0);
			a = a->next;
		}
		else
			return (a->elem);
	}
}

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

int	main(void)
{
	int		sizeA, sizeB, i, elem;
	t_set	A, B;
	t_set* p, * q, * tmp;

	memset(&A, 0, sizeof(t_set));
	memset(&B, 0, sizeof(t_set));

	p = &A;
	q = &B;

	scanf("%d", &sizeA);
	getchar();
	for (i = 0; i < sizeA; i++)
	{
		scanf("%d", &elem);
		p = addElem(p, elem);
		if (p == NULL)
			return (-1);
	}

	scanf("%d", &sizeB);
	getchar();
	for (i = 0; i < sizeB; i++)
	{
		scanf("%d", &elem);
		q = addElem(q, elem);
		if (q == NULL)
			return (-1);
	}

	printf("%d", subset(&A, &B));

	free_list(&A);
	free_list(&B);
	return (0);
}