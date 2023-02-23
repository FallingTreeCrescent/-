#include <bits/stdc++.h>
using namespace std;
int f[1000005];//失败函数 
int tmp[1000005];//存失败函数 
char str[1000005];
long long sum=0;
void fail(char *p)
{
  int lengthP = strlen(p);
  f[0] = -1;
  for (int j = 1; j < lengthP; j++)
  {
    int i = f[j - 1];
    while (p[j] != p[i + 1] && i >= 0)
      i = f[i];
    if (p[j] == p[i + 1])
      f[j] = i + 1;
    else
      f[j] = -1;
  }
}
int main(void)
{
  int n;
  scanf("%d",&n);
  getchar();
  for(int i=0;i<n;i++){
  	scanf("%c",&str[i]);
  }
  /*for(int i=0;i<n;i++){
  	printf("%c",str[i]);
  }*/
  fail(str);
   for(int i=1;i<n;i++)//从第二位开始 
   {
   	int b=f[i]; 
   	if(f[b]!=-1&&b>-1)
   	{
   		b=f[b];
	}
	f[i]=b;//每次保留最短前后缀 
   }
   for(int i=0;i<n;i++){
  	printf("%d ",f[i]);
  }
   for(int i=1;i<n;i++){
   	if(f[i]==-1);
   	else
   	sum=sum+i-f[i];//总长i+1位，前后缀长b+1
   }
   printf("\n%lld",sum);//过大开lld 
  return 0;
}
/*6
ababab
10
bbcabbabbc
12
aaaaaaaaaaaa */












