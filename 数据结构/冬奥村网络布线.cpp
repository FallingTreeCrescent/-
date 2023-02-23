#include <bits/stdc++.h>
//每次选跨集合边（网线）最小值与当前路由器最小值相比较更新 Prim
int router[600], line[600][600];
int Vex[600], min = 2147483647, lowcost[600];
int side = 0, sum = 0; //边和总成本
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
int Solution(int edge[][600], int *arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		Vex[i] = lowcost[i] = 0;
		if (min > arr[i])
		{
			min = arr[i];
			side = i;
		}
	} //找路由器最小的点
	Vex[side] = -1, sum += arr[side];
	for (int i = 0; i < num; i++)
		lowcost[i] = edge[side][i]; //更改这个点到其他点的长度
	for (int i = 1; i < num; i++)	//反复操作
	{
		int minline = 2147483647, sideline = -1, min = 2147483647, v;
		side = -1;
		for (int j = 0; j < num; j++)
		{
			if (Vex[j] != -1 && lowcost[j] < minline) //改边
				sideline = j, minline = lowcost[j];
			if (Vex[j] != -1 && min > arr[j]) //改点
				side = j, min = arr[j];
		}
		if (min > minline) //判断选路由器还是网线
			v = sideline, sum += minline;
		else
			v = side, sum += min;
		Vex[v] = -1, lowcost[v] = 0; //更新来过
		for (int j = 0; j < num; j++)
			if (Vex[j] != -1 && edge[v][j] < lowcost[j])
				lowcost[j] = edge[v][j];
	}
	return sum;
}
int main()
{
	int n, e, a, b, w;
	n = read();
	e = read();
	for (int i = 0; i < n; i++)
		scanf("%d", &router[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			line[i][j] = 2147483647;
	for (; e > 0; e--)
	{
		a = read();
		b = read();
		w = read();
		line[a][b] = line[b][a] = w;
	}
	printf("%d", Solution(line, router, n));
	return 0;
}
