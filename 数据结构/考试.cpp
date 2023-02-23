#include <cstdio>
#include <iostream>
using namespace std;
inline int read()
{ //快读
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
void qsort(int l, int r)
{
	int mid = a[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while (a[i] < mid)
			i++;
		while (a[j] > mid)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}
int pd(int n)
{
	if (n == 1)
		return 0;
	else
	{
		for (int i = 2; i < sqrt(n); i++)
		{
			if (n % i == 0)
				return 0;
		}
	}
	return 1;
} //判断质数
string s, p;
int f[100005];
void fail()
{
	int lengthP = p.length();
	f[0] = -1;
	for (int j = 1; j < lengthP; j++)
	{
		int i = f[j - 1];
		while (p[j] != p[i + 1] && i >= 0)
			i = f[i];
		if (p[j] == p[i + 1])
			f[j] = i + 1;
		else
			f[j] = -1;
	}
}
int kmp()
{
	int i = 0, j = 0;
	int m = p.length();
	int n = s.length();
	while (i < m && j < n)
	{
		if (p[i] == s[j])
		{
			i++;
			j++;
		}
		else
		{
			if (i == 0)
				j++;
			else
				i = f[i - 1] + 1;
		}
	}
	if (i < m)
		return -1;
	else
		return j - m;
}
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
void initial(ptrEdge *arr, int num) //初始化
{
	for (int i = 0; i < num; i++)
	{
		arr[i] = (ptrEdge)malloc(sizeof(struct Edge));
		arr[i]->VerAdj = i;
		arr[i]->cost = 0;
		arr[i]->link = NULL;
	}
}
void insert(ptrEdge s, int pos, int loc)
{
	ptrEdge tmp = (ptrEdge)malloc(sizeof(struct Edge));
	tmp->cost = loc;
	tmp->VerAdj = pos;
	if (s->link == NULL) //无邻接节点
	{
		s->link = tmp;
		tmp->link = NULL;
		return;
	}
	ptrEdge r = s;
	ptrEdge p = s->link;
	while (p != NULL && p->VerAdj < pos) //有邻接节点找最小插入
	{
		r = p; //记录前驱
		p = p->link;
	}
	tmp->link = p;
	r->link = tmp; //插入两个之间
}
void deleteEdge(ptrEdge s, int pos)
{
	ptrEdge p = s->link;
	if (p->cost == pos)
	{
		s->link = p->link;
		free(p);
		return;
	}
	ptrEdge r = s;
	while (p != NULL && p->VerAdj != pos)
	{
		r = p;
		p = p->link;
	}
	r->link = p->link;
	free(p);
}
void TopoSort(ptrEdge *arr, int n) // 有向图的拓扑排序算法
{
	int count[2100]; // 计算count数组，存各顶点入度
	ptrEdge p;
	for (int i = 1; i <= n; i++)
	{
		count[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ptrEdge p = arr[i]->link; //找每个顶点邻接节点
		while (p != NULL)		  //计算每个点的入度
		{
			int k = p->VerAdj;
			count[k] += 1;
			p = p->link;
		}
	}
	int top = 0;
	for (int i = 1; i <= n; i++)
	{
		if (count[i] == 0) //入栈
		{
			count[i] = top;
			top = i;
		}
	}
	for (int i = 1; i <= n; i++) //拓扑排序
	{
		if (top == 0)
		{
			printf("unworkable project\n");
			flag = 1;
			memset(count, 0, sizeof(count));
			break;
		}
		int j = top; //出栈
		top = count[top];
		topo[++m] = j; //选出入度为0的顶点并保存进入拓扑排序数组
		p = arr[j]->link;
		while (p != NULL)
		{
			int k = p->VerAdj;
			count[k] -= 1;
			if (count[k] == 0)
			{
				count[k] = top;
				top = k;
			}
			p = p->link;
		}
	}
	memset(count, 0, sizeof(count));
}
void criticalpath(ptrEdge *arr, int n)
{
	if (flag == 1)
	{
		goto emmmmm;
	}
	ptrEdge p;
	/*计算顶点的最早发生时间*/
	for (int i = 1; i <= n; i++)
	{
		ve[i] = 0;
	}
	//按拓扑序计算各顶点最早发生时间
	for (int i = 1; i <= n - 1; i++)
	{
		int u = topo[i];
		p = arr[u]->link;
		while (p != NULL)
		{
			int k = p->VerAdj;
			if (ve[u] + p->cost > ve[k])
			{
				ve[k] = ve[u] + p->cost;
			}
			p = p->link;
		}
	}
	//计算顶点的最迟发生时间
	for (int i = 1; i <= n; i++)
	{
		vl[i] = ve[n];
	}
	for (int i = n - 1; i >= 1; i--)
	{
		int u = topo[i];
		p = arr[u]->link;
		while (p != NULL)
		{
			int k = p->VerAdj;
			if (vl[k] - p->cost < vl[u])
			{
				vl[u] = vl[k] - p->cost;
			}
			p = p->link;
		}
	}
	printf("%d\n", vl[n]);
	//求诸活动的最早开始时间和最迟开始时间
	for (int i = 1; i <= n - 1; i++)
	{
		p = arr[i]->link;
		while (p != NULL)
		{
			int k = p->VerAdj;
			int e = ve[i];
			int l = vl[k] - p->cost;
			if (l == e)
			{
				printf("%d->%d\n", i, k);
			}
			p = p->link;
		}
	}
emmmmm:
	flag = 0;
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
int height(Tree *root)
{
	if (root == NULL)
		return 0;
	else
		return height(root->left) > height(root->right) ? (1 + height(root->left)) : (1 + height(root->right));
}
int pd(Tree *root, int high) //判断是否处于底层
{
	Tree *p = root;
	int m = high;
	while (p->father != NULL)
	{
		p = p->father;
		m--;
	}
	if (m - 1 == 0)
		return 1;
	return 0;
}
char *multiply(char *num1, char *num2)
{
	int a[201], b[201], c[4001], i, j, len;
	char res[4001];
	a[0] = strlen(num1), b[0] = strlen(num2); //计算长度
	for (i = 1; i <= a[0]; i++)
	{
		a[i] = num1[a[0] - i] - '0';
	}
	for (i = 1; i <= b[0]; i++)
	{
		b[i] = num2[b[0] - i] - '0';
	} //将字符串转换成数字
	for (i = 1; i <= a[0]; i++)
		for (j = 1; j <= b[0]; j++)
			c[i + j - 1] += a[i] * b[j]; //按乘法
	len = a[0] + b[0];					 //原理进行高精乘
	for (i = 1; i < len; i++)
		if (c[i] > 9)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		} //进位
	while (c[len] == 0 && len > 1)
		len--; //判断位数
	j = 0;
	for (i = len; i >= 1; i--, j++)
		res[j] = c[i] + '0';
	res[j++] = 0;
	return res;
}
int main()
{
	cin >> s >> p;
	cout << kmp();
	return 0;
}
