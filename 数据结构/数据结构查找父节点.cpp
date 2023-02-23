#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int pos = 0;
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
void tranverse(Tree *root, int num)
{
	if(root==NULL)
		return;
	if (root->data == num && root->father != NULL)
		pos = root->father->data;
		tranverse(root->left, num);
		tranverse(root->right, num);
}
int main()
{
	Tree *ct = buildTree(ct);
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int n;
		scanf("%d", &n);
		tranverse(ct, n);
		printf("%d", pos);
		printf(m == 0 ? "" : "\n");
		pos = 0;
	}
	free(ct);
	return 0;
}
/*1 2 4 8 0 0 9 0 0 5 10 0 0 11 0 0 2 6 12 0 0 13 0 0 7 14 0 0 15 0 0
3
1
5
16*/
