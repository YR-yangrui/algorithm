/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月05日 星期六 14时46分50秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=500;
int n,p,c,m;
char rubbish;
struct edge{
        int to,next;
}e[maxn*10];
int head[maxn],cnt,w[maxn];
void add(int u,int v,int w)
{
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
        ::w[cnt++]=w;
}
int depth[maxn*10];
bool bfs(int s,int t)
{
        memset(depth,-1,sizeof depth);depth[s]=0;
        queue<int>q;q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                        if(depth[e[i].to]==-1 and w[i]>0)
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
        }
        return (depth[t]>=0);
}
int dfs(int u,int t,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(depth[e[i].to]==depth[u]+1 and w[i]>0)
                {
                        int d=dfs(e[i].to,t,min(dist,w[i]));
                        if(d>0)
                        {
                                w[i]-=d;
                                w[i^1]+=d;
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
                while(int d=dfs(s,t,0x7fffffff))ans+=d;
        return ans;
}
int s,t;
int main()
{
       freopen("poj1459.in","r",stdin);
       freopen("poj1459.out","w",stdout);
       while(cin>>n>>p>>c>>m)
       {
               memset(head,-1,sizeof head);
               memset(w,0,sizeof w);
               s=n;t=n+1;
               int u,v,w;
               for(int i=1;i<=m;i++)
               {
                       cin>>rubbish>>u>>rubbish>>v>>rubbish>>w;
                       if(u==v)continue;
                       add(u,v,w);add(v,u,0);
               }
               for(int i=1;i<=p;i++)
               {
                       cin>>rubbish>>u>>rubbish>>w;
                       add(s,u,w);
                       add(u,s,0);
               }
               for(int i=1;i<=c;i++)
               {
                       cin>>rubbish>>u>>rubbish>>w;
                       add(u,t,w);
                       add(t,u,0);
               }
               cout<<dinic(s,t)<<endl;
       }
}
