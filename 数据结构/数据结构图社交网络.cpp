#include <bits/stdc++.h>
using namespace std;
//���ڽӾ���洢��ͼ
int arr[110][110];
long long bx[110][110];
//       ��¼���·������  �������·����Ŀ
double sum = 0.0;
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
void initial(int n) //��ʼ��
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 2147483647; //����ͨ
			}
		}
	}
}
void find(int n) //��·����Сֵ
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i != k)
				for (int j = 1; j <= n; j++)
				{
					if (arr[k][j] != 2147483647 && arr[i][k] != 2147483647 && j != k && j != i && arr[i][k] + arr[k][j] <= arr[i][j])
					{
						if (arr[i][j] > arr[i][k] + arr[k][j])
						{
							arr[i][j] = arr[i][k] + arr[k][j];
							bx[i][j] = bx[i][k] * bx[k][j]; //����·��
						}
						else if (arr[i][j] == arr[i][k] + arr[k][j])
						{
							bx[i][j] += bx[i][k] * bx[k][j]; //��·��
						}
					}
				}
		}
	}
}
void print(int n)
{
	int i, j, k;
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i != j && i != k && k != j && arr[i][j] == arr[i][k] + arr[k][j])
					sum += (double)arr[i][j] * (double)(bx[i][k] * bx[k][j]) / (double)bx[i][j];
			}
		}
		printf("%0.3lf\n", sum);
		sum = 0.0;
	}
}
int main()
{
	int n, e, k;
	n = read();
	e = read();
	initial(n);
	while (e--)
	{
		int a, b;
		int c;
		a = read();
		b = read();
		c = read();
		arr[a][b] = c;
		arr[b][a] = c;
		bx[a][b] = 1;
		bx[b][a] = 1;
	}
	find(n);
	print(n);
	return 0;
}

