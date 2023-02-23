#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std; 
//���ڽӱ�洢��ͼ
typedef struct Edge //�߽��Ľṹ
{
	int VerAdj; //�ڽӶ������
	int cost;	//�ߵ�Ȩֵ
	Edge *link; //ָ����һ���߽���ָ��
} * ptrEdge;
ptrEdge arr[2100]; //�������ͷָ��
int topo[2100], ve[2100], vl[2100], m = 0, flag = 0;
void initial(ptrEdge *arr, int num) //��ʼ��
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
void TopoSort(ptrEdge *arr, int n) // ����ͼ�����������㷨
{
	int count[2100]; // ����count���飬����������
	ptrEdge p;
	for (int i = 1; i <= n; i++)
	{
		count[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		ptrEdge p = arr[i]->link; //��ÿ�������ڽӽڵ�
		while (p != NULL)		  //����ÿ��������
		{
			int k = p->VerAdj;
			count[k] += 1;
			p = p->link;
		}
	}
	int top = 0;
	for (int i = 1; i <= n; i++)
	{
		if (count[i] == 0) //��ջ
		{
			count[i] = top;
			top = i;
		}
	}
	for (int i = 1; i <= n; i++) //��������
	{
		if (top == 0)
		{
			printf("unworkable project\n");
			flag = 1;
			memset(count,0,sizeof(count));
			break;
		}
		int j = top; //��ջ
		top = count[top];
		topo[++m] = j; //ѡ�����Ϊ0�Ķ��㲢�������������������
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
	/*���㶥������緢��ʱ��*/
	for (int i = 1; i <= n; i++)
	{
		ve[i] = 0;
	}
	//�������������������緢��ʱ��
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
	//���㶥�����ٷ���ʱ��
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
	//���������翪ʼʱ�����ٿ�ʼʱ��
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
