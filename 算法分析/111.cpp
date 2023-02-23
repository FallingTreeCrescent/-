#include <iostream>
using namespace std;

int n, p[26][26], q[26][26];
int s = 0, sum = 0, pos = 0;
bool vis[26]; //列的访问标记
int res[26][2];
void dfs(int x, int y)
{
    s += p[x][y] * q[y][x];
    res[x][0]=x,res[x][1]=y;
    vis[y] = 1;
    if (x == n)
    {
        sum = s > sum ? s : sum;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(x + 1, i);
            s -= p[x + 1][i] * q[i][x + 1];
            vis[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &q[i][j]);
    dfs(0, 0);
    printf("%d\n", sum);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", res[i][0], res[i][1]);
    }
    return 0;
}