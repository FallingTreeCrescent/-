//倍数对 如果某个下标小的元素是下标大的元素的倍数，我们称这两个元素为倍数对
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int t, n, sum = 0;
int a[100002][140], b[100002],pos[100002];
void qh()
{
    for (int i = 1; i <= n; i++)
    {
        int x = b[i];
        for (int j = 1; j <= a[x][0];j++)
         if(pos[x]<pos[a[x][j]])
             sum++;
    }
    printf("%d\n",sum);
}
void zs(){
	for (int i = 1; i <= 100001; i++)
    {
    	a[i][0]=0;
        int o = 1;
        for (int j = 1; j <= sqrt(i); j++)
        {
            int q = i% j;
            if (q == 0)
            {
            	if(i!=j*j)
            	{
            		if(j==1){
            			a[i][o++]=1;
            			a[i][0]++;
					}
            		else{
            			a[i][o++] = i/j;
                        a[i][o++]=j;
                        a[i][0]+=2;
					}
				}
				else 
				{
					if(i!=1){
					a[i][o++]=j;
                    a[i][0]++;
					}
				}
            }
        }
    }
}
inline int read()
{
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main()
{
	zs();
    t = read();
    while (t--)
    {
        n = read();
        for (int i = 1; i <= n; i++)
        {
            b[i] = read();
            pos[b[i]] = i;
        }
        qh();
        sum = 0;
    }
    
    return 0;
}
