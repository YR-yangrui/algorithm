//https://www.luogu.org/problemnew/show/P3366#sub
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200010;
struct point{
	int x;
	int y;
	int v;
}p[maxn];
bool cmp(const point & x,const point & y)
{
	return x.v<y.v;
}
int n,m;
int f[maxn];
int find(int x)
{
	if(f[x]!=x)f[x]=find(f[x]);
	return f[x];
}
void unionn(int & x,int & y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)f[fx]=fy;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i].x>>p[i].y>>p[i].v;
	}
	sort(p+1,p+m+1,cmp);
	int tot=0,k=0;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(find(p[i].x)!=find(p[i].y))
		{
			unionn(p[i].x,p[i].y);
			tot+=p[i].v;
			k++;
		}
		if(k==n-1)break;
	}
	cout<<tot;
	return 0;
}
