#include <bits/stdc++.h>
using namespace std;
//用邻接表存储的图
typedef struct Edge //边结点的结构
{
	int VerAdj; //邻接顶点序号
	int cost;	//边的权值
	Edge *link; //指向下一个边结点的指针
} * ptrEdge;
typedef struct Vertex // 顶点表中结点的结构
{
	int VerName;	//顶点的名称
	Edge *adjacent; //边链表的头指针
} * ptrVertex;
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
void print(ptrEdge s) //输出
{
	if (s->link == NULL)
		return;
	int name = s->VerAdj;
	printf("%d:", name);
	ptrEdge p = s->link;
	while (p != NULL)
	{
		printf("(%d,%d,%d)", name, p->VerAdj, p->cost);
		p = p->link;
	}
	printf("\n");
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
int main()
{
	int n, e, k;
	cin >> n >> e;
	ptrEdge arr[20010];
	initial(arr, n);
	for (int i = 0; i < e; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		insert(arr[a], b, c);
	}
	cin >> k;
	while (k--)
	{
		int q, w;
		cin >> q >> w;
		deleteEdge(arr[q], w);
	}
	for (int i = 0; i < n; i++)
		print(arr[i]);
	return 0;
}
