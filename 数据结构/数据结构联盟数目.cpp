#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
//用邻接表存储的图
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
ptrEdge arr[200]; //边链表的头指针
int markedlist[200], wsm[200][200], edge[200][200];
void initial(ptrEdge *arr, int num) //初始化
{
	for (int i = 1; i <= num; i++)
	{
		arr[i] = (ptrEdge)malloc(sizeof(struct Edge));
		arr[i]->VerAdj = i;
		arr[i]->link = NULL;
	}
}
void insert(ptrEdge s, int pos)
{
	ptrEdge tmp = (ptrEdge)malloc(sizeof(struct Edge));
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
void Warshall(int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i == j)
				wsm[i][j] = 1;
			else if (i != j && edge[i][j] == 1)
				wsm[i][j] = 1;
			else
				wsm[i][j] = 0;
		}
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			if (wsm[i][k] == 1)
			{
				for (j = 1; j <= n; j++)
				{
					if (wsm[i][j] || wsm[k][j])
						wsm[i][j] = 1;
				}
			}
		}
	}
}
void allcomponent(int n)
{
	for (int k = 1; k <= n; k++)
	{
		markedlist[k] = 0;
	}
	Warshall(n);
	int t = 0;
	for (int v = 1; v <= n; v++)
	{
		if (markedlist[v] == 0)
		{
			t += 1;
			markedlist[v] = 1;
			ptrEdge sc = (ptrEdge)malloc(sizeof(struct Edge));
			sc->VerAdj = v;
			sc->link = NULL;
			ptrEdge q = sc;
			for (int i = 1; i <= n; i++)
			{
				if (i != v && wsm[v][i] == 1 && wsm[i][v] == 1)
				{
					markedlist[i] = 1;
					ptrEdge p = (ptrEdge)malloc(sizeof(struct Edge));
					p->VerAdj = i;
					p->link = NULL;
					q->link = p;
					q = p;
				}
			}
			while (sc != NULL)
			{
				q = sc;
				sc = sc->link;
				delete q;
			}
		}
	}
	printf("%d\n", t);
}
int main()
{
	int n, t0, x;
	cin >> t0;
	while (t0--)
	{
		cin >> n;
		initial(arr, n);
		for (int i = 1; i <= n; i++)
		{
			while (1)
			{
				cin >> x;
				if (x == 0)
					break;
				insert(arr[i], x);
				edge[i][x] = 1;
			}
		}
		for (int k = 1; k <= n; k++)
		{
			markedlist[k] = 0;
		}
		allcomponent(n);
		memset(wsm, 0, sizeof(wsm));
		memset(edge, 0, sizeof(edge));
		memset(markedlist, 0, sizeof(markedlist));
	}
	return 0;
}
