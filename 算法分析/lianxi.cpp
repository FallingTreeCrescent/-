#include <iostream>
using namespace std;

int n;
//���������ڵ��������ĸ���
int p[5001];
int q[5001];

int root[5001][5001]; //��¼���ڵ�
int w[5010][5010];    //���������ܺ�
int e[5010][5010];    //������������

void optimalBST(int *p, int *q, int n)
{
    //��ʼ��ֻ���������������
    for (int i = 1; i <= n + 1; ++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //���µ��ϣ��������𲽼���
    for (int len = 1; len <= n; ++len)
    {
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len - 1;
            e[i][j] = 1000005;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //��ȡ��С���۵������ĸ�
            for (int k = i; k <= j; ++k)
            {
                int temp = e[i][k - 1] + e[k + 1][j] + w[i][j];
                if (temp < e[i][j])
                {
                    e[i][j] = temp;
                    root[i][j] = k;
                }
            }
        }
    }
}

//��ӡ���Ŷ���������Ľṹ
//��ӡ��[i,j]���������Ǹ�r����������������
void printOBST(int i, int j, int r) // r��������˿������ĸ��ڵ�
{
    int rootChild = root[i][j]; //�������ڵ�
    if (rootChild == root[1][n])
    {
        printf("%d\n",rootChild);
        printOBST(i, rootChild - 1, rootChild);
        printOBST(rootChild + 1, j, rootChild);
        return;
    }
    if (j <= i - 1) // i-1Ҳ���������ĸ��ڵ㣬j==i-1������Ϊ�յ����
    {
        return;
    }
    else //�����ڲ���� ��Ҳ����ʵ����ֵ
    {
        printf("%d\n",rootChild);
    }
    printOBST(i, rootChild - 1, rootChild);
    printOBST(rootChild + 1, j, rootChild);
}
int main()
{
    scanf("%d", &n);
    p[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &q[i]);
    }
    optimalBST(p, q, n);
    printOBST(1, n, -1);
}
