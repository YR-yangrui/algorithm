//https://www.luogu.org/problemnew/show/P3390#sub
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=110;
const int c=1e9+7;
long long n,k;
struct Matrix{
	long long a[maxn][maxn];
	Matrix(){memset(a,0,sizeof a);}
};
void in(Matrix & k)
{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>k.a[i][j];
				return;
}
void put(Matrix k)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<k.a[i][j]<<' ';
		cout<<endl;
	}
	return;
}
Matrix te,a,ans;
Matrix mul(Matrix & m,Matrix & b)
{	
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			te.a[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
				{
					te.a[i][j]+=(m.a[i][k]*b.a[k][j])%c;
					te.a[i][j]%=c;
				}
		return te;
}
Matrix quick_power(Matrix & a,long long b)
{
	
	for(int i=1;i<=n;i++)
		ans.a[i][i]=1;
	while(b)
	{
		if(b&1)
			ans=mul(ans,a);
		a=mul(a,a);
		b>>=1;
	}
	return ans;
}
int main()
{
	cin>>n>>k;
	in(a);
	put(quick_power(a,k));
	return 0;
}
