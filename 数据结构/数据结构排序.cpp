#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[50001], b[50001];
void qsort(int l, int r) //��������ͷ��β��
{
	int mid = a[(l + r) / 2]; //�м���,ע�ⲻ����mid=(l+r)/2,��Ȼ�ݹ�������
	int i = l, j = r;
	do
	{
		while (a[i] < mid)
			i++; //������벿�ֱ��м��������
		while (a[j] > mid)
			j--;	//�����Ұ벿�ֱ��м���С����
		if (i <= j) //�����һ�鲻����������������С�Ҵ󣩵���
		{
			swap(a[i], a[j]); //����
			i++;
			j--;
		}
	} while (i <= j); //����ע��Ҫ��=
	if (l < j)
		qsort(l, j); //�ݹ�������벿��
	if (i < r)
		qsort(i, r); //�ݹ������Ұ벿��
} //ʱ�临�Ӷ�������ƽ��nlbn,n2,nlbn�����ȶ����ռ临�Ӷ�lbn~n
void insertsort(int length) //����
{
	for (int i = 2; i <= length; i++)
	{
		a[0] = a[i]; //�ڱ���ʱ���Ҫ���������
		int j;
		for (j = i - 1; a[0] < a[j]; j--)
		{
			a[j + 1] = a[j]; //�ҵ�Ҫ�����λ��
		}
		a[j + 1] = a[0]; //����
	}
} //ʱ�临�Ӷ�������ƽ��n,n2,n2���ȶ����ռ临�Ӷ�1
void shellsort(int n)				//ϣ������
{									//�������������ʱ��ȫ����в��ţ��Բ��ŵ��Ż�
	int d;							//��ʾ���
	for (d = n / 2; d >= 1; d /= 2) //����
	{
		for (int i = d + 1; i <= n; i++) //����������
		{
			a[0] = a[i];   //�ڱ���¼��ʼֵ
			int j = i - d; //��λ��Ҫ������ֵ���Ƿ���Ҫ����
			while (j > 0 && a[0] < a[j])
			{
				a[j + d] = a[j]; //�ҵ�Ҫ�����λ��
				j -= d;
			}				 //���±�Խ����һ�αȽϲ��ý����˳�ѭ��
			a[j + d] = a[0]; //����
		}
	} //�ֶ�ģ�⣬d=1ʱ���ǲ����㷨
} //ʱ�临�Ӷ�������ƽ��n1.3,n2,nlbn~n2�����ȶ����ռ临�Ӷ�1
void bubblesort1(int n) //ð������1 ��һ�������������������
{
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n - i + 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
} //ʱ�临�Ӷ�������ƽ��n2,n2,n2���ȶ����ռ临�Ӷ�1
void bubblesort2(int n) //ð������2
{
	int swap = n;	  //��¼��һ��ð���У���󽻻���¼��λ��
	while (swap != 0) //������һ��ѭ��û�н�������ôswapΪ0�˳�ѭ����ǰ����������������һ������
	{
		int bound = swap; // bound��¼���������е����һ��λ��
		swap = 0;
		for (int j = 1; j < bound; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				swap = j;
			}
		}
	}
} //ʱ�临�Ӷ�������ƽ��n,n2,n2���ȶ����ռ临�Ӷ�1
void selection(int n) //ѡ������
{
	for (int i = 1; i < n; i++)
	{
		int index = i; //�ؼ���С����i��,����ɨһ�鿴�Ƿ�����Сֵ����i���������򽻻�
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] < a[index])
				index = j;
		} //����Сֵ��λ��
		if (i != index)
		{
			int tmp = a[i];
			a[i] = a[index];
			a[index] = tmp;
		}
	}
} //ʱ�临�Ӷ�������ƽ��n2,n2,n2�����ȶ����ռ临�Ӷ�1
void Adjust(int k, int m)
{
	int i = k;
	int j = 2 * i;
	while (j <= m)
	{
		if (j < m && a[j + 1] > a[j]) // jָ��i���ҽڵ�Ľϴ���
		{
			j++;
		}
		if (a[i] >= a[j]) //���ϴ����Ҫ����˳�ѭ��
		{
			break;
		}
		else
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i = j; //����һ���ж�ֱ��Ҷ�ڵ����
			j = 2 * i;
		}
	}
}
void heapsort(int n) //������
{
	for (int i = n / 2; i >= 1; i--) //��ʼ�������
	{
		Adjust(i, n);
	}
	for (int i = 1; i < n; i++)
	{
		int tmp = a[1];
		a[1] = a[n - i + 1];
		a[n - i + 1] = tmp;
		Adjust(1, n - i); //ɸѡ���ڵ��������ɴ����
	}
} //ʱ�临�Ӷ�������ƽ��nlbn,nlbn,nlbn�����ȶ����ռ临�Ӷ�1
void countsort(int n) //���������ʺ������Ҽ��е����ݣ������������¼���ִ���
{					  //�Ż���������Сֵ�����ֵ���㿪����Ĵ�С�Ӷ����ٿռ��˷�
	memset(b, 0, sizeof(b));
	for (int i = 1; i <= n; i++)
	{
		b[a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		while (b[i]--)
		{
			printf("%d ", i);
		}
	}
} //ʱ�临�Ӷ�n+k
void Merge(int r[], int r1[], int s, int m, int t) //һ�ι鲢
{
	int i = s, j = m + 1, k = s;
	while (i <= m && j <= t)
	{
		if (r[i] <= r[j])
		{
			r1[k] = r[i];
			k++, i++;
		}
		else
		{
			r1[k] = r[j];
			k++, j++;
		}
	}
	while (i <= m)
	{
		r1[k] = r[i];
		k++, i++;
	}
	while (j <= t)
	{
		r1[k] = r[j];
		k++, j++;
	}
}
void MergePass(int r[], int r1[], int n, int h)
{ //һ�˹鲢����rΪ���鲢���У�r1Ϊ��ʱ�ռ䣬hΪ���������г���
	int i, k;
	i = 1;
	while (i <= n - 2 * h + 1) //���Էָ������������������
	{
		Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
		i = i + 2 * h;
	}
	if (i < n - h + 1) //���Էָ�����������������У���һ������Ϊh���ڶ�������С��h
	{
		Merge(r, r1, i, i + h - 1, n);
	}
	else
	{ //ֻ�ָܷ��1�������������У�����<=h,��r���ݸ��Ƶ�r1��
		for (k = i; k <= n; k++)
		{
			r1[k] = r[k];
		}
	}
} //һ�˹鲢�����Ӷ�Ϊn
void Mergesort(int r[], int r1[], int n) //�鲢����
{
	int h = 1;
	while (h < n)
	{
		MergePass(r, r1, n, h);
		h *= 2;
		MergePass(r1, r, n, h);
		h *= 2;
	}
} //ʱ�临�Ӷ�������ƽ��nlbn,nlbn,nlbn���ȶ����ռ临�Ӷ�n
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	// qsort(1, n);
	// insertsort(n);
	// shellsort(n);
	// bubblesort1(n);
	// bubblesort2(n);
	// selection(n);
	// countsort(n);
	 heapsort(n);
	//Mergesort(a, b, n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
/*7
48 77 35 62 55 14 38*/
// 14 35 38 48 55 62 77
