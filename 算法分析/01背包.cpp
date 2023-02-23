#include <iostream>
using namespace std;
int m, n; //容量和数量
int a[100001];
int path[101];
int res=0;
bool pack(int *a, int m, int n,int vec,int res)
{
    if(vec>m)
	{
	   path[res]=vec-m;
	   vec=m;
    }
    if (n < 0)
        return false;
    else if (m == a[n])
    {
    	path[++res]=m;
        return true;
    }
    else if (m < a[n])
    {
        if (n == 0)
            return false;
        else
            return pack(a, m, n - 1,vec,res);
    }
    else if (m > a[n])
    {
        return pack(a, m, n - 1,vec,res) || pack(a, m - a[n], n - 1,vec,res+1);
    }
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool flag = pack(a, m, n ,m,res);
    //cout<<flag<<endl;
    //cout<<res<<endl;
    if (flag)
    {
        //cout << "true" << endl;
        int i=1;
        while(path[i]!=0)
        {
            i++;
        }
        i--;
        while(i!=1)
        {
            cout<<path[i]<<" ";
            i--;
        }
        cout<<path[i];
    }
    else
    {
        cout << "0";
    }
    //cout<<endl<<res;
}
/*5 4
1 6 2 3*/
