#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
char a[200005];
char b[200005];//存顺序括号 
char c[200005];//存左括号 
int main()
{
  while (cin >> a)
  {
    int left = 0, right = 0, out = 0, j = 0, pos = 0,x=0; 
    for (int i = 0; i < strlen(a);)
    {
      if (a[i] == '(')//遇到左括号直接存
      {
        left++;
        b[j++] = '(';
        i++;
      }
      else if (a[i] == ')')//遇到右括号分情况
      {
      	right++;
        if(right>=left)//右大于左
        {
          while(a[i]==')')//连续找右括号
          {
            i++;
            pos++;//定位右括号个数
          }
          while(pos+right-1>left)//加左括号在c数组里 
          {
            c[x++] = '(';
            left++;
            out++;
          }
          while(pos>0)//加右括号
          {
            b[j++] = ')';
            right++;
            pos--;
          }
          right--;
        }
        else if(right<left)//右小于左直接存 
        {
          b[j++] = ')';
          i++;
        }
      }
    }
    while(left>right)//最后左多于右加右 
    {
    	b[j++]=')';
    	right++;
    	out++;
	}
    if(out==0)
      printf("Match\n");
    else
    {
      printf("%d\n", out);
      for (int i = 0; i < x;i++)
	  {
        printf("%c", c[i]);
      }
      for (int i = 0; i < j;i++)
	  {
        printf("%c", b[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
/*(())()
)(
()))((
()(()()
()()))()*/
