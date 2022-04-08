#include <stdio.h>
#include <stdlib.h>

typedef struct	node
{
	struct node* next;
	struct node* prev;
	char		 elem;
}				Node;

Node* initnode(void);

void	add(Node* list, unsigned int r, char e)
{
	unsigned int	i = 0;
	Node* new;

	while (i < r)
	{
		if ((list)->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		(list) = (list)->next;
		i++;
	}
	if (r == 0)
	{
		printf("invalid position\n");
		return;
	}
	new = initnode();
	new->elem = e;
	((list)->prev)->next = new;
	new->prev = (list)->prev;
	new->next = (list);
	(list)->prev = new;
	new = NULL;//��۸� ������ ����
}

void	Delete(Node* list, unsigned int r)
{
	unsigned int i = 0;

	while (i < r)
	{
		if ((list)->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		(list) = (list)->next;
		i++;
	}
	if ((list->next == 0) || r == 0)
	{
		printf("invalid position\n");
		return;
	}
	((list)->prev)->next = (list)->next;
	((list)->next)->prev = (list)->prev;
	//list->elem = 0;
	free(list);//*?
}

void	get(Node* list, unsigned int r)
{
	unsigned int i = 0;

	while (i < r)
	{
		if ((list)->next == 0)
		{
			printf("invalid position\n");
			return;
		}
		(list) = (list)->next;
		i++;
	}
	if ((list)->next == 0 || r == 0)
	{
		printf("invalid position\n");
		return;
	}
	printf("%c\n", (list)->elem);
}

void	print(Node* list)
{
	list = list->next;
	while ((list)->next)
	{
		printf("%c", (list)->elem);
		list = list->next;
	}
	printf("\n");
}

Node* initnode(void)//�ٵ� ����ü�� �˾Ƽ� 0���� �ʱ�ȭ���� �ʳ�?
{
	Node* new;
	new = malloc(sizeof(Node));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->elem = 0;
	return (new);
}

int main(void)
{
	unsigned int	N;
	unsigned int	r; // rank
	char			opt, put;
	Node* Head, * Tail;
	unsigned int	i;

	Head = initnode();
	Tail = initnode();
	Head->next = Tail;
	Tail->prev = Head;

	scanf("%u", &N);
	for (i = 0; i < N; i++)
	{
		getchar();
		scanf("%c", &opt);
		if (opt == 'A')
		{
			scanf("%u %c", &r, &put);
			add(Head, r, put);
		}
		else if (opt == 'D')
		{
			scanf("%u", &r);
			Delete(Head, r);
		}
		else if (opt == 'P')
			print(Head);
		else if (opt == 'G')
		{
			scanf("%u", &r);
			get(Head, r);
		}
	}
	return (0);
}