#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[50001], b[50001];
void Merge(int r[], int r1[], int s, int m, int t)
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
{
	int i, k;
	i = 1;
	while (i <= n - 2 * h + 1)
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	if (i < n - h + 1)
	{
		Merge(r, r1, i, i + h - 1, n);
	}
	else
	{
		for (k = i; k <= n; k++)
		{
			r1[k] = r[k];
		}
	}
}
void Mergesort(int r[], int r1[], int n)
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h *= 2;
		MergePass(r1, r, n, h);
		h *= 2;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	Mergesort(a, b, n);
	for (int i = 1; i <= n; i++)
	{
		if (i != n)
			printf("%d ", a[i]);
		else
			printf("%d", a[i]);
	}
	return 0;
}
