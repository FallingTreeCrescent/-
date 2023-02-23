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
} HTNode, *HFTree; //���������ṹ��
char code1[10000]; //����1
char code2[10000]; //����2
int n;             //�������鳤��
int num = 0;       //ѹ�����ֽڳ���
int Selectmin(HFTree &HT, int len)
{ //ѡ��Ȩ��С��ֵ
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
    HT[minIndex].parent = 1; // flag�ж��Ƿ��Ѿ���Ϊ��
    return minIndex;
}
void Select(HFTree &Tree, int i, int &min1, int &min2) // Selectѡ������ǰȨ��Сֵ
{
    min1 = Selectmin(Tree, i);
    min2 = Selectmin(Tree, i);
}
void initial(HFTree &Tree, char a[], int b[]) //��ʼ��
{
    int m = 2 * n - 1; //һ����Ҫ2n��1���ڵ�
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
void CreateHFTree(HFTree &Tree) //����������
{
    int m = 2 * n - 1;
    int s1, s2;
    for (int i = n; i < m; i++)
    {
        Select(Tree, i - 1, s1, s2); //��������СȨֵ��
        Tree[i].left = s1;
        Tree[i].right = s2;
        Tree[s1].parent = i;
        Tree[s2].parent = i;
        Tree[i].weight = Tree[s1].weight + Tree[s2].weight;
    }
}
void CreatHFCode(HFTree Tree) //��������������
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
    char pos[5000], tmp[5000]; //��Ҫ������ַ����ʹ���ʱ����
    int flag = 0;
    int s = 0;
    for (int i = 0; i < nx; i++)
    {
        tmp[flag++] = cod[i];       //���ַ�
        tmp[flag] = 0;              //���λ��/0
        for (int j = 0; j < n; j++) //ÿһλ��ƥ��
        {
            if (strcmp(Tree[j].code, tmp) == 0)
            {
                pos[s] = Tree[j].letter; //���ַ����浽pos��
                s++;
                memset(tmp, ' ', sizeof(tmp));
                flag = 0; //�����ж�����Ƿ����
                break;
            }
        }
    }
    if (flag != 0)
        cout << "INVALID" << endl;
    else
    {
        pos[s] = 0;
        cout << pos << endl; //��������Ӧ�ַ�
    }
}
int main()
{
    HFTree HT;
    char a[5000], s[5000]; // a���ַ� sΪ�����ַ���
    int b[5000];           //��Ȩֵ
    cin >> s;
    cin >> code1;
    cin >> code2;
    int len = strlen(s);
    for (int i = 0; i < len; i++) //���и�Ȩֵ����
    {
        int j = 0;
        while (j < n) // n����a����֮ǰ�ĳ���
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
            a[n] = s[i]; //���ַ�
            b[n] = 1;    //��ֵ��ʼȨֵ
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
    printf("%d %d\n", len, num); //���ѹ��ǰ�󳤶�
    Print(HT);
    int len1, len2; //����ĳ���
    len1 = strlen(code1);
    HFDecoding(HT, code1, len1);
    len2 = strlen(code2);
    HFDecoding(HT, code2, len2);
    return 0;
}

