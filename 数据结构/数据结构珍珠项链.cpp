#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
struct cell
{
	int num;
	int head;
}a[100001];
int j=0;
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			a[i].num=i;
			a[i].head=i;
		}

		while(m--)
		{
			int p,q;
			scanf("%d%d",&p,&q);
			while(a[q].head!=a[a[q].head].head)
				a[q].head=a[a[q].head].head;//����������ͷ��� 
			while(a[p].head!=a[a[p].head].head)
				a[p].head=a[a[p].head].head;//����������ͷ���
			a[a[p].head].head=a[q].head;//��ֵͷ��ͷ����ʱΪ���� 
		}

		for(int i=1;i<=n;i++)
		{
			while(a[i].head!=a[a[i].head].head)
				a[i].head=a[a[i].head].head;//��Ϊ��������ʵ����if 
			printf("%d ",a[i].head);
		}
		printf("\n");
	}
	return 0;
}
