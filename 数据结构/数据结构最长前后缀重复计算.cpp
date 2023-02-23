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
  for(int i=0;i<n;i++){
  	tmp[i]=f[i];
  }
  /*for(int i=0;i<n;i++){
  	printf("%d ",tmp[i]);
  }*/
   for(int i=1;i<n;i++)//从第二位开始 
   {
   	int b=-1; 
   	while(tmp[i]!=-1)
   	{
   		b=tmp[i];//记录最后大于-1的f[i] 
   		tmp[i]=f[b];//逐步找最小的前后缀,注意不能修改f[i] 
	}
	if(b==-1)sum+=0;
	else sum+=(i-b);//总长i+1位，前后缀长b+1 
   }
   printf("%d",sum);
  return 0;
}
/*6
ababab
10
bbcabbabbc */
