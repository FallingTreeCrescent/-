#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int n, m, d;
struct dic_Tree
{
    int freq;           //频率
    char name[16];      //单词长度最多15
    dic_Tree *next[16]; //距离最多15
};
dic_Tree *root;
dic_Tree *que[10001], *pos;
int dist[30][30];
int min_Distance(char *a, char *b)
{
    // cout<<"gdsjihhs"<<endl;
    int a_Len = strlen(a), b_Len = strlen(b);
    for (int i = 0; i <= a_Len; i++)
        dist[i][0] = i;
    for (int j = 0; j <= b_Len; j++)
        dist[0][j] = j;
    for (int i = 1; i <= a_Len; i++)
        for (int j = 1; j <= b_Len; j++)
            if (a[i - 1] == b[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
            {
                if (dist[i - 1][j - 1] <= dist[i - 1][j] && dist[i - 1][j - 1] <= dist[i][j - 1])
                    dist[i][j] = dist[i - 1][j - 1] + 1;
                else if (dist[i][j - 1] <= dist[i - 1][j] && dist[i][j - 1] <= dist[i - 1][j - 1])
                    dist[i][j] = dist[i][j - 1] + 1;
                else if (dist[i - 1][j] <= dist[i - 1][j - 1] && dist[i - 1][j] <= dist[i][j - 1])
                    dist[i][j] = dist[i - 1][j] + 1;
            }
    return dist[a_Len][b_Len];
}
void find(char *s)
{
    // cout<<"dfdasdf"<<endl;
    int fro = 0, rear = 0;
    que[rear++] = root;
    pos = NULL;
    int flag = 0;
    while (rear > fro)
    {
        dic_Tree *head = que[fro];
        fro++;
        int min_step = min_Distance(s, head->name);
        if (min_step == 0)
        {
            flag = 1;
            break;
        }
        else if (min_step <= d)
        {
            if (pos == NULL || (head->freq > pos->freq && pos != NULL))
                pos = head;
            else if (head->freq == pos->freq && strcmp(head->name, pos->name) < 0)
                pos = head;
        }
        int p = min_step - d >= 1 ? (min_step - d) : 1;
        int q = min_step + d <= 15 ? (min_step + d) : 15;
        while (p <= q)
        {
            if (head->next[p] != NULL)
            {
                que[rear++] = head->next[p];
                // cout<<p<<" ";
            }
            p++;
        }
        // cout<<"dfdasdf"<<endl;
    }
    if (flag == 1)
    {
        printf("%s\n", s);
    }
    else if (NULL == pos)
    {
        printf("No similar word in dictionary\n");
    }
    else
    {
        printf("%s\n", pos->name);
    }
}
void insert(dic_Tree *r, dic_Tree *p)
{
    int len = min_Distance(p->name, r->name);
    // cout<<len<<endl;
    /*if (p->name == root->name)
        return;*/
    if (NULL == r->next[len])
    {
        r->next[len] = p;
        // return;
        // cout<<"dasas"<<endl;
    }
    else
    {
        insert(r->next[len], p);
    }
}
void buildTree()
{
    char s[16];
    int frequence;
    // cin >> frequence >> s;
    scanf("%d%s", &frequence, s);
    root->freq = frequence;
    strcpy(root->name, s);
    n--;
    while (n--)
    {
        // cin >> frequence >> s;
        scanf("%d%s", &frequence, s);
        dic_Tree *x = new dic_Tree;
        memset(x->next, 0, sizeof(x->next));
        x->freq = frequence;
        strcpy(x->name, s);
        insert(root, x);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &d);
    root = new dic_Tree;
    memset(root->next, 0, sizeof(root->next));
    buildTree();
    char ss[16];
    while (m--)
    {
        scanf("%s", ss);
        find(ss);
    }
    return 0;
}
/*9 8 2
327769900 my
322417800 are
302713400 me
283256900 one
282026500 their
280248100 so
264141700 an
263713600 said
250991700 them
me
wne
therr
xxxxx
they
ax
sy
sds*/