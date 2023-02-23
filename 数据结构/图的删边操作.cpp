#include <bits/stdc++.h>
using namespace std;
//���ڽӱ�洢��ͼ
typedef struct Edge //�߽��Ľṹ
{
	int VerAdj; //�ڽӶ������
	int cost;	//�ߵ�Ȩֵ
	Edge *link; //ָ����һ���߽���ָ��
} * ptrEdge;
typedef struct Vertex // ������н��Ľṹ
{
	int VerName;	//���������
	Edge *adjacent; //�������ͷָ��
} * ptrVertex;
void initial(ptrEdge *arr, int num) //��ʼ��
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
	if (s->link == NULL) //���ڽӽڵ�
	{
		s->link = tmp;
		tmp->link = NULL;
		return;
	}
	ptrEdge r = s;
	ptrEdge p = s->link;
	while (p != NULL && p->VerAdj < pos) //���ڽӽڵ�����С����
	{
		r = p; //��¼ǰ��
		p = p->link;
	}
	tmp->link = p;
	r->link = tmp; //��������֮��
}
void print(ptrEdge s) //���
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
