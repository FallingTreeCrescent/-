#include <iostream>
#include <cstring>
using namespace std;
int a[210];
void qsort(int l, int r)
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
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    qsort(1,n);
    /*for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;*/
    long long minSum=a[1],maxSum=a[n];
    for(int i=2;i<=n;i++)
    {
        cout<<minSum<<" ";
        if(minSum==a[1])
        {
            minSum+=a[i];
        }
        else
        minSum+=minSum+a[i];
    }
    cout<<minSum<<" ";
    for(int i=n-1;i>=1;i--)
    {
        //cout<<maxSum<<" ";
        if(maxSum==a[n])
        {
            maxSum+=a[i];
        }
        else
        maxSum+=maxSum+a[i];
    }
    cout<<maxSum;
    return 0;
}