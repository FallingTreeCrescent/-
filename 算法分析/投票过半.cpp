#include <bits/stdc++.h>
using namespace std;
int a[5001];
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
	memset(a,0,sizeof(a));
	char ch='[' ;
	int n=0;
	ch=getchar();
	while(ch!=']')
	{
		scanf("%d",&a[n]);
		n++;
		ch=getchar();
	}
	qsort(0,n-1);
	/*for(int i=0;i<=n-1;i++)
	{
		cout<<a[i]<<" ";
	}*/
	//cout<<endl;
	int ans=(n-1)/2;
	//cout<<ans<<endl;
	int tmp=a[0];
	int x=1,flag=0;
	for(int i=1;i<=n-1;i++)
	{
		//cout<<x<<"aaa";
		if(tmp==a[i])
		{
			x++;
		}
		else
		{
			x=1,tmp=a[i];
		}
		if(x>ans)
		{
			cout<<tmp;
			flag=1;
			break;
		}
	}
	if(flag==0)cout<<"NA";
	return 0;
}
