//https://www.luogu.org/problemnew/show/P3368
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=5e5+100;
long long n,m;
long long tree[maxn];
inline long long lowbit(int x){return x & -x;};
void add(long long x,long long v)
{
	while(x<=n)
	{
		tree[x]+=v;
		x+=lowbit(x);
	}
	return;
}
long long sum(long long s)
{
	long long res=0;
	while(s>0)
	{
		res+=tree[s];
		s-=lowbit(s);
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	long long last=0;
	for(long long i=1,x;i<=n;++i)
	{
		scanf("%lld",&x);
		add(i,x-last);
		last=x;
	}
	for(long long i=1,x,y,z,k;i<=m;i++)
	{
		scanf("%lld",&k);
		if(k==2)
		{
			scanf("%lld",&x);
			printf("%lld\n",sum(x));
		}
		else
		{
			scanf("%lld%lld%lld",&x,&y,&z);
			add(x,z);
			add(y+1,-z);
		}
	}
}

