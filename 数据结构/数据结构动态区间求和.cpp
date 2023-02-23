#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long int a[2000005], tree[4000005];									  //视频B站 正月点灯笼线段树
void buildTree(long long int *arr, long long int *tree, int root, int start, int end) //建树 (数组转化成树)
{
	if (start == end)
		tree[root] = arr[end]; //递归出口
	else
	{
		int mid = (start + end) / 2;
		int left = root * 2 + 1;  //画线段树左儿子2*n+1
		int right = root * 2 + 2; //画线段树右儿子2*n+2
		buildTree(arr, tree, left, start, mid);
		buildTree(arr, tree, right, mid + 1, end);
		tree[root] = tree[left] + tree[right]; //自下往上求和
	}
}
void changeTree(long long int *arr, long long int *tree, int root, int start, int end, int pos, int num) //实现一个元素的修改，即改一条路径
{																					 // pos表示要改的数组下标，num表示要改的元素
	if (start == end)
	{
		arr[pos] = num;
		tree[root] = num;
	}
	else
	{
		int mid = (start + end) / 2;
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		if (pos >= start && pos <= mid)
		{
			changeTree(arr, tree, left, start, mid, pos, num); // pos在左分支改左分支
		}
		else
		{
			changeTree(arr, tree, right, mid + 1, end, pos, num); // pos在右分支改右分支
		}
		tree[root] = tree[left] + tree[right];
	}
}
long long sumTree(long long int *arr, long long int *tree, int root, int start, int end, int l, int r) //实现区间求和，l表示区间起点,r区间终点
{
	if (r < start || l > end) //当一开始区间就不在数组范围内
	{
		return 0;
	}
	else if (l <= start && r >= end) //递归出口最后start和end在l~r范围内
	{
		return tree[root];
	}
	else if (start == end)
	{
		return tree[root];
	}
	else
	{
		int mid = (start + end) / 2;
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		long long sum_left = sumTree(arr, tree, left, start, mid, l, r);	 //计算左区间包含数的和
		long long sum_right = sumTree(arr, tree, right, mid + 1, end, l, r); //计算右区间包含数的和
		return sum_left + sum_right;
	}
}
int main()
{
	// memset(a,0,sizeof(a));
	// memset(tree,0,sizeof(tree));
	long long sum = 0;
	int n, q, flag, i, x, l, r;
	scanf("%d%d", &n, &q);
	for (int j = 1; j <= n; j++)
		scanf("%lld", &a[j]);
	buildTree(a, tree, 1, 1, n);
	while (q--)
	{
		scanf("%d", &flag);
		if (flag == 1)
		{
			scanf("%d%d", &i, &x);
			changeTree(a, tree, 1, 1, n, i, a[i] + x); //改值
		}
		else if (flag == 2)
		{
			scanf("%d%d", &l, &r);
			sum = sumTree(a, tree, 1, 1, n, l, r); //求区间和
			printf("%lld\n", sum);
		}
	}
	return 0;
}
/*6 4
1 2 3 4 5 6
1 2 -1
2 2 3
2 1 3
2 1 6*/
