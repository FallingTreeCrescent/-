#include <bits/stdc++.h>
using namespace std;
//用邻接矩阵存储的图
int arr[110][110],b[110];
inline int read() 
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch>'9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
void initial(int n) //初始化
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 99999; //不连通
			}
		}
	}
}
void find(int n) //找路径最小值
{
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if(arr[i][k]!=99999)
			for (int j = 0; j < n; j++)
			{
				if(arr[k][j]!=99999)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
}
int main()
{
	int n, e, k;
	while(cin>>n>>e)
{
	initial(n);
	while(e--)
	{
		int a, b, c;
		a=read();b=read();c=read();
		arr[a][b] = min(c, arr[a][b]);
		arr[b][a] = arr[a][b];
	}
	find(n);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			b[i]+=arr[i][j];
		}
		if(b[ans]>b[i])
		{
			ans=i;
		}
	}
	printf("%d\n", ans);
	memset(b,0,sizeof(b));
}
	return 0;
}
