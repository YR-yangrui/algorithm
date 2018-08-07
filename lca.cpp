#include<iostream>
using namespace std;
const int maxn=5e5+100;
const int LG=25;
int father[maxn];
int d[maxn];
int f[maxn][LG];
int head[maxn];
int n,m,s;
struct edge{
	int to,next;
}e[maxn];
int cnt;
void add(int u,int v)
{
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}
void getfather(int fa)
{
	for(int i=head[fa];i;i=e[i].next)
		if(e[i].to!=fa)
		{
			d[i]=d[fa]+1;
			for(int j=0;j<20;j++)
				f[i][j+1]=f[f[i][j]][j];
		}
}
int main()
{
}
