#include <bits/stdc++.h>
using namespace std;
//�ڽӾ����ͼ
int arr[5001][5001];
int out[5001], in[5001]; //��¼���Ⱥ����
int que[50005];			 //����
int path[50005];
int front = 0, rear = 0;
int orz = 0;
int ans; //��¼·������
inline int read()
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
void qsort(int *a, int l, int r)
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
		qsort(a, l, j);
	if (i < r)
		qsort(a, i, r);
}
int main()
{
	int n, m;
	n = read();
	m = read();
	while (m--)
	{
		int a, b;
		a = read();
		b = read();
		arr[a][b] = 1;
		out[a]++;
		in[b]++;
	}
	for (int i = 0; i < n; i++)
	{
		if (in[i] == 0)
		{
			que[rear++] = i; //������Ϊ0�ĵ�
							 // path[++orz]=i;
		}
	}
	while (front != rear) //�����Ϊ��
	{
		int a = que[front];
		path[++orz] = a;
		front++; //����
		for (int k = 0; k < n; k++)
		{
			if (arr[a][k] == 0)
				continue; //���1~2��·�����´�ѭ��
			in[k]--;	  //ÿ��һ������ȼ�һ
			if (in[k] == 0)
			{
				que[rear++] = k; //������Ϊ0�ĵ�
			}
		}
		qsort(que, front, rear - 1);
		// arr[front]~arr[rear-1]
	}
	for (int i = 1; i <= orz; i++)
	{
		printf("%d ", path[i]);
	}
	return 0;
}
/*5 4
0 1
1 2
2 3
2 4*/
/*7 6
0 1
1 2
2 4
2 3
2 5
1 6*/
// 0 1 2 3 4 5 6
/*8 7
0 1
1 2
2 3
2 7
2 5
1 6
6 4*/
// 01235647
