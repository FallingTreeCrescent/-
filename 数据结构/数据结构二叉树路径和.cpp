#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
/*6
8 5 1 0 0 2 0 0 7 0 0 7
8 5 1 0 0 2 0 0 7 0 0 6
8 5 2 5 0 0 6 0 0 3 8 0 0 7 0 0 2 4 0 0 3 0 0 5
8 5 2 5 0 0 6 0 0 3 8 0 0 7 0 0 2 4 0 0 3 0 0 14
8 5 2 5 0 0 6 0 0 3 8 0 0 7 0 0 -5 4 0 0 3 0 0 6
8 5 -100 5 0 0 6 0 0 3 8 0 0 7 0 0 -5 4 0 0 3 0 0 -82
*/
/*7
5 1
5
8 2 4
6
8 5 -100 5*/
//每次全部遍历节点之前的值求和，路径放入a数组
int a[2000001], b[2000001];
int j = 0, ans = 10000; //记录最小的路径
inline int read()
{
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
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
	x = read();
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
	else
		return;
}
void tranverse(Tree *root, int sum)
{
	/*for(int i=0;i<j;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");*/
	if(root==NULL)
		return;
	Tree *p = root;
	int x = 0;
	j = 0; // j与ans比较位数
	while (p != NULL)//对每个结点求前序和 
	{
		b[j++] = p->data;
		x += p->data;
		if (x == sum && j <= ans)
		{
			for (int i = 0; i < j; i++)
			{
				a[i] = b[i];//将b数组赋值a数组
			}
			ans = j;
		}
			p = p->father;
	}
		tranverse(root->left, sum);
		tranverse(root->right, sum);
}
int main()
{
	int n;
	n = read();
	while (n--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b)); 
		int sum;
		Tree *ct;
		ct = buildTree(ct);
		sum = read();
		tranverse(ct, sum);
		if (ans !=10000&&ans!=0)
			for (int i = ans-1; i >= 0; i--)
			{
				printf("%d ", a[i]);
			}
		else
			printf("no available path");
		printf("\n");
		ans = 10000;
	}
	return 0;
}
