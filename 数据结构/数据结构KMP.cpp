// KMP
#include <cstdio>
#include <iostream>
using namespace std;
string s, p; //查询串（主串）s和子串（模式串）p
int f[100005];
//长度为前4个字符的子串aaba，最长相同前后缀的长度为1。
//长度为前5个字符的子串aabaa，最长相同前后缀的长度为2。
//长度为前7个字符的子串aaab|aaa，最长相同前后缀的长度为3。@ j=3,i=1,i=0,i=-1
//长度为前6个字符的子串aabaaf，最长相同前后缀的长度为0。
//可以看出模式串s与前缀表f对应位置的数字表示的就是：下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
void fail()
{
    int lengthP = p.length();
    f[0] = -1; //第一个数初始值设为-1
    for (int j = 1; j < lengthP; j++)
    {
        int i = f[j - 1];                  //每一次i等于当前j的前一个数j-1的失败函数值
        while (p[j] != p[i + 1] && i >= 0) //前后缀末尾不相同了就要向前回溯，p[j]表示后缀末尾，p[i+1]表示前缀末尾如@第9列
            i = f[i];                      //向前回溯
        if (p[j] == p[i + 1])              //匹配成功
            f[j] = i + 1;
        else //匹配失败
            f[j] = -1;
    }
}
int kmp() //返回模式串p第一次出现在主串s中的位置
{
    int i = 0, j = 0;
    int m = p.length();
    int n = s.length();
    while (i < m && j < n)
    {
        if (p[i] == s[j]) //字符比对成功都++
        {
            i++;
            j++;
        }
        else //字符比对失败
        {
            if (i == 0) //第一次i=0只能s主串j++,p模式串不动
                j++;
            else //比对时模式串p返回到上一字符失败函数值+1处,主串s的位置只能始终往前走而在此处匹配失败故j不动
                i = f[i - 1] + 1;
        }
    }
    if (i < m) //未找到，不相匹配返回-1
        return -1;
    else //找到由于j是匹配末端+1，故返回首字母出现位置为j-m
        return j - m;
}
int main()
{
    cin >> s >> p;
    fail();
    cout << kmp() << endl;
    cout << p.length() / 2 << endl;
    for (int i = 0; i < p.length(); i++)
        cout << f[i] << " ";
    return 0;
}
