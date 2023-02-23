#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
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
struct Word
{
	char name[100];
	int freq;
	int v=1;
};
struct Word word[10001];
char pos[21];
void qsort(int l, int r)
{
	Word mid = word[(l + r) / 2];
	// cout<<mid.freq<<" "<<mid.name<<endl;
	int i = l, j = r;
	do
	{
		//while (strcmp(word[i].name, mid.name) < 0||(strcmp(word[i].name, mid.name) == 0)&&(word[i].freq-mid.freq)<0)
		while ((word[i].freq-mid.freq)>0)
		{
			i++;
			// cout<<"asfg";
		}
		while ((word[j].freq-mid.freq)<0)
			j--;
		if (i <= j)
		{
			swap(word[i], word[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (l < j)
		qsort(l, j);
	if (i < r)
		qsort(i, r);
}
void bubbledet(int l, int r)
{
	for (int i = l; i < r; i++)
	{
		int j=i+1;
		while(j<=r)
		{
			if(strcmp(word[i].name,word[j].name)==0)
		    {
			   word[j].v=0;
		    }
		    j++;
		}
	}
}
int main()
{
	int n, m, k;
	n=read();
	m=read();
	k=read();
	for (int i = 0; i < n; i++)
	{
		word[i].freq=read();
		scanf("%s",&word[i].name);
		// cout<<word[i].name<<" ";
	}
	qsort(0, n - 1);
	bubbledet(0,n-1);
	// cout<<"hdfdf";
	// cout<<"ÅÅÐòºó"<<endl;
	/*for(int i=0;i<n;i++)
	{
		cout<<word[i].freq<<" "<<word[i].name<<endl;
	}*/
	for (int i = 0; i < m; i++)
	{
		int kk = k;
		//cin >> pos;
		scanf("%s",&pos);
		// cout<<" asdaa";
		for (int j = 0; j < n; j++)
		{
			int o = 0, flag = 0;
			while (pos[o] == word[j].name[o]&&word[j].v==1)
			{
				o++;
				if (pos[o] == '\0' && strcmp(pos, word[j].name) != 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				//cout << word[j].name << endl;
				printf("%s\n",word[j].name);
				kk--;
			}
			if (kk == 0)
				break;
		}
		if (kk == k)
			//cout << "no suggestion"<<endl;
			printf("no suggestion\n");
		if(i!=m-1)cout << endl;
	}
	return 0;
}
/*20 3 4
1827187200 the
1595609600 to
1107331800 that
401542500 this
334039800 they
282026500 their
250991700 them
196118888 these
150877900 than
144968100 time
125563600 then
109336600 two
196120000 there
87862100 those
79292500 through
75885600 the
71578000 think
67462300 2
65648600 tx356
57087700 though
th
xxx
the*/
