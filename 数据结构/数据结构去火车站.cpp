#include <bits/stdc++.h>
using namespace std;
//用邻接表存储的图
int so1[20050], dist1[20050];
int so2[20050], dist2[20050];
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
ptrEdge arr[20010];
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
void DshortPath(ptrEdge *arr, int n, int v,int *so, int *dist)
{
	//计算v到其他点最小路径
	for (int i = 1; i <= n; i++)//初始化 
	{
		dist[i] = 2147483647;
		so[i] = 0;
	}
	dist[v] = 0;
	so[v] = 1;
	ptrEdge p = arr[v]->link;
	int u = v;
	//求从初始顶点v到其他顶点的最短路径
	for (int j = 1; j <= n - 1; j++)
	{
		while (p != NULL)//持续更新这个头结点的邻接节点 
		{
			int k = p->VerAdj;
			if (so[k] != 1 && dist[u] + p->cost < dist[k])
			{
				dist[k] = dist[u] + p->cost;
			}
			p = p->link;
		}
		int idist = 2147483647;
		for (int i = 1; i <= n; i++)//找到权值最小的未到过的点进入下次循环 
		{
			if (dist[i] < idist && so[i] == 0)
			{
				idist = dist[i];
				u = i;
			}
		}
		so[u] = 1;
		p = arr[u]->link;
	}
}
int main()
{
	int n, s, t, m, k; //车站数目，小明所在的站，火车站，公交路线
	while (~scanf("%d%d%d",&n,&s,&t))
	{
		initial(arr, n);
		scanf("%d",&m);
		while (m--)
		{
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			insert(arr[a], b, c);
			insert(arr[b], a, c);
		}
		scanf("%d",&k);
		DshortPath(arr, n, s,so1,dist1);
		DshortPath(arr, n, t,so2,dist2);
		int xxx = -1; //记录编号最小
		int sum1 = dist1[t];
		while (k--)
		{
			int x, y, z,flag;
			scanf("%d%d%d",&x,&y,&z);
			int tmp1=dist1[x];
			int tmp2=dist2[y];
			if(tmp1+tmp2+z<sum1)
			{
				sum1=tmp1+tmp2+z;
				xxx=x;
			}
			int tmp3=dist1[y];
			int tmp4=dist2[x];
			if(tmp3+tmp4+z<sum1)
			{
				sum1=tmp3+tmp4+z;
				xxx=y;
			}
			if(tmp1+tmp2==tmp3+tmp4&&tmp1+tmp2+z<dist1[t])
			{
				xxx=x>y?y:x;
				sum1=tmp1+tmp2+z;
			}
		}
		printf("%d\n",sum1);
		if(xxx==-1)printf("no metro\n");
		else printf("%d\n", xxx);
	}
	return 0;
}
