#include <bits/stdc++.h>
using namespace std;
int w[1001], v[1001], flag[1001];
int dp[1001][1001];
int path[1001][1001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
            {
                if (dp[i][j] < dp[i][j - w[i]] + v[i])//只有dp[i][..]不是dp[i-1][..] (回退到当前行)
                {
                    dp[i][j] = dp[i][j - w[i]] + v[i];
                    path[i][j] = i;
                }
                else
                {
                    path[i][j] = path[i - 1][j];
                }
            }
            else
            {
                path[i][j] = path[i - 1][j];
            }
        }
    }
    printf("%d\n", dp[n][m]);
    int sum = dp[n][m];
    int x = n, y = m;
    while (sum != 0)
    {
        sum -= v[path[x][y]];
        flag[path[x][y]]++;
        y -= w[path[x][y]];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != n)
            printf("%d ", flag[i]);
        else
            printf("%d", flag[i]);
    }
    printf("\n");
    return 0;
}
