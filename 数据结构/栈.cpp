#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//顺序栈
template<class T>
class Astack{
private:
	int size;
	T *stackarray;
	int top;
public:
    Astack(int maxsize)
	{
		size = maxsize;
		stackarray = new T[maxsize];
		top = -1;
	}
	~Astack(){delete[] stackarray;}
	Stack(void);
	void push(const T&item);
	T top();
	void clearstack();
	T peak() const;
	int stackempty() const;
	int stackfull() const;
};
struct cell{
	int x;
	struct cell *next;
};
//要求在堆栈中查找元素n在栈中第一次出现的位置
//并将该位置元素移至栈顶，同时其他元素次序不变。
int* SelectItem1(int a[],int maxsize,int n){
	int m = 0, s = 0;
	while(a[m]!=n)
	{
		m++;
	}
	s = a[m];
	for (int i = m - 1; i > 0;i++){
		a[m] = a[m - 1];
	}
	a[0] = s;
	return a;
}
struct cell* SelectItem2(struct cell* head,int n){
	struct cell *p, *q, *r;
	if(n==head->x)
		return head;
	else
	{
	p = head->next;
	r = head;
	q= (struct cell *)malloc(sizeof(struct cell));
	for (int i = 0;p->x!=n ; i++)
	{
		r->next = p;
		p = p->next;
	}
	q = r->next;
	r->next = p;
	q->next = head;
	}
	return head;
}