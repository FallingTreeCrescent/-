#include <iostream>
using namespace std;
int sum, n, pos;
int a[505] = {1};
void print(int pos)
{
	cout << n << "=";
	for (int i = 1; i <= pos - 1; i++)
		cout << a[i] << "+";
	cout << a[pos] << endl;
}
void dfs(int pos)
{
	if (sum == 0)
	{
		return;
	}
	for (int i = a[pos - 1]; i <= sum; i++)
	{
		if (i < n)
		{
			a[pos] = i;
			sum -= i;
			print(pos);
			dfs(pos + 1);
			sum += i;
		}
	}
	return;
}

int main()
{
	cin >> n;
	sum = n;
	dfs(1);
	return 0;
}
