#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int a[100001];
int j=0;
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
int height(Tree *root)
{
	if(root==NULL)
	return 0;
	else
	return height(root->left)>height(root->right)?(1+height(root->left)):(1+height(root->right));
}
int pd(Tree *root,int high)//判断是否处于底层 
{
	Tree *p=root;
	int m=high;
	while(p->father!=NULL)
	{
		p=p->father;
		m--;
	}
	if(m-1==0)return 1;
	return 0;
}
void tranverse(Tree *root,int high) 
{
	if(root==NULL)return;
	if(root->left==NULL&&root->right==NULL&&pd(root,high)==1)
	{
		a[j++]=root->data;
	}
	tranverse(root->left,high);
	tranverse(root->right,high);
}
int main()
{
	Tree *ct = buildTree(ct);
	int high=height(ct);
	tranverse(ct,high);
	if(j==1)
	{
		printf("0");
	}
	else
	{
		printf("%d",a[j-1]-a[0]>0?(a[j-1]-a[0]):(a[0]-a[j-1]));
		//printf("%d %d",a[j-1],a[0]);
	}
	//printf("\n%d",height(ct));
	return 0;
}
//1 2 0 5 0 0 3 6 0 0 8 0 0
//1 2 0 5 0 0 3 0 0
//8 5 -100 5 0 0 6 0 0 3 8 0 0 7 0 0 -5 4 0 0 3 0 0
//1 2 4 8 0 0 9 0 0 5 10 0 0 11 0 0 2 6 12 0 0 13 0 0 7 14 0 0 15 0 0
//1 2 4 8 20 0 0 0 9 0 0 5 10 0 0 11 0 0 2 6 12 0 0 13 0 0 7 14 0 0 15 -1000 0 0 0





















