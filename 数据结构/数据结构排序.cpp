#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[50001], b[50001];
void qsort(int l, int r) //快速排序（头和尾）
{
	int mid = a[(l + r) / 2]; //中间数,注意不能用mid=(l+r)/2,不然递归会出问题
	int i = l, j = r;
	do
	{
		while (a[i] < mid)
			i++; //查找左半部分比中间数大的数
		while (a[j] > mid)
			j--;	//查找右半部分比中间数小的数
		if (i <= j) //如果有一组不满足排序条件（左小右大）的数
		{
			swap(a[i], a[j]); //交换
			i++;
			j--;
		}
	} while (i <= j); //这里注意要有=
	if (l < j)
		qsort(l, j); //递归搜索左半部分
	if (i < r)
		qsort(i, r); //递归搜索右半部分
} //时间复杂度正序反序平均nlbn,n2,nlbn，不稳定，空间复杂度lbn~n
void insertsort(int length) //插排
{
	for (int i = 2; i <= length; i++)
	{
		a[0] = a[i]; //哨兵临时存放要插入的数据
		int j;
		for (j = i - 1; a[0] < a[j]; j--)
		{
			a[j + 1] = a[j]; //找到要插入的位置
		}
		a[j + 1] = a[0]; //插入
	}
} //时间复杂度正序反序平均n,n2,n2，稳定，空间复杂度1
void shellsort(int n)				//希尔排序
{									//待数组基本有序时对全体进行插排，对插排的优化
	int d;							//表示间隔
	for (d = n / 2; d >= 1; d /= 2) //分组
	{
		for (int i = d + 1; i <= n; i++) //对组内排序
		{
			a[0] = a[i];   //哨兵记录初始值
			int j = i - d; //定位需要交换的值看是否需要交换
			while (j > 0 && a[0] < a[j])
			{
				a[j + d] = a[j]; //找到要插入的位置
				j -= d;
			}				 //至下标越界或第一次比较不用交换退出循环
			a[j + d] = a[0]; //插入
		}
	} //手动模拟，d=1时就是插排算法
} //时间复杂度正序反序平均n1.3,n2,nlbn~n2，不稳定，空间复杂度1
void bubblesort1(int n) //冒泡排序1 第一趟排序把最大数放最后面
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i + 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
} //时间复杂度正序反序平均n2,n2,n2，稳定，空间复杂度1
void bubblesort2(int n) //冒泡排序2
{
	int swap = n;	  //记录在一次冒泡中，最后交换记录的位置
	while (swap != 0) //如果最后一次循环没有交换，那么swap为0退出循环提前结束，对有序数组一趟跑完
	{
		int bound = swap; // bound记录无序区序列的最后一个位置
		swap = 0;
		for (int j = 1; j < bound; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				swap = j;
			}
		}
	}
} //时间复杂度正序反序平均n,n2,n2，稳定，空间复杂度1
void selection(int n) //选择排序
{
	for (int i = 1; i < n; i++)
	{
		int index = i; //关键最小码在i处,往后扫一遍看是否有最小值不在i处，不在则交换
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[index])
				index = j;
		} //找最小值的位置
		if (i != index)
		{
			int tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
	}
} //时间复杂度正序反序平均n2,n2,n2，不稳定，空间复杂度1
void Adjust(int k, int m)
{
	int i = k;
	int j = 2 * i;
	while (j <= m)
	{
		if (j < m && a[j + 1] > a[j]) // j指向i左右节点的较大者
		{
			j++;
		}
		if (a[i] >= a[j]) //符合大根堆要求就退出循环
		{
			break;
		}
		else
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i = j; //向下一层判断直到叶节点结束
			j = 2 * i;
		}
	}
}
void heapsort(int n) //堆排序
{
	for (int i = n / 2; i >= 1; i--) //初始化大根堆
	{
		Adjust(i, n);
	}
	for (int i = 1; i < n; i++)
	{
		int tmp = a[1];
		a[1] = a[n - i + 1];
		a[n - i + 1] = tmp;
		Adjust(1, n - i); //筛选根节点重新生成大根堆
	}
} //时间复杂度正序反序平均nlbn,nlbn,nlbn，不稳定，空间复杂度1
void countsort(int n) //计数排序适合整数且集中的数据，开额外数组记录出现次数
{					  //优化可以找最小值和最大值计算开数组的大小从而减少空间浪费
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++)
	{
		b[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		while (b[i]--)
		{
			printf("%d ", i);
		}
	}
} //时间复杂度n+k
void Merge(int r[], int r1[], int s, int m, int t) //一次归并
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])
		{
			r1[k] = r[i];
			k++, i++;
		}
		else
		{
			r1[k] = r[j];
			k++, j++;
		}
	}
	while (i <= m)
	{
		r1[k] = r[i];
		k++, i++;
	}
	while (j <= t)
	{
		r1[k] = r[j];
		k++, j++;
	}
}
void MergePass(int r[], int r1[], int n, int h)
{ //一趟归并排序，r为待归并序列，r1为临时空间，h为完整子序列长度
	int i, k;
	i = 1;
	while (i <= n - 2 * h + 1) //可以分割出两个完整的子序列
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	if (i < n - h + 1) //可以分割出两个完整的子序列，第一个长度为h，第二个长度小于h
	{
		Merge(r, r1, i, i + h - 1, n);
	}
	else
	{ //只能分割出1个完整的子序列，长度<=h,将r数据复制到r1中
		for (k = i; k <= n; k++)
		{
			r1[k] = r[k];
		}
	}
} //一趟归并排序复杂度为n
void Mergesort(int r[], int r1[], int n) //归并排序
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h *= 2;
		MergePass(r1, r, n, h);
		h *= 2;
	}
} //时间复杂度正序反序平均nlbn,nlbn,nlbn，稳定，空间复杂度n
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	// qsort(1, n);
	// insertsort(n);
	// shellsort(n);
	// bubblesort1(n);
	// bubblesort2(n);
	// selection(n);
	// countsort(n);
	 heapsort(n);
	//Mergesort(a, b, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
/*7
48 77 35 62 55 14 38*/
// 14 35 38 48 55 62 77
