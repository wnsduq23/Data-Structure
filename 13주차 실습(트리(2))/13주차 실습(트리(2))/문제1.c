#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef enum e_order
{
	ERROR,
	PRE,	// 전위순회
	IN,		// 중위순회
	POST	// 후위순회
} t_order;

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

void	pre_order(t_tree* root)
{
	if (!root)
		return;
	printf(" %d", root->data);
	pre_order(root->left);
	pre_order(root->right);
}

void	in_order(t_tree* root)
{
	if (!root)
		return;
	in_order(root->left);
	printf(" %d", root->data);
	in_order(root->right);
}

void	post_order(t_tree* root)
{
	if (!root)
		return;
	post_order(root->left);
	post_order(root->right);
	printf(" %d", root->data);

}

void	find_node(t_tree* root, t_order type, int ID)
{

	if (ID <= 0 || 8 < ID)
		printf("-1");
	else if (!root)
		;
	else if (root->id == ID)
	{
		if (type == PRE)
			pre_order(root);
		else if (type == IN)
			in_order(root);
		else if (type == POST)
			post_order(root);
	}
	else
	{
		find_node(root->left, type, ID);
		find_node(root->right, type, ID);
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
	t_order	order_num;
	int		node_id;

	//트리 구현
	tree = malloc(sizeof(t_tree));
	if (!tree)
		return (-1);
	init_tree(tree);

	scanf("%d %d", &order_num, &node_id);
	find_node(tree, order_num, node_id);

	free_tree(tree);
	return (0);
}
