#include <bits/stdc++.h>
using namespace std;
int parent[201], d[201], f[201], n, p[201], w[201], c[201];
void sort(int P[], int D[], int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int item = P[i];
        int item_d = D[i];
        int j = i - 1;
        while (j >= start && item > P[j])
        {
            P[j + 1] = P[j];
            D[j + 1] = D[j];
            j--;
        }
        P[j + 1] = item;
        D[j + 1] = item_d;
    }
}
void Union(int i, int j) //和不相交集合的合并（使用加权规则的合并算法)
{
    int x = parent[i] + parent[j];
    if (parent[i] > parent[j])//树j的结点个数多
    {
        parent[i] = j;
        parent[j] = x;
    }
    else
    {
        parent[j] = i;
        parent[i] = x;
    }
}
int find(int i) //使用压缩规则的查找算法
{
    int j = i;
    while (parent[j] > 0) //找到结点i所在树的树根j
    {
        j = parent[j];
    }
    int k = i;
    while (parent[k] > 0) //从结点i到树根j的路径上所有结点的PARENT(k)都变为j
    {
        int t = parent[k];
        parent[k] = j;
        k = t;
    }
    return j;
}
int main()
{
    int total = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i] >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        w[i] = p[i];
    }
    sort(p, d, 1, n);
    vector<int> res;
    for (int i = 0; i <= n; ++i)// FJS
    {
        f[i] = i;
        parent[i] = -1;
    }
    for (int i = 1; i <= n; ++i) // FJS
    {
        int j = find(min(n, d[i]));
        if (f[j] != 0)
        {
            res.push_back(i);
            c[j] = i;
            int l = find(f[j] - 1); //期限j前面的最大可用时间片被占用，需更新其最大可用时间片
            Union(l, j);
            f[j] = f[l];
        }
    }
    for (int re : res)
    {
        total += p[re];
    }
    cout << total << endl;
    for (int i = 1; i <= n; i++)
    {
        int k = c[i];
        for (int j = 1; j <= n; j++)
        {
            if (w[j] == p[k])
                cout << j;
        }
        if (c[i + 1] != 0)
            cout << ' ';
    }
    return 0;
}
