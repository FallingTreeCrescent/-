#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
int threshold;
int flag = 1;
int depth;
int o=0;
int b[100001];
void insertsort(int *a, int length) //����
{
    for (int i = 2; i <= length; i++)
    {
        a[0] = a[i]; //�ڱ���ʱ���Ҫ���������
        int j;
        for (j = i - 1; a[0] < a[j]; j--)
        {
            a[j + 1] = a[j]; //�ҵ�Ҫ�����λ��
        }
        a[j + 1] = a[0]; //����
    }
} //ʱ�临�Ӷ�������ƽ��n,n2,n2���ȶ����ռ临�Ӷ�1
void Adjust(int *a, int k, int m)
{
    int i = k;
    int j = 2 * i;
    while (j <= m)
    {
        if (j < m && a[j + 1] > a[j]) // jָ��i���ҽڵ�Ľϴ���
        {
            j++;
        }
        if (a[i] >= a[j]) //���ϴ����Ҫ����˳�ѭ��
        {
            break;
        }
        else
        {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i = j; //����һ���ж�ֱ��Ҷ�ڵ����
            j = 2 * i;
        }
    }
}
void heapsort(int *a,int n) //������
{
    /*for (int i = m; i <= (m + n) / 2; i++)
    {
        printf("%d ", a[i]);
    }*/
    for (int i = 1; i < n; i++)
    {
        int tmp = a[1];
        a[1] = a[n - i + 1];
        a[n - i + 1] = tmp;
        Adjust(a, 1, n - i); //ɸѡ���ڵ��������ɴ����
    }
}
int position(int *a, int m, int n)
{
    int i, j, k;
    i = m, j = n + 1, k = a[m];
    while (i < j)
    {
        i += 1;
        while (a[i] <= k&&i<n)
            i += 1;
        j -= 1;
        while (a[j] > k)
            j -= 1;
        if (i < j)
        {
            int tmp;
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int t;
    t = a[m];
    a[m] = a[j];
    a[j] = t;
    return j;
}
void qsort(int *a, int x, int y, int dep, int depth)
{
    if (y - x + 1 > threshold)
    {
        if (dep < depth)
        {
            int j = position(a, x, y);
            qsort(a, x, j - 1, dep + 1, depth);
            qsort(a, j + 1, y, dep + 1, depth);
        }
        // printf("%d\n",depth);
        else
        {
        	int ans=0,loc=0;
        	for(int i=x;i<=y;i++)
        	{
        		b[++ans]=a[i];
			}
            for (int i = ans / 2; i >= 1; i--) //��ʼ�������
            {
                Adjust(b, i, ans);
            }
            for(int i=x;i<=y;i++)
        	{
        		a[i]=b[++loc];
			}
            printf("Heap:");
            for (int i = x; i <= y; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            heapsort(b, ans);
            loc=0;
            for(int i=x;i<=y;i++)
        	{
        		a[i]=b[++loc];
			}
        }
    }
}
void sort(int *R, int n)
{
    int d = (2 * log(n) / log(2));
    printf("depth_limit:%d\n", d);
    qsort(R, 1, n, 0, d);
    printf("Intermediate:");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", R[i]);
    }
    insertsort(R, n);
    printf("\n");
}

int main()
{
    int n, i;
    int a[50010];
    scanf("%d %d", &n, &threshold);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    sort(a, n);

    printf("Final:");
    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
