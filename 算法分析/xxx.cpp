#include <iostream>
#include <cstring>
using namespace std;
int a[505];
void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            cout << a[i];
        else
            cout << "+" << a[i];
    }
    cout << endl;
}
void dfs(int num, int pos)
{
    for (int i = 1; i <= num / 2; i++)
    {
        if (i >= a[pos - 1])
        {
            a[pos] = i;
            a[pos + 1] = num - i;
            print(pos + 1);
            dfs(num - i, pos + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(n, 1);
    return 0;
}