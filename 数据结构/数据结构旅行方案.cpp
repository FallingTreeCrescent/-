#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
int b[100005], sum;
int read()
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
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
ptrEdge arr[100010];
void initial(ptrEdge *arr, int num) //初始化
{
	for (int i = 1; i <= num; i++)
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
	tmp->link = s->link;
	s->link = tmp; //插入两个之间
}
void DFS(ptrEdge *arr, int x, int num, int l)
{
	b[x] = 1;
	if (num == 0 || l < 0)
	{
		return;
	}
	sum++;
	ptrEdge p = arr[x]->link;
	while (p != NULL) // x后邻接节点个数
	{
		if (b[p->VerAdj] == 0)
		{
			DFS(arr, p->VerAdj, num - 1, l - p->cost); //每走一步长度减一
		}
		p = p->link;
	}
}
int main()
{
	int n, m, l;
	while (cin >> n >> m)
	{
		initial(arr, n);
		while (m--)
		{
			int a, b, c;
			a = read();
			b = read();
			c = read();
			insert(arr[a], b, c);
			insert(arr[b], a, c);
		}
		cin >> l;
		sum = n;
		for (int j = 1; j <= n; j++)
		{
			DFS(arr, j, n, l);
			memset(b, 0, sizeof(b));
		}
		cout << sum / 2 << endl;
	}
	return 0;
}

