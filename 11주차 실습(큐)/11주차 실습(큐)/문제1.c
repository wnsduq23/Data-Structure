#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;

typedef struct s_queue
{
	int front;
	int rear;
	int* que;
	int	size;
}t_queue;

t_bool	is_empty(t_queue* Q)
{
	if (Q->front == Q->rear)
		return (TRUE);
	else
		return (FALSE);
}

t_bool is_full(t_queue* Q)
{
	if (Q->front == ((Q->rear + 1) % Q->size))
		return (TRUE);
	else
		return (FALSE);
}

void print(t_queue* Q)
{
	int* p;
	for (p = Q->que; p < Q->que + Q->size; p++)
		printf(" %d", *p);
	printf("\n");
}

void	init_queue(t_queue* Q, int size)
{
	Q->front = 0;
	Q->rear = 0;
	Q->que = malloc(sizeof(int) * size);
	if (!Q->que)
		return;
	for (int i = 0; i < size; i++)
		Q->que[i] = 0;
	Q->size = size;
}

t_bool	enqueue(t_queue* Q, int e)
{
	if (is_full(Q) == TRUE)
		return (FALSE);
	Q->rear += 1;
	Q->rear %= Q->size;
	Q->que[Q->rear] = e;
	return (TRUE);
}

t_bool	dequeue(t_queue* Q)
{
	if (is_empty(Q) == TRUE)
		return (FALSE);
	Q->front += 1;
	Q->front %= Q->size;
	Q->que[Q->front] = 0;
	return (TRUE);
}

int	main(void)
{
	int			N; // 연산의 개수 
	int			q; // 원형 큐의 크기 
	char		cmd;
	t_queue		Q;
	int			e;

	scanf("%d", &q);
	scanf("%d", &N);

	init_queue(&Q, q);

	for (int i = 0; i < N; i++)
	{
		getchar();
		scanf("%c", &cmd);
		if (cmd == 'I')
		{
			getchar();
			scanf("%d", &e);
			if (enqueue(&Q, e) == FALSE)
			{
				printf("overflow");
				print(&Q);
				break;

			}
		}
		else if (cmd == 'D')
		{
			if (dequeue(&Q) == FALSE)
			{
				printf("underflow");
				break;
			}
		}
		else if (cmd == 'P')
			print(&Q);
	}
	free(Q.que);
	return (0);
}