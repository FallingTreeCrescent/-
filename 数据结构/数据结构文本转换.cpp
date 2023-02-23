/*艾迪正在打一篇稿子，稿子只包含空格和26个小写字母。但他的键盘中有6个按键出现了故障，当按下k键时会使当前输入光标左移一个字符位置（如果光标在文档头则不左移），当按下z键时会使当前输入光标右移一个字符位置（如果光标在文档尾则不右移），当按下w键时会使当前输入光标移至文档开始位置，当按下s键时会使当前输入光标移至文档尾，当按下q键时会删除当前输入光标前的一个字符，当按下m键时会使输入光标在插入和改写（覆盖）状态切换（初始是插入状态）。现给定艾迪的原始稿子，请编写程序输出使用故障键盘打出的稿件，即屏幕最终显示的文本。

关于m键的解释：若当前输入状态是ab|cd（|表示光标）：（1）若处在插入状态，则输入字符插入到光标后面，如输入x，则变为abx|cd；（2）若处在改写（覆盖）状态，则输入字符覆盖光标后面的字符，如输入x，则变为abx|d。（3）初始时为插入状态，按一下m键切换到改写状态，再按一下m键切换回插入状态，再按一下m键，切换到改写状态......以此类推。*/
#include <cstdio>
#include <iostream>
typedef struct cell 
{
    char data;
    struct cell *last;
    struct cell *next;
} Doublelist, *ptr;
Doublelist *head, *rear;
Doublelist *build(void)
{
    head = new Doublelist();
    head->next = NULL;
    head->last = NULL;
    rear = head;
    return head;
}
void print(Doublelist *head)
{
    Doublelist *p = head;
    while (p->next != NULL)
    {
        printf("%c", p->next->data);
        p = p->next;
    }
}
int main()
{
    int flag = 1; //实现m的转换
    head = build();
    Doublelist *p, *q, *r; //用p来标记光标
    p = head;
    char ch;
    ch = getchar();
    while ((ch >= 'a' && ch <= 'z') || ch == ' ')
    {
        //左移
        if (ch == 'k')
        {
            if (p != head)
                p = p->last;
        }
        //右移
        else if (ch == 'z')
        {
            if (p != rear)
                p = p->next;
        }
        //移位头
        else if (ch == 'w')
        {
            p = head;
        }
        //移位尾
        else if (ch == 's')
        {
            p = rear;
        }
        //删除前一节点
        else if (ch == 'q')
        {
            if (p->next == NULL)
            {
                if (p != head)
                {
                    p->last->next = NULL;
                    rear = p->last;
                    delete (p);
                    p = rear;
                }
            }
            else
            {
                p->next->last = p->last;
                p->last->next = p->next;
                delete (p);
            }
        }
        //切换状态
        else if (ch == 'm')
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }
        //输入其他字符实现插入或覆盖
        else
        {
            if (flag == 1)
            {
                q = new Doublelist();
                q->data = ch;
                q->next = p->next;
                if (p->next == NULL)
                {
                    rear = q;
                    p->next = q;
                    q->last = p;
                    p = p->next;
                }
                else
                {
                    p->next->last = q;
                    p->next = q;
                    q->last = p;
                    p = p->next;
                }
            }
            else
            {
                if (p->next != NULL)
                {
                    p->next->data = ch;
                    p = p->next;
                }
            }
        }
        ch = getchar();
    }
    print(head);
    return 0;
}
