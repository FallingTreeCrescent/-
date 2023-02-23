#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
typedef struct
{
    char letter;
    char *code;
    int weight;
    int parent, left, right;
} HTNode, *HFTree; //哈夫曼树结构体
char code1[10000]; //编码1
char code2[10000]; //编码2
int n;             //传入数组长度
int num = 0;       //压缩后字节长度
int Selectmin(HFTree &HT, int len)
{ //选择权最小的值
    int j;
    int minweight = 9999;
    int minIndex = 9999;
    for (j = 0; j <= len; j++)
    {
        if (HT[j].parent == 0)
        {
            if (HT[j].weight < minweight)
            {
                minweight = HT[j].weight;
                minIndex = j;
            }
        }
    }
    HT[minIndex].parent = 1; // flag判断是否已经作为根
    return minIndex;
}
void Select(HFTree &Tree, int i, int &min1, int &min2) // Select选两个当前权最小值
{
    min1 = Selectmin(Tree, i);
    min2 = Selectmin(Tree, i);
}
void initial(HFTree &Tree, char a[], int b[]) //初始化
{
    int m = 2 * n - 1; //一共需要2n－1个节点
    Tree = new HTNode[m + 1];
    for (int i = 0; i < n; i++)
    {
        Tree[i].parent = 0;
        Tree[i].left = 0;
        Tree[i].right = 0;
        Tree[i].letter = a[i];
        Tree[i].weight = b[i];
    }
    for (int i = n; i <= m; i++)
    {
        Tree[i].parent = 0;
        Tree[i].left = 0;
        Tree[i].right = 0;
        Tree[i].letter = ' ';
        Tree[i].weight = 0;
    }
}
void CreateHFTree(HFTree &Tree) //建哈夫曼树
{
    int m = 2 * n - 1;
    int s1, s2;
    for (int i = n; i < m; i++)
    {
        Select(Tree, i - 1, s1, s2); //找两个最小权值数
        Tree[i].left = s1;
        Tree[i].right = s2;
        Tree[s1].parent = i;
        Tree[s2].parent = i;
        Tree[i].weight = Tree[s1].weight + Tree[s2].weight;
    }
}
void CreatHFCode(HFTree Tree) //建立哈夫曼编码
{
    int tc, ans;
    int i = 0;
    char *cod = new char[n];
    cod[n - 1] = 0;
    while (i < n)
    {
        int len = 0;
        int start = n - 1;
        tc = i;
        ans = Tree[i].parent;
        while (ans != 0)
        {
            start--;
            if (Tree[ans].left == tc)
            {
                cod[start] = '0';
                len++;
            }
            else
            {
                cod[start] = '1';
                len++;
            }
            tc = ans;
            ans = Tree[ans].parent;
        }
        Tree[i].code = new char[n - start];
        strcpy(Tree[i].code, &cod[start]);
        num = num + len * (Tree[i].weight);
        i++;
    }
    delete cod;
}
void Print(HFTree HT)
{
    for (int i = 0; i < n; i++)
        HT[i].parent = 0;
    for (int i = 0; i < n; i++)
    {
        int node = Selectmin(HT, n);
        printf("%c:%s\n", HT[node].letter, HT[node].code);
    }
}
void HFDecoding(HFTree Tree, char *cod, int nx)
{
    char pos[5000], tmp[5000]; //存要输出的字符串和存临时变量
    int flag = 0;
    int s = 0;
    for (int i = 0; i < nx; i++)
    {
        tmp[flag++] = cod[i];       //存字符
        tmp[flag] = 0;              //最后位置/0
        for (int j = 0; j < n; j++) //每一位都匹配
        {
            if (strcmp(Tree[j].code, tmp) == 0)
            {
                pos[s] = Tree[j].letter; //将字符保存到pos中
                s++;
                memset(tmp, ' ', sizeof(tmp));
                flag = 0; //拿来判断最后是否相等
                break;
            }
        }
    }
    if (flag != 0)
        cout << "INVALID" << endl;
    else
    {
        pos[s] = 0;
        cout << pos << endl; //相等输出对应字符
    }
}
int main()
{
    HFTree HT;
    char a[5000], s[5000]; // a存字符 s为输入字符串
    int b[5000];           //存权值
    cin >> s;
    cin >> code1;
    cin >> code2;
    int len = strlen(s);
    for (int i = 0; i < len; i++) //进行赋权值操作
    {
        int j = 0;
        while (j < n) // n代表a数组之前的长度
        {
            if (a[j] == s[i])
            {
                b[j]++;
                break;
            }
            j++;
        }
        if (j >= n)
        {
            a[n] = s[i]; //存字符
            b[n] = 1;    //赋值初始权值
            n++;
        }
    }
    initial(HT, a, b);
    CreateHFTree(HT);
    CreatHFCode(HT);
    if (num % 8 != 0)
        num = num / 8 + 1;
    else
        num = num / 8;
    printf("%d %d\n", len, num); //输出压缩前后长度
    Print(HT);
    int len1, len2; //译码的长度
    len1 = strlen(code1);
    HFDecoding(HT, code1, len1);
    len2 = strlen(code2);
    HFDecoding(HT, code2, len2);
    return 0;
}

