/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月29日 星期四 15时21分54秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=505;
const int maxm=3005;
const int inf=0x7fffffff;
const int LG=12;
int n,m,s,t,depth[maxn],cur[maxn],ow[maxm],tmp[maxn],qe[maxn],c[maxn],tot,f[maxn][LG+1],mi[maxn][LG+1];
struct QXX{
    int head[maxn],cnt;
    struct edge{
        int to,next,w;
    }e[maxm];
    QXX(int p=0){memset(head,-1,sizeof head);cnt=p;}
    edge & operator[](const int i){return e[i];}
    void add(int u,int v,int w=0)
    {
        e[cnt].next=head[u];
        e[cnt].to=v;
        e[cnt].w=w;
        head[u]=cnt++;
    }
}e,g;
bool bfs(int s,int t)
{
    queue<int>q;
    memset(depth,0,sizeof depth);
    q.push(s);
    depth[s]=1,cur[s]=e.head[s];
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=e.head[x];i!=-1;i=e[i].next)
        {
            if(e[i].w>0 and !depth[e[i].to])
            {
                depth[e[i].to]=depth[x]+1;
                cur[e[i].to]=e.head[e[i].to];
                if(e[i].to==t)return true;
                q.push(e[i].to);
            }
        }
    }
    return false;
}
int dfs(int now,int dist)
{
    if(now==t) return dist;
    for(int & i=cur[now];i!=-1;i=e[i].next)
        if(e[i].w>0 and depth[e[i].to]==depth[now]+1)
        {
            int d=dfs(e[i].to,min(dist,e[i].w));
            if(d>0)
            {
                e[i].w-=d;
                e[i^1].w+=d;
                return d;
            }
        }
    return 0;
}
int dinic()
{
    int ans=0;
    for(int i=0;i<e.cnt;i++) e[i].w=ow[i];
    while(bfs(s,t))
        while(int d=dfs(s,inf))
            ans+=d;
    return ans;
}
void color(int x,int co)
{
    c[x]=co;
    for(int i=e.head[x];i!=-1;i=e[i].next)
        if(e[i].w>0 and c[e[i].to]!=co)
            color(e[i].to,co);
}
void build(int l,int r)
{
    if(l==r)return;
    s=qe[l],t=qe[l+1];
    int ql=l-1,qr=r+1,cut=dinic();
    color(s,++tot);
    for(int i=l;i<=r;i++)
        if(c[qe[i]]==tot)
            tmp[++ql]=qe[i];
        else 
            tmp[--qr]=qe[i];
    for(int i=l;i<=r;i++)qe[i]=tmp[i];
    g.add(s,t,cut); g.add(t,s,cut);
    build(l,ql); build(qr,r);
}
void dfs(int now)
{
    for(int i=1;i<=LG;i++)
    {
        f[now][i]=f[f[now][i-1]][i-1];
        mi[now][i]=min(mi[now][i-1],mi[f[now][i-1]][i-1]);
    }
    for(int i=g.head[now];i!=-1;i=g[i].next)
    {
        if(g[i].to==f[now][0])continue;
        depth[g[i].to]=depth[now]+1;
        f[g[i].to][0]=now,mi[g[i].to][0]=g[i].w;
        dfs(g[i].to);
    }
}
int getcut(int x,int y)
{
    int res=inf;
    if(depth[x]<depth[y])swap(x,y);
    for(int i=LG;i>=0;i--)
        if(depth[f[x][i]]>=depth[y])
            res=min(res,mi[x][i]),x=f[x][i];
    if(x==y)return res;
    for(int i=LG;i>=0;i--)
        if(f[x][i]!=f[y][i])
            res=min(res,min(mi[x][i],mi[y][i])),x=f[x][i],y=f[y][i];
    return min(res,min(mi[x][0],mi[y][0]));
}
int main()
{
    freopen("最小割树.in","r",stdin);
    freopen("最小割树.out","w",stdout);
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v>>w;
        e.add(u,v,w);
        e.add(v,u,w);
    }
    for(int i=1;i<=n;i++) qe[i]=i;
    for(int i=0;i<e.cnt;i++) ow[i]=e[i].w;
    build(1,n);
    depth[0]=0;depth[1]=1;
    dfs(1);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        cout<<getcut(u,v)<<endl;
    }
    return 0;
}
