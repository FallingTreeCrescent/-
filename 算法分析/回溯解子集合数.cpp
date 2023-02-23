#include <iostream>
using namespace std;
int m, n, i, j;
int x[100];
int w[100];
int pos = 0;
int flag = 0;
void dfs(int s, int k) // s:当前已有和数  k:当前个数
{
    if (k > n)
        return;
    x[k] = 1;
    s += w[k];
    if (s == m)
    {
        flag = 1;
        for (int i = 1; i <= n; i++)
            printf("%d", x[i]);
        printf("\n");
    }
    else if (s < m)
    {
        dfs(s, k + 1);
    }
    x[k] = 0;
    s -= w[k];
    dfs(s, k + 1);
    return;
}
int main()
{
    int r = 0;
    int k = 1;
    int s = 0;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        r += w[i];
    }
    dfs(s, k);
    if (flag == 0)
        printf("no solution!\n");
    return 0;
}