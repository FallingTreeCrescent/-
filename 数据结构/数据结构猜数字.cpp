#include <bits/stdc++.h>
using namespace std;
int f1[100005];
int f2[100005];
char str1[100005];
char str2[100005];
char b[100005];
void fail2(char *p)
{
  int lengthP = strlen(p);
  f2[0] = -1;
  for (int j = 1; j < lengthP; j++)
  {
    int i = f2[j - 1];
    while (p[j] != p[i + 1] && i >= 0)
      i = f2[i];
    if (p[j] == p[i + 1])
      f2[j] = i + 1;
    else
      f2[j] = -1;
  }
}
int main(void)
{
  int pos, lenP, lenQ, lenS;
  while (cin >> str1)
  {
    int j = 0;
    for (int i = strlen(str1) - 1; i >= 0; i--, j++)
    {
      str2[j] = str1[i];
    }
    str2[j] = 0;
    /*fail2(str1);
    if (f2[strlen(str1) - 1] != -1)
      lenS = f2[f2[strlen(str1) - 1]] + 1;
    else
      lenS = 0;
    lenQ = strlen(str1) - 2 * lenS;*/
    fail2(str2);
    int m = -1;
    for (int i = 0; i < strlen(str1); i++)
    {
      m = max(f2[i], m);
    }
    lenP = m + 1;
    if (f2[strlen(str2) - 1] != -1)
      lenS = f2[f2[strlen(str2) - 1]] + 1;
    else
      lenS = 0;
    lenQ = strlen(str2) - 2 * lenS;
    if (lenQ < 0)
      lenQ = 0;
    // cout << lenP+lenQ << endl;
    cout << lenP + lenQ << endl;
  }
  return 0;
}
