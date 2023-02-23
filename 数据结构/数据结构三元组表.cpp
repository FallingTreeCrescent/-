//两个同阶稀疏矩阵A和B分别都采用三元组表示，编写程序求C=A+B，要求C也采用三元组表示
#include <bits/stdc++.h>
int m,n;
inline int read() {	//快读 
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch>'9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
struct triple{
	int col,row,data;
}a[1010],b[1010],c[1010];
int main(){
	m=read();
	n=read();
	for(int i=0;i<m;i++)
	{
		a[i].row=read();
		a[i].col=read();
		a[i].data=read();
	}
	for(int i=0;i<n;i++)
	{
		b[i].row=read();
		b[i].col=read();
		b[i].data=read();
	}
	int i=0,j=0,s=0;
	while(i<m&&j<n)
	{
		if(a[i].row<b[j].row)
		{
			c[s].row=a[i].row;
			c[s].col=a[i].col;
			c[s].data=a[i].data;
			i++,s++;
		}
		else if(a[i].row>b[j].row)
		{
			c[s].row=b[i].row;
			c[s].col=b[i].col;
			c[s].data=b[i].data;
			j++,s++;
		}
		else
		{
			if(a[i].col==b[j].col)
			{
				if(a[i].data+b[j].data==0)
				{
					i++;j++;
				}
				else
				{
					c[s].row=a[i].row;
					c[s].col=a[i].col;
					c[s].data=b[j].data+a[i].data;
					i++;j++;s++;
				}
			}
			else if(a[i].col>b[j].col)
			{
				c[s].row=b[j].row;
			    c[s].col=b[j].col;
			    c[s].data=b[j].data;
			    j++,s++;
			}
			else
			{
				c[s].row=a[i].row;
			    c[s].col=a[i].col;
			    c[s].data=a[i].data;
			    i++,s++;
			}
		}
	}
	while(i<m)c[s++]=a[i++];
	while(j<n)c[s++]=b[j++];
	for(int i=0;i<s;i++){
		printf("%d %d %d\n",c[i].row,c[i].col,c[i].data);
	}
	return 0;
}
