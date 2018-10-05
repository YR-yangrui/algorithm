//https://www.luogu.org/problemnew/show/P3374#sub
#include<cstdio>
using namespace std;
const int maxn=5e+5+100;
int a[maxn],c[maxn];
int n,m;
int lowbit(int x)
{
	return x & -x;
}
void updata(int x,int y)
{
	while(x<=n)
	{
		c[x]+=y;
		x+=lowbit(x);
	}
}
int sum(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=c[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)updata(i,a[i]);
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1)
			updata(y,z);
		else 
			printf("%d\n",sum(z)-sum(y-1));
	}
	return 0;
}

