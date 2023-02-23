#include <iostream>
using namespace std;
int main()
{
	int n,sum=0,tmp,x;
	cin>>n;
	cin>>tmp;
	n--;
	while(n--)
	{
		cin>>x;
		if(x>tmp)sum+=x-tmp;
		tmp=x;
	}
	cout<<sum;
	return 0;
}
