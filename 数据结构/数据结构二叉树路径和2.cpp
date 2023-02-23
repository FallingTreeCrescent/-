#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int a[100001],b[100001];//记录路径 
int ans=999,sum=0;
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
void tranverse(Tree *root)
{
	if(root==NULL)return;
	Tree *p = root;
	int x = 0;
	int j = 0; // j与ans比较位数
	while (p != NULL)//对每个结点求前序和 
	{
		flag:
		b[j++] = p->data;
		x += p->data;
		if (x > sum)
		{
			if(p->father!=NULL&&p->father->data>=0)
			{
				p=p->father;
				goto flag;
			}
			for (int i = 0; i < j; i++)
			{
				a[i] = b[i];//将b数组赋值a数组
			}
			ans = j;
			sum=x;
		}
		else if(x==sum&&j<ans)
		{
			for (int i = 0; i < j; i++)
			{
				a[i] = b[i];//将b数组赋值a数组
			}
			ans = j;
		}
			p = p->father;
	}
		tranverse(root->left);
		tranverse(root->right);
}
int main()
{
	Tree *ct = buildTree(ct);
	tranverse(ct);
	printf("%d\n",sum);
	for (int i = ans-1; i >= 0; i--)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
//1 2 0 0 3 0 0
//-1 2 0 0 3 4 0 0 0
//3 2 0 0 -1 4 0 0 0
//1 2 4 8 0 0 9 0 0 5 10 0 0 11 0 0 2 6 12 0 0 13 0 0 7 14 0 0 15 0 0
//1 7 8 0 0 0 15 0 0
//1 6 9 0 0 0 7 0 8 0 0

















