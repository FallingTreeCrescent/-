//���������� 
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,j=2;//j����¼�� 
	//int a[32769][16];
	int a[20000][16],b[100000];//a�������� b��ÿ�еĳ��� 
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	int o,x,m,w,t;//o����¼֮ǰj��λ�� x����¼�� w����¼���һλҪ�ӵ��� 
	x=1;w=1;
	a[1][1]=n;
	b[1]=1;
	for(int i=1;i<n;i++)
	{
		o = 1;t=0;
		for(int p=1;p<=pow(2,x)-1;p++)//���Ʋ�����ĸ���� 
		{
			m=1;//m��λ���Ƶ����Ƿ�Ϊ�� 
			while(a[o][m]!=0)//���� 
			{
				a[j][m]= a[o][m];
				m++;
			}
			if(a[j][m-1]>1)//�������� 
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
	//����������У����������������
	printf("{}\n");
	o = pow(2,n)-1;
	while(o>=1)//��2��n�η�-1��
	{
		//m = a[o].length();//��¼ÿһ�г��� 
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
//a��97

