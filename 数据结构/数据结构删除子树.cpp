#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int flag=0;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
	struct node *father;
} Tree, *ptr;
Tree *buildTree(Tree *root) //建立二叉树
{
	int x;
	scanf("%d", &x);
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
Tree *deleteTree(Tree *root, int num)
{
	if (root == NULL)
		return NULL;
	if (root->data == num)
	{
		flag=1;
		if(root->father!=NULL)
		{
			if(root->father->left==root)
			root->father->left=NULL;
			else if(root->father->right==root)
			root->father->right=NULL;
		}
		else return NULL;//删除根有问题 
	}
	deleteTree(root->left, num);
	deleteTree(root->right, num);
	return root;
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
int main()
{
	Tree *ct = buildTree(ct);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		flag=0;
		int n;
		scanf("%d", &n);
		deleteTree(ct, n);
		if(flag==1)
		midorder(ct);
		else printf("0");
		printf(m == 0 ? "" : "\n");
	}
	free(ct);
	return 0;
}
