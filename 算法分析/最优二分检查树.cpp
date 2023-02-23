#include <iostream>
using namespace std;
int n;
int p[5005],q[5005];//查找第i个标识符的次数、未找到的第i种情形的次数
int r[5005][5005]; //记录根节点
int w[5005][5005];//子树概率总和
int c[5005][5005];//最优二分检索树的成本。
void print(int i, int j, int ans)//ans传入为当前子树的父节点 
{
  int root = r[i - 1][j];
  if (root == r[0][n])
  {
    cout << root << endl;
    print(i, root - 1, root);
    print(root + 1, j, root);
    return;
  }
  if (j <= i - 1)//子树为空(<是空，=是虚拟键)
    return;
  else//遇到内部节点 
  {
    if (root < ans)//左孩子 
      cout << root << endl;
    else//右孩子 
      cout << root << endl;
  }
  print(i, root - 1, root);
  print(root + 1, j, root);
}
int main()
{
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d", &p[i]);
  for (int i = 0; i <= n; i++)
    scanf("%d", &q[i]);
  for (int i = 0; i < n; i++)//PPT代码
  {
    w[i][i] = q[i];
    r[i][i] = c[i][i] = 0;
    w[i][i + 1] = c[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
    r[i][i + 1] = i + 1;
  }
  w[n][n] = q[n];
  r[n][n] = c[n][n] = 0;
  for (int m = 2; m <= n; m++)
  {
    for (int i = 0; i <= n - m; i++)
    {
      int j = i + m;
      w[i][j] = w[i][j - 1] + p[j] + q[j];
      int k;
      int min = 999999;
      for (int l = r[i][j - 1]; l <= r[i + 1][j]; l++)
      {
        if ((c[i][l - 1] + c[l][j]) < min)
          min = c[i][l - 1] + c[l][j], k = l;
      }
      c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
      r[i][j] = k;
    }
  }
  print(1, n, -1);
  return 0;
}
