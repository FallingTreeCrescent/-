#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int a[100001]; //存节点走过的路径
int f[100001]; //存失败函数值
int ans = -1;//维护失败函数最大值 
int top = 0;
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
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *father;//没用到 
} Tree, *ptr;
Tree *buildTree(Tree *root) //建立二叉树
{
    int x;
    x = read();
    if (x == 0)
    {
        root = NULL;
        return root;
    }
    root = (Tree *)malloc(sizeof(Tree));
    root->father = NULL;
    root->data = x;
    root->left = buildTree(root->left);
    if (root->left != NULL)
        root->left->father = root;
    root->right = buildTree(root->right);
    if (root->right != NULL)
        root->right->father = root;
    return root;
}
void dfs(struct node *loc)
{
    if (loc == NULL)
    {
        ans = ans > f[top] ? ans : f[top];
        return;
    }
    a[++top] = loc->data;
    int p = top - 1;
    while (f[p] != -1 && a[f[p] + 1] != loc->data)
        p = f[p];
    if (a[f[p] + 1] == loc->data)
        f[top] = f[p] + 1;
    else
        f[top] = -1;
    dfs(loc->left);
    dfs(loc->right);
    top--;
}
void preorder(Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    int n;
    n = read();
    while (n--)
    {
        Tree *root = NULL;
        root = buildTree(root);
        //    preorder(root);
        //    cout<<endl;
        a[0] = root->data;
        f[0] = -1;
        dfs(root->left);
        dfs(root->right);
        cout << ans<<endl; 
        ans = -1;
    }
    return 0;
}
