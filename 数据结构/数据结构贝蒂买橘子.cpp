//贝蒂买橘子 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,j=2;//j来记录行 
	//int a[32769][16];
	int a[20000][16],b[100000];//a数组存输出 b存每行的长度 
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	int o,x,m,w,t;//o来记录之前j的位置 x来记录列 w来记录最后一位要加的数 
	x=1;w=1;
	a[1][1]=n;
	b[1]=1;
	for(int i=1;i<n;i++)
	{
		o = 1;t=0;
		for(int p=1;p<=pow(2,x)-1;p++)//复制并加字母操作 
		{
			m=1;//m定位复制的列是否为空 
			while(a[o][m]!=0)//复制 
			{
				a[j][m]= a[o][m];
				m++;
			}
			if(a[j][m-1]>1)//往后添数 
			{
				if(t==0)
				{
				a[j][m]=a[j][m-1]-w;
				t=a[j][m];	
				}
				else
				{
					a[j][m]=t;
				}
			}
			b[j]=m;
			j++;o++;
		}
		b[j]=1;
		if(a[j-1][m]>=1)
		{
			a[j][1]=a[j-1][m];
			j++;
		}
		x++;w++;
	}
	//输出所求序列，从右往左从下往上
	printf("{}\n");
	o = pow(2,n)-1;
	while(o>=1)//有2的n次方-1行
	{
		//m = a[o].length();//记录每一行长度 
		//m=a[0].length();
		//m=sizeof(a[o])/sizeof(int);  16
		//cout<<m<<" ";
		m=b[o];
		printf("{");
		if(a[o][m]!=0)
		printf("%c", (char)(a[o][m]+96));
		m--;
		while(a[o][m]!=0)
		{
			printf(",%c", (char)(a[o][m]+96));
			m--;
		}
		printf("}\n");
		o--;
	}
	return 0;
}
//a是97

