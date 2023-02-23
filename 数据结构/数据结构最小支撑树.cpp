#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline int read() //快读
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
struct node
{
	int left, right, weight; //左点，右点，边值
} e[2005];
bool cmp(const node &x, const node &y)
{
	return x.weight < y.weight;
} //方便排序
void qsort(int l, int r)
{
	node mid = e[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while (cmp(e[i], mid))
			i++;
		while (cmp(mid, e[j]))
			j--;
		if (i <= j)
		{
			node tmp = e[i];
			e[i] = e[j];
			e[j] = tmp;
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}
int fa[2005];
int find(int x) //并查集思想
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}
int main()
{
	long long int sum = 0;
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			fa[i] = i;
		}
		for (int i = 0; i < m; i++)
		{
			e[i].left = read();
			e[i].right = read();
			e[i].weight = read();
		}
		qsort(0, m - 1);
		//sort(e, e + m, cmp); //从小到大排序
		int k = 0;
		for (int i = 0; i < m; i++)
		{
			int e1 = e[i].left;
			int e2 = e[i].right;
			int w = e[i].weight;
			e1 = find(e1), e2 = find(e2); //判断有没有连在一起
			if (e1 != e2)
			{
				sum += w; //长度的和
				fa[e2] = e1;
				k++;
			}
		}
		if (k == n - 1)
			printf("%lld\n", sum);
		else
			printf("There is no minimum spanning tree.\n");
		sum=0; 
	}
	return 0;
}
/*4 5
0 1 1
0 3 1
1 3 5
1 2 1
2 3 8
4 2
0 1 1
2 3 8
*/
/*3
There is no minimum spanning tree.
*/
