//https://www.luogu.org/problemnew/show/P3367
#include<iostream>
using namespace std;
const int maxn=10005;
int n,m;
int f[maxn];
int find(int x)
{
	if(x!=f[x])f[x]=find(f[x]);
	return f[x];
}
void unionn(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
		f[fy]=fx;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
			unionn(x,y);
		else if(find(x)==find(y))cout<<'Y'<<endl;
			else  cout<<"N\n";
	}
	return 0;
}

