#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
char a[200005];
char b[200005];//��˳������ 
char c[200005];//�������� 
int main()
{
  while (cin >> a)
  {
    int left = 0, right = 0, out = 0, j = 0, pos = 0,x=0; 
    for (int i = 0; i < strlen(a);)
    {
      if (a[i] == '(')//����������ֱ�Ӵ�
      {
        left++;
        b[j++] = '(';
        i++;
      }
      else if (a[i] == ')')//���������ŷ����
      {
      	right++;
        if(right>=left)//�Ҵ�����
        {
          while(a[i]==')')//������������
          {
            i++;
            pos++;//��λ�����Ÿ���
          }
          while(pos+right-1>left)//����������c������ 
          {
            c[x++] = '(';
            left++;
            out++;
          }
          while(pos>0)//��������
          {
            b[j++] = ')';
            right++;
            pos--;
          }
          right--;
        }
        else if(right<left)//��С����ֱ�Ӵ� 
        {
          b[j++] = ')';
          i++;
        }
      }
    }
    while(left>right)//���������Ҽ��� 
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
