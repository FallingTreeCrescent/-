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
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
ptrEdge arr[2100]; //边链表的头指针
int topo[2100], ve[2100], vl[2100], m = 0, flag = 0;
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
			memset(count,0,sizeof(count));
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
	memset(count,0,sizeof(count));
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
int main()
{
	int n, e;
	while (cin >> n >> e)
	{
		initial(arr, n);
		for (int i = 1; i <= e; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			insert(arr[a], b, c);
		}
		TopoSort(arr, n);
		criticalpath(arr, n);
		/*for (int i = 1; i <= n; i++)
		{
			cout << ve[i] << " ";
		}
		printf("\n");
		for (int i = 1; i <= n; i++)
		{
			cout << vl[i] << " ";
		}*/
		memset(topo,0,sizeof(topo));
		memset(ve,0,sizeof(ve));
		memset(vl,0,sizeof(vl));
		m=0;
	}
	return 0;
}
/*4 4
1 2 6
1 3 4
2 4 1
3 4 1*/
/*7
1->2
2->4*/

/*9 11
1 2 6
1 3 4
1 4 5
4 6 2
3 5 1
2 5 1
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4*/
/*18
1->2
2->5
5->7
5->8
7->9
8->9*/

/*9 11
1 2 6
1 3 4
1 4 5
4 6 2
3 5 1
2 5 1
5 7 9
5 8 7
6 8 4
7 9 2
8 4 4*/
// unworkable project
