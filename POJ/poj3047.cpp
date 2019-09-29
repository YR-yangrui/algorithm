/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月28日 星期六 21时35分41秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct edge{
    int to,next,w;
};

const int maxn=505;
const int inf=0x7fffffff;
int n,k,head[maxn*3],cnt,s,t,depth[maxn*3],dis[maxn*3];
edge e[maxn*maxn];

void add(int u,int v,int w)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u]=cnt++;
}

bool bfs()
{
    memset(depth,-1,sizeof depth);depth[s]=0;
    std::queue<int>q;q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=head[u];i!=-1;i=e[i].next)
            if(depth[e[i].to]==-1 && e[i].w>0)
            {
                depth[e[i].to]=depth[u]+1;
                q.push(e[i].to);
            }
    }
    return depth[t]!=-1;
}

int dfs(int u,int dist)
{
    if(u==t)return dist;
    for(int i=head[u];i!=-1;i=e[i].next)
        if(depth[e[i].to]==depth[u]+1 && e[i].w>0)
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

int Dinic()
{
    int ans=0;
    while(bfs())
        while(int d=dfs(s,inf))
            ans+=d;
    return ans;
}

int main()
{
    freopen("poj3047.in","r",stdin);
    freopen("poj3047.out","w",stdout);
    memset(head,-1,sizeof head);
    cin>>n>>k;
    s=n+n+1;t=n+n+2;
    for(int i=1;i<=n;i++)
    {
        add(s,i,1);
        add(i,s,0);
        add(i+n,t,1);
        add(t,i+n,0);
    }
    int u,v;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v;
        add(u,v+n,1);
        add(v+n,u,0);
    }
    cout<<Dinic()<<endl;
    return 0;
}
