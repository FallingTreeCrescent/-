#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *father;
} Tree, *ptr;
Tree *buildTree(Tree *root) //½¨Á¢¶þ²æÊ÷
{
	int x;
	scanf("%d",&x);
	if (x == 0)
	{
		root = NULL;
		return root;
	}
	root = (Tree *)malloc(sizeof(Tree));
	root->father = NULL;
	root->data = x;
	root->left = buildTree(root->left);
	if (root->left != NULL)
		root->left->father = root;
	root->right = buildTree(root->right);
	if (root->right != NULL)
		root->right->father = root;
	return root;
}
void preorder(Tree *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void midorder(Tree *root)
{
	if (root != NULL)
	{
		midorder(root->left);
		printf("%d ", root->data);
		midorder(root->right);
	}
}
void postorder(Tree *root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
int main()
{
	Tree *ct = buildTree(ct);
	preorder(ct);
	printf("\n");
	midorder(ct);
	printf("\n");
	postorder(ct);
	free(ct); 
	return 0;
}
