#include <bits/stdc++.h>
using namespace std;
struct node
{
	string str;
	int freq;
};
struct dictionary_Tree
{
	char name;				   //字符
	int frequency = 0;		   //频率
	int treeLast = 0;		   // 树中字母是否为最后的节点
	int wordEnd = 0;		   // 一个单词的结束
	int samestr = 0;		   //是否和子串相同
	dictionary_Tree *next[36]; //每个节点后有32个节点
	string sum = "";
};
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
dictionary_Tree root;
node arr[10000];
int expo = 0;
int flag2 = 0;
int flag3 = 0;
string res = "";
void qsort(int l, int r)
{
	node mid = arr[(l + r) / 2];
	int i = l, j = r;
	do
	{
		while ((arr[i].freq - mid.freq) > 0 || ((arr[i].freq == mid.freq) && (arr[i].str < mid.str)))
		{
			i++;
			// cout<<"asfg";
		}
		while ((arr[j].freq - mid.freq) < 0 || ((arr[j].freq == mid.freq) && (arr[j].str > mid.str)))
			j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}
int transform(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= '0' && c <= '9')
		return c - '0' + 26;
}
void createTree(string Str, int fq)
{
	dictionary_Tree *temp = &root;
	int flag = 0;
	for (int i = 0; i < Str.size(); i++)
	{
		int ans = transform(Str[i]);
		if (temp->next[ans] == NULL)
		{
			dictionary_Tree *ptr = new dictionary_Tree();
			ptr->name = Str[i];
			temp->next[ans] = ptr;
			temp->treeLast = 0;
			temp = temp->next[ans];
			flag = 1;
		}
		else
		{
			temp = temp->next[ans];
			flag = 0;
		}
	}
	if (flag == 1)
		temp->treeLast = 1;
	temp->wordEnd = 1;
	if (fq > temp->frequency)
		temp->frequency = fq;
	else
		temp->frequency = temp->frequency;
}
void dfs(dictionary_Tree *tree, string &subString)
{
	if (tree->wordEnd == 1 && tree->samestr == 0)
	{
		arr[expo].str = subString;
		arr[expo++].freq = tree->frequency;
		if (tree->treeLast == 1)
			return;
	}
	if (tree->treeLast == 1 && tree->samestr)
	{
		printf("no suggestion\n");
		flag2 = 1;
		tree->samestr = 0;
	}
	else
		tree->samestr = 0;
	for (int i = 0; i < 36; i++)
	{
		if (!tree->next[i])
			continue;
		subString += tree->next[i]->name;
		dfs(tree->next[i], subString);
		subString = string(subString.begin(), subString.end() - 1);
	}
}
dictionary_Tree *findSubstring(string str)
{
	dictionary_Tree *t = &root;
	for (int i = 0; i < str.size(); i++)
	{
		int ans = transform(str[i]);
		t = t->next[ans];
		res += str[i];
		if (t == NULL)
		{
			flag2 = 1;
			flag3 = 1;
			return t;
		}
	}
	if (t != NULL)
		t->samestr = 1;
	return t;
}
int main()
{
	int n, m, k;
	n = read();
	m = read();
	k = read();
	int frequency;
	string s;
	char temp[21];
	for (int j = 0; j < n; j++)
	{
		frequency = read();
		scanf("%s", temp);
		s = temp;
		createTree(s, frequency);
	}
	dictionary_Tree *t;
	string s1;
	for (int i = 0; i < m; i++)
	{
		scanf("%s", temp);
		s1 = temp;
		t = findSubstring(s1);
		if (t == NULL)
		{
			flag3 = 0;
			res = "";
			printf("no suggestion\n");
		}
		else
		{
			if (t->sum == "")
			{
				if (!flag3)
					dfs(t, res);
				qsort(0, expo - 1);
				expo = k > expo ? expo : k;
				for (int j = 0; j < expo; j++)
				{
					printf("%s\n", arr[j].str.c_str());
					t->sum += (arr[j].str + "\n");
				}
			}
			else
			{
				printf("%s", t->sum.c_str());
				t->samestr = 0;
			}
		}
		expo = 0;
		if (i < m - 1)
			printf("\n");
		res = "";
		flag2 = 0;
	}
	return 0;
}
