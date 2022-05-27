#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s_tree
{
	struct s_tree* left;
	struct s_tree* right;
	int				data;
}t_tree;

t_tree* link_node(int data, t_tree* left, t_tree* right)
{
	t_tree* new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->left = left;
	new->right = right;
	new->data = data;
	return (new);
}

t_tree* get_node(int data)
{
	t_tree* new;

	new = malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return (new);
}

void print(t_tree* tree[], int n)
{
	t_tree* node = tree[n];
	printf(" %d", node->data);
	if (node->left)
		printf(" %d", (node->left)->data);
	if (node->right)
		printf(" %d", (node->right)->data);
}

void	init_tree(t_tree* tree[])
{
	tree[4] = get_node(70);
	tree[5] = get_node(90);
	tree[7] = get_node(130);
	tree[8] = get_node(80);
	tree[6] = link_node(120, tree[7], tree[8]);
	tree[2] = link_node(30, tree[4], tree[5]);
	tree[3] = link_node(50, 0, tree[6]);
	tree[1] = link_node(20, tree[2], tree[3]);
}

void	free_tree(t_tree* tree[])
{
	int	i;

	i = 0;
	while (++i < 9)
		free(tree[i]);
}

int	main(void)
{
	t_tree* tree[9];
	int		n;

	init_tree(tree);

	scanf("%d", &n);
	if (1 <= n && n <= 8)
		print(tree, n);
	else
		printf("-1");
	free_tree(tree);
	return (0);
}
