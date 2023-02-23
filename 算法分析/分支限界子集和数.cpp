#include <iostream>
using namespace std;
int m, n, i, j;
int x[100];
int w[100];
int pos = 1;
int flag = 0;
int res[100][100];
int dis[100];
int tmp[100];
void qsort(int l, int r)
{
    int mid = dis[(l + r) / 2];
    int i = l, j = r;
    do
    {
        while (dis[i] < mid)
            i++;
        while (dis[j] > mid)
            j--;
        if (i <= j)
        {
            int tmp1 = dis[i], tmp2 = dis[j];
            for (int k = 1; k <= tmp1; k++)
            {
                tmp[k] = res[i][k];
            }
            for (int k = 1; k <= tmp2; k++)
            {
                res[i][k] = res[j][k];
            }
            for (int k = 1; k <= tmp1; k++)
            {
                res[j][k] = tmp[k];
            }
            swap(dis[i], dis[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j)
        qsort(l, j);
    if (i < r)
        qsort(i, r);
}
void msort(int num)
{
    for (int i = 1; i < num; i++)
    {
        for (int j = 1; j < num - i + 1; j++)
        {
            if (dis[j] > dis[j + 1])
            {
                int tmp1 = dis[j + 1], tmp2 = dis[j];
                for (int k = 1; k <= tmp1; k++)
                {
                    tmp[k] = res[j + 1][k];
                }
                for (int k = 1; k <= tmp2; k++)
                {
                    res[j + 1][k] = res[j][k];
                }
                for (int k = 1; k <= tmp1; k++)
                {
                    res[j][k] = tmp[k];
                }
                int tmp3 = dis[j];
                dis[j] = dis[j + 1];
                dis[j + 1] = tmp3;
            }
        }
    }
}
void dfs(int s, int k) // s:当前已有和数  k:当前个数
{
    if (k > n)
        return;
    x[k] = 1;
    s += w[k];
    if (s == m)
    {
        j = 0;
        flag = 1;
        /*for (int i = 1; i <= n; i++)
            if(x[i]==1)printf("%d ", i);
        printf("\n");*/
        for (int i = 1; i <= n; i++)
            if (x[i] == 1)
                res[pos][++j] = i;
        dis[pos] = j;
        pos++;
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
    {
        printf("no solution!");
        return 0;
    }
    pos--;
    msort(pos);
    for (i = 1; i <= pos; i++)
    {
        for (j = 1; j <= dis[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}