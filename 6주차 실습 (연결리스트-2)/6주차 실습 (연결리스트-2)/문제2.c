#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct s_node
{
	int	coef;	// 계수
	int	exp;	// 차수
	struct s_node* next;
}t_list;

t_list* get_node_malloc(void)
{
	t_list* new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	memset(new, 0, sizeof(t_list));
	return (new);
}

void	make_poly(t_list* head, int c, int e)
{
	t_list* new;

	while (head->next)
		head = head->next;
	new = get_node_malloc();
	if (!new)
		return;
	new->coef = c;
	new->exp = e;
	head->next = new;
}

void	add_and_print_poly(t_list* h1, t_list* h2)
{
	t_list* result;
	int sum = 0;

	result = get_node_malloc();
	if (!result)
	{
		printf("fail to make result");
		return;
	}
	while ((h1->next != NULL) && (h2->next != NULL))
	{
		if (h1->next->exp > h2->next->exp)
		{
			make_poly(result, h1->next->coef, h1->next->exp);
			h1 = h1->next;
		}
		else if (h1->next->exp < h2->next->exp)
		{
			make_poly(result, h2->next->coef, h2->next->exp);
			h2 = h2->next;
		}
		else
		{
			sum = h1->next->coef + h2->next->coef;
			if (sum != 0)
				make_poly(result, sum, h2->next->exp);
			h1 = h1->next;
			h2 = h2->next;
		}
	}
	while (h1->next != NULL)
	{
		make_poly(result, h1->next->coef, h1->next->exp);
		h1 = h1->next;
	}
	while (h2->next != NULL)
	{
		make_poly(result, h2->next->coef, h2->next->exp);
		h2 = h2->next;
	}
	result = result->next;
	while (result)
	{
		printf("%d %d ", result->coef, result->exp);
		result = result->next;
	}
	free(result);
	result = NULL;
}

int main(void)
{
	int		N, M; // 반복 지우기
	int		c, e;
	t_list* head1;// head1,2는 단순 포인터용도. 값을 집어넣지 않는다.
	t_list* head2;

	head1 = get_node_malloc();
	if (!head1)
	{
		printf("Memory allocation failure");
		return (-1);
	}
	head2 = get_node_malloc();
	if (!head2)
	{
		printf("Memory allocation failure");
		return (-1);
	}
	scanf("%d", &N);
	getchar();

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &c, &e);
		make_poly(head1, c, e);
	}
	getchar();

	scanf("%d", &M);
	getchar();

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &c, &e);
		make_poly(head2, c, e);
	}
	add_and_print_poly(head1, head2);
	free(head1);
	free(head2);
	head1 = NULL;
	head2 = NULL;
	return (0);
}