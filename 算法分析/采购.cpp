#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int v[1001], w[1001], f[100001]; //需要度和价格和规划
int n, m;                        //商品数和预算
int res[1001];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    /*for (int i = 1; i <= m; i++)
    {
        cout<<f[i]<<" ";
    }*/
    printf("%d\n", f[m]);
    int j = m;
    /*for (int i = n; i >=1; i--)
    {
        if(f[j-1]==f[j])
        {
            res[i]=0;
        }
    }*/
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", res[i]);
    }
    return 0;
}
/*3 10
4 5 6
3 4 5
0 0 4 5 6 8 9 10 12 13*/
