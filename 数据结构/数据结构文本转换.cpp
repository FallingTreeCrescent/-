/*�������ڴ�һƪ���ӣ�����ֻ�����ո��26��Сд��ĸ�������ļ�������6�����������˹��ϣ�������k��ʱ��ʹ��ǰ����������һ���ַ�λ�ã����������ĵ�ͷ�����ƣ���������z��ʱ��ʹ��ǰ����������һ���ַ�λ�ã����������ĵ�β�����ƣ���������w��ʱ��ʹ��ǰ�����������ĵ���ʼλ�ã�������s��ʱ��ʹ��ǰ�����������ĵ�β��������q��ʱ��ɾ����ǰ������ǰ��һ���ַ���������m��ʱ��ʹ�������ڲ���͸�д�����ǣ�״̬�л�����ʼ�ǲ���״̬�����ָ������ϵ�ԭʼ���ӣ����д�������ʹ�ù��ϼ��̴���ĸ��������Ļ������ʾ���ı���

����m���Ľ��ͣ�����ǰ����״̬��ab|cd��|��ʾ��꣩����1�������ڲ���״̬���������ַ����뵽�����棬������x�����Ϊabx|cd����2�������ڸ�д�����ǣ�״̬���������ַ����ǹ�������ַ���������x�����Ϊabx|d����3����ʼʱΪ����״̬����һ��m���л�����д״̬���ٰ�һ��m���л��ز���״̬���ٰ�һ��m�����л�����д״̬......�Դ����ơ�*/
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
    int flag = 1; //ʵ��m��ת��
    head = build();
    Doublelist *p, *q, *r; //��p����ǹ��
    p = head;
    char ch;
    ch = getchar();
    while ((ch >= 'a' && ch <= 'z') || ch == ' ')
    {
        //����
        if (ch == 'k')
        {
            if (p != head)
                p = p->last;
        }
        //����
        else if (ch == 'z')
        {
            if (p != rear)
                p = p->next;
        }
        //��λͷ
        else if (ch == 'w')
        {
            p = head;
        }
        //��λβ
        else if (ch == 's')
        {
            p = rear;
        }
        //ɾ��ǰһ�ڵ�
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
        //�л�״̬
        else if (ch == 'm')
        {
            if (flag == 0)
                flag = 1;
            else
                flag = 0;
        }
        //���������ַ�ʵ�ֲ���򸲸�
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
