#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Tree, *ptr;
Tree *root;
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
void insertNode(Tree *&t, int ans)
{
	if (t == NULL)
	{
		t = new Tree();
		t->data = ans;
	}
	else if (ans < t->data)
		insertNode(t->left, ans);
	else if (ans > t->data)
		insertNode(t->right, ans);
}
Tree *find1(Tree *p, int ans)
{
	if (p == NULL)
		return NULL;
	else if (p->data == ans)
		return p;
	else if (ans < p->data)
		find1(p->left, ans);
	else if (ans > p->data)
		find1(p->right, ans);
}
Tree *find2(Tree *p, int ans)
{
	if (p == NULL || p->data == ans)
	{
		// cout<<"asgfdsfh";
		return NULL;
	}
	else if (p->left->data == ans || p->right->data == ans)
		return p;
	else if (ans < p->data)
		find2(p->left, ans);
	else if (ans > p->data)
		find2(p->right, ans);
}
void remove(Tree *&t, int k)
{
	if (t == NULL)
		return;
	if (k < t->data)
		remove(t->left, k);
	else if (k > t->data)
		remove(t->right, k);
	else if (t->left == NULL || t->right == NULL)
	{
		Tree *tmp = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete tmp;
	}
	else if (t->right->left == NULL)
	{
		Tree *s = t->right;
		s->left = t->left;
		delete t;
		t = s;
	}
	else
	{ // K有2个子结点且右孩子的左孩子不空
		Tree *r, *s = t->right;
		while (s->left != NULL)
		{
			r = s;
			s = s->left;
		}
		r->left = s->right;
		s->left = t->left;
		s->right = t->right;
		delete t;
		t = s;
	}
}
void removeNode(int ans)
{
	Tree *q = find1(root, ans);
	Tree *q_father = find2(root, ans);
	if (NULL == q)
		return;
	// cout<<"dgsafhg";
	if (NULL == q_father && q != NULL)
	{
		goto flag;
	}
	// cout<<"dgsafhg";
	if (q->left == NULL && q->right == NULL)
	{
		// cout<<"dgsafhg";
		q_father->left = NULL;
		free(q);
	}
	else if (q->left != NULL && q->right == NULL)
	{
		q_father->left = q->left;
		free(q);
	}
	else if (q->right != NULL && q->left == NULL)
	{
		// cout<<"dgsafhg";
		q_father->right = q->right;
		free(q);
	}
	else
	{
	flag:
		Tree *r = q->right;
		int pos = r->data;
		Tree *r_father = find2(root, pos);
		// cout<<r_father->data<<endl;
		// cout<<r_father->left->data<<endl;
		while (r->left != NULL)
		{
			r = r->left;
		}
		q->data = r->data;
		if (r->left == NULL && r->right == NULL)
		{
			r_father->left = NULL;
			free(r);
		}
		else if (r->right != NULL && r->left == NULL)
		{
			r_father->left = r->right;
			// cout<<r_father->left->data<<endl;
			free(r);
		}
	}
}
int main()
{
	int t;
	cin >> t;
	char s[7];
	int num;
	root = new Tree();
	cin >> s >> num;
	root->data = num;
	t--;
	while (t--)
	{
		cin >> s >> num;
		if (s[0] == 'I')
		{
			insertNode(root, num);
		}
		else if (s[0] == 'R')
		{
			remove(root,num);
		}
	}
	midorder(root);
	printf("\n\n");
	preorder(root);
	return 0;
}
