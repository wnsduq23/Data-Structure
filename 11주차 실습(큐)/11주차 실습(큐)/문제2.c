#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 포인터 front , rear가 직접 순회하면서 추가시킴
typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_queue
{
	struct s_queue* next;
	struct s_queue* prev;
	int				elem;
	int				size;
}t_queue;

void	add_front(t_queue** front, t_queue** rear, int e)
{
	t_queue* new;

	new = malloc(sizeof(t_queue));
	if (!new)
		return;
	new->elem = e;
	new->next = *front;
	new->prev = NULL;
	if (*front == NULL)
	{
		*front = new;
		*rear = new;
	}
	else
	{
		(*front)->prev = new;
		*front = new;
	}
}

void add_rear(t_queue** front, t_queue** rear, int e)
{
	t_queue* new;
	new = malloc(sizeof(t_queue));
	if (!new)
		return;
	new->elem = e;
	new->next = NULL;
	new->prev = *rear;
	if (*rear == 0) // 첫 원소인 경우
	{
		*front = new;
		*rear = new;
	}
	else
	{
		(*rear)->next = new;
		*rear = new;
	}
}

t_bool delete_front(t_queue** front, t_queue** rear)
{
	t_queue* new;

	if (*front == NULL)
	{
		printf("underflow\n");
		return (FALSE);
	}
	new = (*front)->next;
	if (new != 0)
		new->prev = 0;
	else
		*rear = new;
	free(*front);
	*front = new;
}
t_bool delete_rear(t_queue** front, t_queue** rear)
{
	t_queue* new;

	if (*rear == NULL)
	{
		printf("underflow\n");
		return (FALSE);
	}
	new = (*rear)->prev;
	if (new != 0)
		new->next = 0;
	else
		*front = new;
	free(*rear);
	*rear = new;
}

void print(t_queue* front)
{
	t_queue* p;
	for (p = front; p; p = p->next)
		printf(" %d", p->elem);
	printf("\n");
}

void	free_list(t_queue* front)
{
	t_queue* dump;

	while (front)
	{
		dump = front;
		front = front->next;
		free(dump);
		dump = NULL;
	}
}

int	main(void)
{
	int			N; // 연산의 개수 
	char		cmd;
	t_queue* front = NULL;
	t_queue* rear = NULL;
	int			e;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();
		scanf("%c", &cmd);
		if (cmd == 'A')
		{
			scanf("%c", &cmd);
			scanf("%d", &e);
			if (cmd == 'F')
				add_front(&front, &rear, e);
			else if (cmd == 'R')
				add_rear(&front, &rear, e);
		}
		else if (cmd == 'D')
		{
			scanf("%c", &cmd);
			if (cmd == 'F')
			{
				if (delete_front(&front, &rear) == FALSE)
					break;
			}
			else if (cmd == 'R')
			{
				if (delete_rear(&front, &rear) == FALSE)
					break;
			}
		}
		else if (cmd == 'P')
			print(front);
	}
	free_list(front);
	return (0);
}