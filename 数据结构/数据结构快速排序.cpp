#include <bits/stdc++.h>
using namespace std;
int a[50001], n, o;
int position(int m, int n)
{
	int i, j, k;
	i = m, j = n + 1, k = a[m];
	while (i < j)
	{
		i += 1;
		while (a[i] <= k)
			i += 1;
		j -= 1;
		while (a[j] > k)
			j -= 1;
		if (i < j)
		{
			int tmp;
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
	int t;
	t = a[m];
	a[m] = a[j];
	a[j] = t;
	return j;
}
void qsort(int m, int n)
{
	if (m < n)
	{
		int j = position(m, n);
		for (int i = 1; i <= o; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		qsort(m, j - 1);
		qsort(j + 1, n);
	}
}
int main()
{
	scanf("%d", &n);
	o = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	a[n + 1] = 2147483647;
	qsort(1, n);
	for (int i = 1; i <= o; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
