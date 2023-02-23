#include <iostream>
using namespace std;
typedef struct b {
	int veradj;           //�������
	int cost;             //Ȩֵ
	struct b* link = nullptr;
}edge,* epointer;         //��������
typedef struct a {
	int vername;          //ͷ�������
	epointer adjacent = nullptr;    //ͷ���ָ�������
}Head;
int main() {
	Head head[20000];
	int m, n;
	cin >> m >> n;
	for (int k = 0;k < m;k++)
		head[k].vername = k;
	int a, b, c;
	while (n--) {
		cin >> a >> b >> c;
		epointer p = new(edge);
		p->veradj = b;
		p->cost = c;
		p->link = nullptr;
		epointer q = head[a].adjacent;
		epointer r = nullptr;
		if (q == nullptr) {
			head[a].adjacent = p;
		}
		else {
			while (q != nullptr && b > q->veradj) {
				r = q;
				q = q->link;
			}
			if (q == nullptr)                 //p����β���
				r->link = p; 
			else {
				if (r == nullptr) {           //p�����׽��
					head[a].adjacent = p;
					p->link = q;
				}
				else {                        //p�����м�
					r->link = p;
					p->link = q;
				}
			}
		}/*else*/
	}/*while*/
	for (int k = 0;k < m;k++) {
		int flag = 0;
		epointer q = head[k].adjacent;
		if (q != nullptr)
			flag = 1;
		if (flag)
			cout << k << ":";
		while (q != nullptr) {
			cout << "(" << k << "," << q->veradj << "," << q->cost << ")";
			q = q->link;
		}
		if(flag)
		cout << endl;
	}/*for*/
}
