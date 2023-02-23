#include <stdio.h>
using namespace std;
struct node
{
    int data;
    node *firstChild;
    node *nextBrother;
};
node *CreateTree()
{
    int k;
    scanf("%d", &k);
    if (k == 0)
        return NULL;
    node *t = new node;
    t->data = k;
    t->firstChild = CreateTree();
    t->nextBrother = CreateTree();
    return t;
}
void Del(node *root)
{
    if (root == NULL)
        return;
    node *p = root->firstChild;
    node *next;
    while (p != NULL)
    {
        next = p->nextBrother;
        Del(p);
        p = next;
    }
    delete root;
}

/* 你的代码将出现在这里 */
//找到a,b所对应的节点
node *find(node *root, int x)
{
    if (root->data == x)
        return root;
    if (root->firstChild != NULL)
        node *left = find(root->firstChild, x);
    if (root->nextBrother != NULL)
        node *right = find(root->nextBrother, x);
    return NULL;
}
int staa[10000], stab[10000], path[10000];
void route(node *root, int a, int b, int level)
{ //存路径
    if (root == NULL)
        return;
    path[level] = root->data;
    if (root->data == a)
    {
        for (int i = 0; i <= level; i++)
        {
            staa[i] = path[i];
        }
    }
    if (root->data == b)
    {
        for (int i = 0; i <= level; i++)
        {
            stab[i] = path[i];
        }
    }
    route(root->firstChild, a, b, level + 1);
    route(root->nextBrother, a, b, level);
}
//找a,b最近公共祖先
int LeastCommonAncestors(node *root, int a, int b)
{
    route(root, a, b, 0);
    int ans = 0;
    for (int i = 0; staa[i] != 0 && stab[i] != 0; i++)
    {
        if (staa[i] == stab[i])
        {
            ans = staa[i];
        }
        else
            return ans;
    }
    return ans;
}
int main()
{
    int a, b, T;
    scanf("%d", &T);
    while (T--)
    {
        node *root = CreateTree();
        scanf("%d %d", &a, &b);
        printf("%d\n", LeastCommonAncestors(root, a, b));
        Del(root);
    }
    return 0;
}
/*4
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
1 2
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
2 4
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
5 2
8 5 1 0 6 0 2 0 0 3 4 0 0 7 0 0 0
3 7*/
// 5 8 2 8
