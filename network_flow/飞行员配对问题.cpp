/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月05日 星期六 09时56分19秒
*******************************/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=3000;
int n,m;
struct edge{
        int u,next,to;
}e[maxn*5];
int head[150],cnt,w[maxn],depth[maxn];
void add(int u,int v,int w)
{
        e[cnt].u=u;
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
        ::w[cnt++]=w;
}
bool bfs(int s,int t)
{
        memset(depth,-1,sizeof depth); depth[s]=0;
        queue<int>q; q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                {
                        if(depth[e[i].to]==-1 and w[i]>0)
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
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
void dinic(int s,int t)
{
        int ans=0;
        while(bfs(s,t))
                while(int d=dfs(s,t,0x7fffffff))
                        ans+=d;
        if(ans==0)cout<<"No Solution!\n";
        else 
        {
                cout<<ans<<endl;
               for(int i=0;i<=cnt;i++)
                       if(w[i]>0 and e[i].to<=m and e[i^1].to>m)
                               cout<<e[i].to<<' '<<e[i^1].to<<endl;
        }
}
int main()
{
       freopen("飞行员配对问题.in","r",stdin);
       freopen("飞行员配对问题.out","w",stdout);
       memset(head,-1,sizeof head);
       cin>>m>>n;
       for(int i=1;i<=m;i++)
               add(0,i,1), add(i,0,0);
       for(int i=m+1;i<=n;i++)
               add(i,n+1,1),add(n+1,i,0);
       int a,b;
       while(true)
       {
               cin>>a>>b;
               if(a==-1 and b==-1)break;
               add(a,b,1);
               add(b,a,0);
       }
       dinic(0,n+1);
       return 0;
}
