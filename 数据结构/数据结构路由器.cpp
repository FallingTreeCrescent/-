/*6 2
0 5 1 2 3 4 5
1 0
2 0
3 0
4 0
5 0
0 2
1 2
4 2
0 2 1 2
1 2 2 3
2 1 3
3 1 2
0 3
1 0*/
/*1
connection impossible
2
connection impossible*/
#include <cstdio>
#include <iostream>
using namespace std;
//用邻接矩阵存储的图
int arr[210][210];
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
void initial(int n) //初始化
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 99999; //不连通
			}
		}
	}
}
void find(int n) //找路径最小值
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i][k] != 99999)
				for (int j = 0; j < n; j++)
				{
					if (arr[k][j] != 99999)
						arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
				}
		}
	}
}
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		initial(n);
		for (int i = 0; i < n; i++)
		{
			int k;
			k = read();
			// for(int j=1;j<=k;j++)
			while (k--)
			{
				int pos;
				pos = read();
				arr[i][pos] = 1;
			}
		}
		find(n);
		while (m--)
		{
			int o, y;
			o = read();
			y = read();
			if (arr[o][y] == 99999)
				printf("connection impossible\n");
			else
				printf("%d\n", arr[o][y]);
		}
	}
	return 0;
}
