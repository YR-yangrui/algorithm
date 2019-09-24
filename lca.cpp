#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct edge{
	int to,next;
};

const int maxn=5e5+100;
const int LG=25;
int f[maxn][LG+1],head[maxn],n,m,s,cnt,depth[maxn];
edge e[maxn<<1];

void add(int u,int v)
{
	e[++cnt].next=head[u];
	head[u]=cnt;
	e[cnt].to=v;
}

void dfs(int now)
{
    depth[now]=depth[f[now][0]]+1;
    for(int i=1;i<=LG;i++)
        f[now][i]=f[f[now][i-1]][i-1];
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=f[now][0])
        {
            f[e[i].to][0]=now;
            dfs(e[i].to);
        }
}

int LCA(int x,int y)
{
    if(depth[x]<depth[y])swap(x,y);
    for(int i=LG;i>=0;i--)
        if(depth[f[x][i]]>=depth[y])
            x=f[x][i];
    if(x==y)return x;
    for(int i=LG;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i],y=f[y][i];
    return f[x][0];
}

int main()
{
}
