//https://www.luogu.org/problemnew/show/P3811
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3e6+5;
long long n,p;
long long a[maxn];
int main()
{
	cin>>n>>p;
	cout<<1<<endl;
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=(p-p/i)*a[p%i]%p;
		printf("%lld\n",a[i]);
	}
	return 0;
}

