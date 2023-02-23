#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <ctype.h>
#include <math.h>
using namespace std;
int n; //物品数量
int m; //背包容量
int c[1001][5001];
int v[10001],w[10001];
int res[10001];
void DP(int v[], int w[],int n,int m)
{
    int i, j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w[i] > j)
                c[i][j] = c[i - 1][j];
            else
                c[i][j] = max(c[i - 1][j - w[i]] + v[i], c[i - 1][j]);
        }
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    memset(c, 0, sizeof(c));
    DP(v, w, n, m);
    int j=m,sum=0;
    for(int i=n;i>=1;i--)
    {
        if(c[i][j]==c[i-1][j])
        {
            res[i]=0;
        }
        else if(c[i][j]>c[i-1][j])
        {
            res[i]=1;
            j=j-w[i];
            sum+=w[i];
        }
    }
    /*for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            printf("%-3d ", c[i][j]);
        puts("");
    }*/
    printf("%d %d\n", c[n][m],sum);
    for(int i=1;i<=n;i++)
    {
        if(i!=n)printf("%d ",res[i]);
        else printf("%d",res[i]);
    }
    return 0;
}