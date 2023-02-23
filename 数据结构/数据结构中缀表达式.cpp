//中缀表达式，请编写程序计算该表达式的值
#include <bits/stdc++.h>
using namespace std;
#define max 200005
int flag = 1;
typedef struct node
{
	long long int data[max];
	long long int top;
} Stack1;
typedef struct cell
{
	char data[270000];
	long long int top;
} Stack2;
void push1(Stack1 *p, long long int x)
{
	if (p->top == max)
		;
	// printf("stack1满\n");
	else
	{
		p->data[p->top] = x;
		p->top++;
	}
}
void push2(Stack2 *p, char x)
{
	if (p->top == 270000)
		;
	// printf("stack2满\n");
	else
	{
		p->data[p->top] = x;
		p->top++;
	}
}
void pop1(Stack1 *p, long long int *x)
{
	if (p->top == 0)
		;
	// printf("stack1空\n");
	else
	{
		p->top--;
		*x = p->data[p->top];
	}
}
void pop2(Stack2 *p, char *x)
{
	if (p->top == 0)
		;
	// printf("stack2空\n");
	else
	{
		p->top--;
		*x = p->data[p->top];
	}
}
void initial1(Stack1 *p)
{
	p->top = 0;
}
void initial2(Stack2 *p)
{
	p->top = 0;
}
void calculate(Stack1 *p, char x)
{
	long long int n, m;
	pop1(p, &m);
	pop1(p, &n);
	if (x == '+')
		push1(p, n + m);
	else if (x == '-')
		push1(p, n - m);
	else if (x == '*')
		push1(p, n * m);
	else if (x == '/')
	{
		if (m == 0) //判断是否除数为0
		{
			printf("ILLEGAL");
			flag = 0;
		}
		else
			push1(p, n / m);
	}
}
int main()
{
	char ch, str[max];
	// gets(str);
	Stack1 stack1;
	Stack2 stack2;
	initial1(&stack1);
	initial2(&stack2);
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		//操作数放入stack1注意两位及以上
		if (str[i] >= '0' && str[i] <= '9')
		{
			int tmp = str[i] - '0';
			while (str[i + 1] != '\0')
			{
				if (str[i + 1] >= '0' && str[i + 1] <= '9')
				{
					tmp = tmp * 10 + str[i + 1] - '0';
					i++;
				}
				else
					break;
			}
			push1(&stack1, tmp);
		}
		//运算符放入stack2
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')')
		{
			if (str[i] == '+' || str[i] == '-')
			{
				//注意连续弹栈，当前运算符优先级<=栈顶运算符：弹栈直至当前运算符优先级大于栈顶或栈空或栈顶为左括号，再压栈 
				while ((stack2.data[stack2.top - 1] == '+' || stack2.data[stack2.top - 1] == '-' || stack2.data[stack2.top - 1] == '*' || stack2.data[stack2.top - 1] == '/')&&stack2.data[stack2.top - 1] != '(')                  
				{
						pop2(&stack2, &ch);
						calculate(&stack1, ch);
						if (flag == 0)
							return 0;
				}
					push2(&stack2, str[i]);
			}
			else if (str[i] == '/' || str[i] == '*')
			{
				//注意连续弹栈，当前运算符优先级<=栈顶运算符：弹栈直至当前运算符优先级大于栈顶或栈空或栈顶为左括号，再压栈
				while ((stack2.data[stack2.top - 1] == '*' || stack2.data[stack2.top - 1] == '/')&&stack2.data[stack2.top - 1] != '(')
				{
						pop2(&stack2, &ch);
						calculate(&stack1, ch);
						if (flag == 0)
							return 0;
			    }
					push2(&stack2, str[i]);
			}
			else if (str[i] == '(')
			{
				push2(&stack2, str[i]);
			}
			else if (str[i] == ')')
			{
				while (stack2.data[stack2.top - 1] != '(')
				{
					pop2(&stack2, &ch);
					calculate(&stack1, ch);
					if (flag == 0)
						return 0;
				}
				pop2(&stack2, &str[i]);
			}
		}
	}
	//弹出剩余stack2内东西 
	while (stack2.top > 0)
	{
		pop2(&stack2, &ch);
		calculate(&stack1, ch);
		if (flag == 0)
			return 0;
	}
	printf("%lld\n", stack1.data[stack1.top - 1]);
	return 0;
}
// 1+5/(1-1)   5+5*5*5
