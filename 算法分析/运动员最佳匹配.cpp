#include <iostream>
using namespace std;
int n;
int Q[26][26], P[26][26];
int PQ[26][26], pre[26];
int op[26], X[26];
int tmpprice, sum;
void dfs(int t)
{
    if (t > n) //³ö¿Ú
    {
        if (tmpprice > sum)
        {
            sum = tmpprice;
            for (int i = 1; i <= n; i++)
            {
                op[i] = X[i];
            }
        }
        return;
    }
    else
    {
        int tmpSum = 0;
        for (int i = t; i <= n; i++)
        {
            tmpSum += pre[i];
        }
        if (tmpprice + tmpSum < sum)
            return;
        for (int i = t; i <= n; i++)
        {
            swap(X[i], X[t]);
            tmpprice += PQ[t][X[t]];
            dfs(t + 1);
            tmpprice -= PQ[t][X[t]];
            swap(X[i], X[t]);
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        X[i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &P[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &Q[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            PQ[i][j] = P[i][j] * Q[j][i];
            pre[i] = max(pre[i], PQ[i][j]);
        }
    }
    tmpprice = 0, sum = 0;
    dfs(1);
    cout << sum << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << op[i];
        if (i != n)
            cout << endl;
    }
    return 0;
}