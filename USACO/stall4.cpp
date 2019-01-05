/*
ID:galaxy_6
LANG:C++
TASK:stall4
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=300;
int n,m,s;
struct edge{
        int next,to;
}e[maxn*maxn*5];
int head[500],cnt,w[maxn*maxn*5];
void add(int u,int v,int w)
{
        e[cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
        ::w[cnt++]=w;
}
int depth[maxn*5];
bool bfs(int s,int t)
{
        memset(depth,-1,sizeof depth); depth[s]=0;
        queue<int>q; q.push(s);
        while(!q.empty())
        {
                int u=q.front(); q.pop();
                for(int v=head[u];v!=-1;v=e[v].next)
                {
                        if(depth[e[v].to]==-1 and w[v]>0)
                        {
                                depth[e[v].to]=depth[u]+1;
                                q.push(e[v].to);
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
int Dinic(int s,int t)
{
        int ans=0;
        while(bfs(s,t))
                while(int d=dfs(s,t,0x7fffffff))
                        ans+=d;
        return ans;
}
int main()
{
       freopen("stall4.in","r",stdin);
       freopen("stall4.out","w",stdout);
       memset(head,-1,sizeof head);
       cin>>n>>m;
       for(int i=1;i<=n;i++){add(0,i+200,1);add(i+200,0,0);}
       for(int i=1;i<=m;i++){add(i,401,1);add(401,i,0);}
       for(int i=1;i<=n;i++)
       {
               cin>>s;
               while(s--)
               {
                       int v;
                       cin>>v;
                       add(i+200,v,1);
                       add(v,i+200,0);
               }
       }
       cout<<Dinic(0,401)<<endl;
       return 0;
}
