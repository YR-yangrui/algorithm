/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月21日 星期一 17时56分25秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=500;
const int INF=0x7fffffff;
struct edge{
        int to,next,w;
}e[maxn*maxn*10];
int depth[maxn*10],head[10*maxn],cnt,n,m,s,t;
void add(int u,int v,int w)
{
        e[cnt].to=v;
        e[cnt].next=head[u];
        e[cnt].w=w;
        head[u]=cnt++;
}
bool bfs(int s,int t)
{
        memset(depth,-1,sizeof depth);depth[s]=0;
        queue<int>q;q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                        if(depth[e[i].to]==-1 and e[i].w>0)
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
        }
        return (depth[t]!=-1);
}
int dfs(int u,int t,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(e[i].to>0 and depth[e[i].to]==depth[u]+1)
                {
                        int d=dfs(e[i].to,t,min(dist,e[i].w));
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
int dinic(int s,int t)
{
        int ans=0;
        while(bfs(s,t))
                while(int d=dfs(s,t,INF))
                        ans+=d;
        return ans;
}
int u,v,a;
int main()
{
       freopen("善意的投票.in","r",stdin);
       freopen("善意的投票.out","w",stdout);
       memset(head,-1,sizeof head);
       cin>>n>>m;
       s=0,t=n+1;//s 1 t 0
       for(int i=1;i<=n;i++)
       {
               cin>>a;
               if(a)
               {
                       add(s,i,1);
                       add(i,s,0);
               }
               else 
               {
                       add(i,t,1);
                       add(t,i,0);
               }
       }
       for(int i=1;i<=m;i++)
       {
               cin>>u>>v;
               add(u,v,1);
               add(v,u,1);
       }
       cout<<dinic(s,t)<<endl;
       return 0;
}
