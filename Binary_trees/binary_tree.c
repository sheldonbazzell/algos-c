#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *left;
	struct node *right;
} node;

typedef struct tree {
	struct node *root;
} tree;

void pushTree(tree *tree, int value);
void pushNode(node *node, int value);
void inOrderTraverseT(tree *tree);
void inOrderTraverseN(node *node);

int main(void)
{
	tree *tree;
	pushTree(tree, 5);
	pushTree(tree, 2);
	pushTree(tree, 7);
	inOrderTraverseT(tree);
	return 1;
}

void pushTree(tree *tree, int value)
{
	if (tree->root == NULL)
	{
		node *node = malloc(sizeof(node));
		if (node != NULL)
		{
			node->val = value;
			node->left = NULL;
			node->right = NULL;
			tree->root = node;
		}
	}
	else
	{
		return pushNode(tree->root, value);
	}
}

void pushNode(node *root, int value)
{
	if (value < root->val)
	{
		if (root->left != NULL)
		{
			return pushNode(root->left, value);
		}
		else
		{
			node *node = malloc(sizeof(node));
			if (node != NULL)
			{
				node->val = value;
				node->left = NULL;
				node->right = NULL;
				root->left = node;
			}
		}
	}
	else
	{
		if (root->right != NULL)
		{
			return pushNode(root->right, value);
		}
		else
		{
			node *node = malloc(sizeof(node));
			if (node != NULL)
			{
				node->val = value;
				node->left = NULL;
				node->right = NULL;
				root->right = node;
			}
		}
	}
}

void inOrderTraverseT(tree *tree)
{
	if (tree->root != NULL)
	{
		return inOrderTraverseN(tree->root);
	}
}

void inOrderTraverseN(node *root)
{
	if (root->left != NULL)
	{
		inOrderTraverseN(root->left);
	}
	printf("%d\n", root->val);
	if (root->right != NULL)
	{
		inOrderTraverseN(root->right);
	}
}

