/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 10时05分10秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=20010;
int n,m;
struct edge{
        int from,to,next,w;
}e[maxn];
int head[505],cnt,depth[505],s,t;
void add(int u,int v,int k)
{
        e[cnt].from=u;
        e[cnt].w=k;
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt++;
}
bool bfs()
{
        memset(depth,-1,sizeof depth);depth[s]=0;
        queue<int>q;q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                {
                        if(depth[e[i].to]==-1 and e[i].w>0)
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
                }
        }
        return depth[t]>=0;
}
int dfs(int u,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(depth[e[i].to]==depth[u]+1 and e[i].w>0)
                {
                        int d=dfs(e[i].to,min(dist,e[i].w));
                        if(d>0)
                        {
                                e[i].w-=d;
                                e[i^1].w+=d;
                                return d;
                        }
                }
        }
        return 0;
}
int dinic()
{
        int ans=0;
        while(bfs())
                while(int d=dfs(s,0x7fffffff))
                        ans+=d;
        return ans;
}
int vis[505];
void bfs(int st)
{
        queue<int>q;q.push(st);
        vis[st]=1;
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                        if(e[i].w>0 and !vis[e[i].to])
                        {
                                vis[e[i].to]=1;
                                q.push(e[i].to);
                        }
        }
        return;
}
int main()
{
       freopen("求最小割.in","r",stdin);
       freopen("求最小割.out","w",stdout);
       memset(head,-1,sizeof head);
       cin>>n>>m;
       s=1,t=n;
       for(int i=1;i<=m;i++)
       {
               int u,v,c;
               cin>>u>>v>>c;
               add(u,v,c);
               add(v,u,0);
       }
       cout<<dinic()<<' ';
       bfs(s);
       int ans=0;
       for(int i=1;i<=n;i++)
               if(vis[i])ans++;
       cout<<ans<<endl;
       for(int i=1;i<=n;i++)
               if(vis[i])cout<<i<<' ';
       cout<<endl;
       return 0;
}
