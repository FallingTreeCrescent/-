#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long int a[2000005], tree[4000005];									  //��ƵBվ ���µ�����߶���
void buildTree(long long int *arr, long long int *tree, int root, int start, int end) //���� (����ת������)
{
	if (start == end)
		tree[root] = arr[end]; //�ݹ����
	else
	{
		int mid = (start + end) / 2;
		int left = root * 2 + 1;  //���߶��������2*n+1
		int right = root * 2 + 2; //���߶����Ҷ���2*n+2
		buildTree(arr, tree, left, start, mid);
		buildTree(arr, tree, right, mid + 1, end);
		tree[root] = tree[left] + tree[right]; //�����������
	}
}
void changeTree(long long int *arr, long long int *tree, int root, int start, int end, int pos, int num) //ʵ��һ��Ԫ�ص��޸ģ�����һ��·��
{																					 // pos��ʾҪ�ĵ������±꣬num��ʾҪ�ĵ�Ԫ��
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
			changeTree(arr, tree, left, start, mid, pos, num); // pos�����֧�����֧
		}
		else
		{
			changeTree(arr, tree, right, mid + 1, end, pos, num); // pos���ҷ�֧���ҷ�֧
		}
		tree[root] = tree[left] + tree[right];
	}
}
long long sumTree(long long int *arr, long long int *tree, int root, int start, int end, int l, int r) //ʵ��������ͣ�l��ʾ�������,r�����յ�
{
	if (r < start || l > end) //��һ��ʼ����Ͳ������鷶Χ��
	{
		return 0;
	}
	else if (l <= start && r >= end) //�ݹ�������start��end��l~r��Χ��
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
		long long sum_left = sumTree(arr, tree, left, start, mid, l, r);	 //����������������ĺ�
		long long sum_right = sumTree(arr, tree, right, mid + 1, end, l, r); //����������������ĺ�
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
			changeTree(a, tree, 1, 1, n, i, a[i] + x); //��ֵ
		}
		else if (flag == 2)
		{
			scanf("%d%d", &l, &r);
			sum = sumTree(a, tree, 1, 1, n, l, r); //�������
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
