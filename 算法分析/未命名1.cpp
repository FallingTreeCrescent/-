#include <iostream>
using namespace std;
int c[20001],b[20001];
void qsort(int a[] ,int l, int r)
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
		qsort(c, l, j);
	if (i < r)
		qsort(c, i, r);
}
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	qsort(c,1,m);
	qsort(b,1,n);
	int sum=0,j=1;
	for(int i=1;i<=n&&j<=m;i++)
	{
		while(j<=m)
		{
			if(c[j]>=b[i])
		    {
				sum++,j++;
				break;
			}
			else j++;
		}
		if(j>m) break;
	}
	cout<<sum;
	return 0;
}
/*5 5
5 4 2 3 1
1 3 2 4 5*/

