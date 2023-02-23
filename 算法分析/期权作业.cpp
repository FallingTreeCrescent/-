#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct job
{
	int index,ddl,p;
}work[201];
bool cmp(job x, job y)
{
	return x.p > y.p;
}
int res = 0;
void JS(job *work, int *done, int n)
{
	done[0] = 0;
	for (int j = 1; j < n; j++)
	{
		int r = res;
		while (r >= 0 && work[done[r]].ddl > work[j].ddl && work[done[r]].ddl > r + 1)
			r--;
		if ((r < 0 || work[done[r]].ddl <= work[j].ddl) && work[j].ddl > r + 1)
		{
			for (int i = res; i >= r + 1; i--)
				done[i + 1] = done[i];
			done[r + 1] = j;//把要完成的作业提前
			res++;//作业个数+1
		}
	}
}
int main()
{
	int n, done[201];//存放要完成的作业序号
	int arr[201],b[201];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> work[i].ddl >> work[i].p;
		work[i].index = i;
	}
	sort(work, work + n, cmp);
	JS(work, done, n);
	int sum=0;
	for (int i = 0; i <= res; i++)
	{
		arr[i] = work[done[i]].index;
		//cout<<arr[i]<<" "<<work[arr[i]].p<<endl;
		sum+=work[done[i]].p;
	}
	//sort(arr, arr + res + 1);
	cout<<sum<<endl;
	for (int i = 0; i <= res; i++)
		if(i!=res)cout << arr[i] + 1 << ' ';
		else cout<< arr[i] + 1;
	return 0;
}
/*6
2 25
3 20
3 15
2 10
4 1
4 5 
*/
