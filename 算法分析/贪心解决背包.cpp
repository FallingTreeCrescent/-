#include <iostream>
using namespace std;
struct node
{
    float m, v;
    float p;
    float flag=0.00;
    int pos;
} a[10001];
float res[10001];
void qsort(int l, int r)
{
    struct node mid = a[(l + r) / 2];
    int i = l, j = r;
    do
    {
        while (a[i].p > mid.p)
            i++;
        while (a[j].p < mid.p)
            j--;
        if (i <= j)
        {
            float tmp1=a[i].m;
            a[i].m=a[j].m;
            a[j].m=tmp1;
            float tmp2=a[i].v;
            a[i].v=a[j].v;
            a[j].v=tmp2;
            float tmp3=a[i].p;
            a[i].p=a[j].p;
            a[j].p=tmp3;
            int tmp4=a[i].pos;
            a[i].pos=a[j].pos;
            a[j].pos=tmp4;
            i++, j--;
        }
    } while (i <= j);
    if (i < r)
        qsort(i, r);
    if (j > l)
        qsort(l, j);
}
int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].m;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].p = a[i].v / a[i].m;
        a[i].pos=i;
    }
    qsort(1, n);
    /*for (int i = 1; i <= n; i++)
    {
        cout << a[i].m << " " << a[i].v;
        cout << endl;
    }*/
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m >= a[i].m)
        {
        	//cout<<"aaaa"<<endl;
            sum += a[i].v;
            m -= a[i].m;
            a[a[i].pos].flag=1.00;
        }
        else if (m < a[i].m && m > 0)
        {
            sum += m * a[i].p;
            //cout<<"m"<<m<<a[i].m<<endl;
            //cout<<"bbbb";
            a[a[i].pos].flag=(float)m/a[i].m;
            //cout<<a[i].flag<<endl;
            break;
        }
    }
    /*for(int i=1;i<=n;i++)
    {
    	//cout<<a[i].pos<<" ";
        res[i]=a[i].flag;
    }*/
    //cout<<endl;
    printf("%g\n", sum);
    for(int i=1;i<=n-1;i++)
    {
        printf("%.2f ", a[i].flag);
    }
    printf("%.2f", a[n].flag);
    return 0;
}
