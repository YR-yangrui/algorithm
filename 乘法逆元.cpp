//https://www.luogu.org/problemnew/show/P3811
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3e6+5;
long long n,p;
long long a[maxn];
void solve()
{
	cout<<1<<endl;
        //线性求逆元
	a[1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=(p-p/i)*a[p%i]%p;
		printf("%lld\n",a[i]);
	}
}
//费马小定理
//x^p mod p=1
long long ksm(long long a,long long b,long long c)
{
        long long ans=1;
        while(b)
        {
                if(b&1)
                        ans=ans*a%c;
                a=a*a%c;
                b>>=1;
        }
        return ans;
}
long long solve(long long a,long long b)
{
        return ksm(a,b-2);
}
//扩展欧几里得
void exgcd(long long a,long long b,long long & x,long long &y)
{
        if(b==0)
        {
                x=1;
                y=0;
                return;
        }
        exgcd(b,a%b,x,y);
        long long t=x;
        x=y; y=t-a/b*y;
}
long long solve(long long a,long long b)
{
        long long k1,k2;
        exgcd(a,b,k1,k2);
        return k1;
}
int main()
{
	cin>>n>>p;
        solve();
	return 0;
}

