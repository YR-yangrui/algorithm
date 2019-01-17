/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 08时18分34秒
*******************************/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=350;
const int INF=0x7fffffff;
int n,m;
struct edge{
        int next,to;
}e[maxn*maxn*20];
int head[10*maxn],cnt,depth[10*maxn],w[maxn*maxn*20],s,t,tot;
void add(int u,int v,int val)
{
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
        w[cnt++]=val;
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
                        if(depth[e[i].to]==-1 and w[i])
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
                }
        }
        return (depth[t]>=0);
}
int dfs(int u,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(w[i] and depth[e[i].to]==depth[u]+1)
                {
                        int d=dfs(e[i].to,min(dist,w[i]));
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
int dinic()
{
        int ans=0;
        while(bfs())
                while(int d=dfs(s,INF))ans+=d;
        return ans;
}
int main()
{
       freopen("最大权闭合子图.in","r",stdin);
       freopen("最大权闭合子图.out","w",stdout);
       memset(head,-1,sizeof head);
       cin>>n>>m;
       s=0;t=n+m+100;
       int b;
       for(int i=1;i<=m;i++)
       {
               cin>>b;
               add(i+n,t,b);
               add(t,i+n,0);
       }
       int a,k;
       for(int i=1;i<=n;i++)
       {
               cin>>a>>k;
               tot+=a;
               add(s,i,a);
               add(i,s,0);
               while(k--)
               {
                       cin>>a;
                       add(i,a+n,INF);
                       add(a+n,i,0);
               }
       }
       cout<<(tot-dinic())<<endl;
}
