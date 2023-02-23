#include <iostream>
using namespace std;

int n;
//搜索到根节点和虚拟键的概率
int p[5001];
int q[5001];

int root[5001][5001]; //记录根节点
int w[5010][5010];    //子树概率总和
int e[5010][5010];    //子树期望代价

void optimalBST(int *p, int *q, int n)
{
    //初始化只包括虚拟键的子树
    for (int i = 1; i <= n + 1; ++i)
    {
        w[i][i - 1] = q[i - 1];
        e[i][i - 1] = q[i - 1];
    }

    //由下到上，由左到右逐步计算
    for (int len = 1; len <= n; ++len)
    {
        for (int i = 1; i <= n - len + 1; ++i)
        {
            int j = i + len - 1;
            e[i][j] = 1000005;
            w[i][j] = w[i][j - 1] + p[j] + q[j];
            //求取最小代价的子树的根
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

//打印最优二叉查找树的结构
//打印出[i,j]子树，它是根r的左子树和右子树
void printOBST(int i, int j, int r) // r传入后当做此棵子树的父节点
{
    int rootChild = root[i][j]; //子树根节点
    if (rootChild == root[1][n])
    {
        printf("%d\n",rootChild);
        printOBST(i, rootChild - 1, rootChild);
        printOBST(rootChild + 1, j, rootChild);
        return;
    }
    if (j <= i - 1) // i-1也就是子树的根节点，j==i-1是子树为空的情况
    {
        return;
    }
    else //遇到内部结点 ，也就是实际数值
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
