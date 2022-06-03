#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct s_tree
{
	int				 id;
	int				 data;
	struct s_tree* left;
	struct s_tree* right;
}					t_tree;

void	setLR(t_tree* t, t_tree* l, t_tree* r)
{
	t->left = l;
	t->right = r;
}

t_tree* get_node(int id, int data)
{
	t_tree* new;

	new = (t_tree*)malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->id = id;
	new->data = data;
	new->left = NULL;
	new->right = NULL;

	return (new);
}

int	pre_order(t_tree* root, int s)
{
	int	sum = s;
	if (!root)
		return;
	sum += root->data;
	sum = pre_order(root->left, sum);
	sum = pre_order(root->right, sum);
	return (sum);
}

void	find_node(t_tree* root, int ID)
{
	int	sum = 0;

	if (ID <= 0 || 8 < ID)
		printf("-1");
	else if (!root)
		;
	else if (root->id == ID)
	{
		sum = pre_order(root, 0);
		printf("%d", sum);
	}
	else
	{
		find_node(root->left, ID);
		find_node(root->right, ID);
	}
}

void	init_tree(t_tree* root)
{
	t_tree* left, * right;

	root->id = 1;
	root->data = 20;
	//root's child nodes
	left = get_node(2, 30);
	right = get_node(3, 50);
	setLR(root, left, right);
	//root's left child's child nodes
	left = get_node(4, 70);
	right = get_node(5, 90);
	setLR(root->left, left, right);
	//root's right child's child nodes
	left = NULL;
	right = get_node(6, 120);
	setLR(root->right, left, right);
	//root's right child's child's child nodes
	left = get_node(7, 130);
	right = get_node(8, 80);
	setLR((root->right)->right, left, right);

}

void	free_tree(t_tree* tree)
{
	while (tree)
	{
		free_tree(tree->left);
		free_tree(tree->right);
		free(tree);
		tree = NULL;
	}
}

int	main(void)
{
	t_tree* tree;// 루트노드를 가리키는 포인터 
	int		node_id;

	//트리 구현
	tree = malloc(sizeof(t_tree));
	if (!tree)
		return (-1);
	init_tree(tree);

	scanf("%d", &node_id);
	find_node(tree, node_id);

	free_tree(tree);
	return (0);
}
