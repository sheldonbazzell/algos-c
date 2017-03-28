#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node {
	int val;
	struct node *left;
	struct node *right;
} node;

typedef struct tree {
	struct node *root;
} tree;

void pushTree(tree *tree, int value);
int removeN(node *root, node *parent, int target);
void pushNode(node *node, int value);
void inOrderTraverseT(tree *tree);
void inOrderTraverseN(node *node);
int height(node *node);
bool isBalanced(node *node);

int main(void)
{
	tree *tree;
	pushTree(tree, 5);
	pushTree(tree, 2);
	pushTree(tree, 7);
	pushTree(tree, 1);
	pushTree(tree, 9);
	pushTree(tree, 3);
	pushTree(tree, 6);
	removeN(tree->root, NULL, 7);
	inOrderTraverseT(tree);
	//int x = height(tree->root);
	//printf("%d\n", x);
	bool y = isBalanced(tree->root);
	printf("%s\n", y ? "true" : "false");
	return 1;
}

void pushTree(tree *tree, int value)
{
	if (tree->root == NULL)
	{
		tree->root = malloc(sizeof(node));
		if (tree->root != NULL)
		{
			tree->root->val = value;
			tree->root->left = NULL;
			tree->root->right = NULL;
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
			root->left = malloc(sizeof(node));
			if (root->left != NULL)
			{
				root->left->val = value;
				root->left->left = NULL;
				root->left->right = NULL;
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
			root->right = malloc(sizeof(node));
			if (root->right != NULL)
			{
				root->right->val = value;
				root->right->left = NULL;
				root->right->right = NULL;
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

int height(node *root)
{
	if (root == NULL)
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	if (right > left)
	{
		return right + 1;
	}
	else
	{
		return left + 1;
	}
}

int getMin(node *node)
{
	if (node->left)
		return getMin(node->left);
	else
		return node->val;
}

int removeN(node *root, node *parent, int value)
{
	if (value < root->val)
	{
		if (root->left != NULL)
			return removeN(root->left, root, value);
		else
			return 0;
	}
	else if (value > root->val)
	{
		if (root->right != NULL)
		{
			return removeN(root->right, root, value);
		}
		else
			return 0;
	}
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			root->val = getMin(root->right);
			removeN(root->right, root, root->val);
			return 1;
		}
		else if(parent->right == root)
		{
			if (root->left != NULL)
			{
				parent->right = root->left;
			}
			else
			{
				parent->right = root->right;
			}
		}
		else if(parent->left == root)
		{
			if (root->left != NULL)
			{
				parent->left = root->left;
			}
			else
			{
				parent->left = root->right;
			}
		}
		return 1;
	}
}

bool isBalanced(node *node)
{
	if (node == NULL)
	{
		return true;
	}
	int left = height(node->left);
	int right = height(node->right);
	if (abs(left - right) <= 1 && isBalanced(node->left) && isBalanced(node->right))
	{
		return true;
	}
	else
	{
		return false;
	}
}


