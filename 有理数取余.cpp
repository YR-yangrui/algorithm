//https://www.luogu.org/problemnew/show/P2613
#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=19260817;
long long read()
{
	long long res=0;
	char ch=getchar();
	while(ch<'0' or ch>'9')ch=getchar();
	res=ch-'0';
	while((ch=getchar())>='0' and ch<='9')
		res= (res*10)% mod + ch - '0';
	return res%mod;
}
long long a,b;
long long nb;
long long quick_pow(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	a=read();b=read();
	if(b==0){cout<<"Angry!"<<endl;return 0;}
	nb=quick_pow(b,mod-2);
	long long ans=a*nb%mod;
	cout<<ans<<endl;
	return 0;
}

