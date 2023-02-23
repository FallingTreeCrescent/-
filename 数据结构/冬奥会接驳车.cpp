#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
int kx[4] = {1, -1, 0, 0};
int ky[4] = {0, 0, 1, -1};
int arr[101][101];
int vis[101][101];
int n, m;
struct node
{
    int x, y, depth;
} que[10001];
int bfs(int sx, int sy, int ex, int ey)
{
    que[0].x = sx;
    que[0].y = sy;
    que[0].depth = 0;
    int head = 0, tail = 1;
    while (tail > head)
    {
        int x = que[head].x;
        int y = que[head].y;
        int step = que[head].depth;
        head++;
        if (x == ex && y == ey)
            return step;
        for (int i = 0; i <= 3; i++)
        {
            int x0 = x + kx[i], y0 = y + ky[i];
            if (x0 > 0 && x0 <= n && y0 > 0 && y0 <= m && vis[x0][y0] == 0 && arr[x0][y0] == 0)
            {
                que[tail].x = x0;
                que[tail].y = y0;
                que[tail].depth = step + 1;
                vis[x0][y0] = 1;
                tail++;
            }
        }
    }
    return -1;
}
int main()
{
    while (scanf("%d%d", &n, &m)!=EOF)
    {
        int xfirst = -1, xlast = -1, yfirst = -1, ylast = -1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] == 3)
                {
                    xfirst = i;
                    xlast = j;
                    arr[i][j] = 0;
                }
                else if (arr[i][j] == 4)
                {
                    yfirst = i;
                    ylast = j;
                    arr[i][j] = 0;
                }
            }
        }
		//cout<<xfirst<<" "<<xlast<<" "<<yfirst<<" "<<ylast<<endl;
        memset(vis, 0, sizeof(vis));
        vis[xfirst][xlast] = 1;
        int a = bfs(xfirst, xlast, yfirst, ylast);
        if (a != -1)
            printf("%d\n",a);
        else
            printf("unreachable\n");
    }
    return 0;
}
/*3 4
0 0 1 0
0 3 0 0
4 0 1 1*/
