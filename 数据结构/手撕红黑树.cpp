#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define Red 1
#define Black 0
typedef struct node
{
	int data;
	bool color;
	node *left;
	node *right;
	node *father;
} RBTree;
RBTree *root, *x, *p, *g, *u, *f, *r, *s, *n, *qr;
int getcolor(RBTree *&t)
{
	return t == NULL ? Black : t->color;
}
void preorder(node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		if (root->color == 1)
			printf("R ");
		else
			printf("B ");
		preorder(root->left);
		preorder(root->right);
	}
}
void midorder(node *root)
{
	if (root != NULL)
	{
		midorder(root->left);
		printf("%d ", root->data);
		if (root->color == 1)
			printf("R ");
		else
			printf("B ");
		midorder(root->right);
	}
}
void LL(node *&A) //右转
{
	node *B = A->left;
	B->father = A->father;
	if (B->father == NULL)
	{
		root = B;
		root->color = Black;
	}
	else
	{
		B->father->left == A ? (B->father->left = B) : (B->father->right = B);
	}
	A->left = B->right;
	if (B->right != NULL)
		B->right->father = A;
	B->right = A;
	A->father = B;
	// A = B;
	// cout << "fhgda" << endl;
}
void RR(node *&A) //左转
{
	node *B = A->right;
	B->father = A->father;
	if (B->father == NULL)
	{
		root = B;
		root->color = Black;
	}
	else
	{
		B->father->left == A ? (B->father->left = B) : (B->father->right = B);
	}
	A->right = B->left;
	if (B->left != NULL)
		B->left->father = A;
	B->left = A;
	A->father = B;
	// A = B;
	// cout << "adgafhg" << endl;
}
void RL(node *&A)
{
	LL(A->right);
	RR(A);
}
void LR(node *&A)
{
	RR(A->left);
	LL(A);
}
void fitNode(RBTree *x)
{
	if (getcolor(x->father) == Black)
		return;
	else if (x->father && getcolor(x->father) == Red)
	{
		p = x->father;
		g = p->father;
		u = (g->left == x->father) ? g->right : g->left;
		if (getcolor(u) == Black)
		{
			if (g->left && g->left->left && g->left->left == x)
			{
				LL(g);
				p->color = Black;
				p->right->color = Red;
			}
			else if (g->right && g->right->right && g->right->right == x)
			{
				RR(g);
				p->color = Black;
				p->left->color = Red;
			}
			else if (g->left && g->left->right && g->left->right == x)
			{
				RR(p);
				LL(g);
				p->father->color = Black;
				p->father->left->color = Red;
				p->father->right->color = Red;
			}
			else if (g->right && g->right->left && g->right->left == x)
			{
				LL(p);
				RR(g);
				p->father->color = Black;
				p->father->left->color = Red;
				p->father->right->color = Red;
			}
		}
		else if (getcolor(u) == Red)
		{
			p->color = Black;
			u->color = Black;
			g->color = Red;
			fitNode(g);
		}
	}
}
void insertNode(node *&x, int ans)
{
	if (x == NULL)
	{
		x = new RBTree();
		x->data = ans;
		x->color = Red;
		x->father = f;
		// cout << "afdga" << endl;
		fitNode(x);
		// cout<<"111"<<endl;
	}
	else if (ans < x->data)
	{
		f = x;
		insertNode(x->left, ans);
	}
	else if (ans > x->data)
	{
		f = x;
		insertNode(x->right, ans);
	}
	else if (ans == x->data)
		return;
}
void swap_Oper(RBTree *a, RBTree *b)
{
	if (b != NULL)
		b->father = a->father;
	if (a->father != NULL)
	{
		if (a->father->left == a)
			a->father->left = b;
		else
			a->father->right = b;
	}
	else
	{
		root = b;
	}
	delete a;
}
void RemoveNode(node *pos)
{
	if (pos == NULL)
		return;
	x = pos;
	if (x->left == NULL)
		r = x->right;
	else
		r = x->left;
	if (x->father != NULL)
	{
		p = x->father;
		if (p->left == x)
			s = p->right;
		else
			s = p->left;
	}
	else
	{
		p = NULL, s = NULL;
	}
	if (getcolor(x) == Red) //情况一：红节点必须是红叶子节点
	{
		if (x->father)
		{
			if (x->father->left == x)
				x->father->left = NULL;
			else
				x->father->right = NULL;
		}
		delete x;
		return;
	}
	else if (getcolor(x) == Black && getcolor(r) == Red)
	{
		// r替换 x
		swap_Oper(x, r);
		r->color = Black;
		return;
	}
	//双黑缺陷
	else if (getcolor(x) == Black && getcolor(r) == Black)
	{
		swap_Oper(x, r);
	flag:
		if (getcolor(s) == Black) //情况一兄弟为黑且有红孩子
		{
			// cout << "qqqqqqqqqqq" << endl;
			if (p && p->left && s && p->left == s && getcolor(s->left) == Red)
			{
				// cout << "7777777777" << endl;
				LL(p); //右转p
				s->color = p->color;
				s->left->color = Black;
				s->right->color = Black;
				return;
			}
			else if (p && p->left && s && p->left == s && getcolor(s->right) == Red)
			{
				// cout << "8888888888" << endl;
				//  LR(p); //左转s再右转p
				RR(s), LL(p);
				p->father->color = p->color;
				p->father->left->color = Black;
				p->father->right->color = Black;
				return;
			}
			else if (p && p->right && s && p->right == s && getcolor(s->right) == Red)
			{
				// cout << "999999999" << endl;
				RR(p); //左转p
				s->color = p->color;
				s->left->color = Black;
				s->right->color = Black;
				return;
			}
			else if (p && p->right && s && p->right == s && getcolor(s->left) == Red)
			{
				//	cout << "aaaaaaaaa" << endl;
				// RL(p); //右转s再左转p
				LL(s), RR(p);
				p->father->color = p->color;
				p->father->left->color = Black;
				p->father->right->color = Black;
				return;
			}
			else if (s && getcolor(s->left) == Black && getcolor(s->right) == Black) //情况二兄弟为黑且无红孩子
			{
				//	cout << "ooooooooooo" << endl;
				if (p && getcolor(p) == Red)
				{
					// cout << "bbbbbbbbbbb" << endl;
					p->color = Black;
					s->color = Red;
					return;
				}
				else if (getcolor(p) == Black)
				{
					//	cout << "ccccccccccc" << endl;
					s->color = Red;
					//继续双黑修正
					x = p;
					r = p;
					p = p->father;
					if (p != NULL)
						s = (p->left == x) ? p->right : p->left;
					else
						s = NULL;
					goto flag;
				}
			}
			// return;
		}
		else if (p && s && getcolor(s) == Red) //情况三兄弟s为红
		{
			//	cout << "pppppppppp" << endl;
			if (s == p->left)
			{
				//	cout << "ddddddddd" << endl;
				LL(p);
				s->color = Black;
				p->color = Red;
				// if (p->left->left->color == Red || p->left->right->color == Red)
				// RemoveNode(p->right, p->right->data);
				//继续双黑修正
				s = p->left;
				goto flag;
			}
			else if (s == p->right)
			{
				//	cout << "eeeeeeeee" << endl;
				RR(p);
				s->color = Black;
				p->color = Red;
				// if (p->right->left->color == Red || p->right->right->color == Red)
				// RemoveNode(p->left, p->left->data);
				//继续双黑修正
				s = p->right;
				goto flag;
			}
		}
	}
}
void removeNode(RBTree *root, int num)
{
	if (root == NULL)
	{
		return; //找不到
	}
	else if (num == root->data)
	{
		if (root->left == NULL || root->right == NULL)
		{
			x = root;
		}
		else if (root->right && root->left)
		{
			node *temp = root->right;
			while (temp != NULL && temp->left)
			{
				temp = temp->left;
			}
			root->data = temp->data;
			x = temp;
		}
		RemoveNode(x); //处理要删除节点x
	}
	else if (num < root->data)
	{
		p = root;
		removeNode(root->left, num); //左
	}
	else if (num > root->data)
	{
		p = root;
		removeNode(root->right, num); //右
	}
}
int main()
{
	int t;
	cin >> t;
	char s[7];
	int num;
	root = new RBTree();
	cin >> s >> num;
	root->data = num;
	root->color = Black;
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
			removeNode(root, num);
		}
		root->color = Black; //更新根的颜色
	}
	midorder(root);
	printf("\n\n");
	preorder(root);
	return 0;
}
/*6
Insert 8
Insert 9
Insert 3
Insert 4
Insert 5
Remove 5*/
/*-97 R -5 B 2 R 7 R 10 B 12 B 13 R 20 B 23 R 30 R 32 B 40 B 50 B 52 R 74 B 80 B 85 R 90 B 103 R 306 B 752 R

74 B 30 R 12 B 7 R -5 B -97 R 2 R 10 B 20 B 13 R 23 R 40 B 32 B 50 B 52 R 90 B 80 B 85 R 306 B 103 R 752 R*/
/*-97 R -5 B 2 R 7 R 10 B 12 B 13 R 20 B 23 R 30 R 32 B 40 B 52 B 66 B 74 B 80 B 85 B 103 R 306 B 752 R

66 B 30 R 12 B 7 R -5 B -97 R 2 R 10 B 20 B 13 R 23 R 40 B 32 B 52 B 80 B 74 B 103 R 85 B 306 B 752 R*/

