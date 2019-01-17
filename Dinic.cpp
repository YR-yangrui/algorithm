/*******************************
Author:galaxy yr
LANG:C++
Created Time:2018年12月31日 星期一 18时34分13秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
const int maxn=1e5+10;
int w[2*maxn],n,m,ans,depth[2*maxn],s,t,u,v,val;
struct edge{
        int to,next;
}e[maxn*2];
int head[maxn*2],cnt;
void add(int u,int v,int k)
{
        e[cnt].next=head[u];
        e[cnt].to=v;
        w[cnt]=k;
        head[u]=cnt;
        cnt++;
}
int dfs(int u,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(depth[u]+1==depth[e[i].to] and w[i]>0)
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
bool bfs()
{
        queue<int>q;
        memset(depth,-1,sizeof depth);
        q.push(s);
        depth[s]=0;
        while(!q.empty())
        {
                int v=q.front();q.pop();
                for(int i=head[v];i!=-1;i=e[i].next)
                {
                        if(w[i] >0 and depth[e[i].to] ==-1 )
                        {
                                depth[e[i].to]=depth[v]+1;
                                q.push(e[i].to);
                        }
                }
        }
        return depth[t]!=-1;
}
int Dinic()
{
        int ans=0;
        while(bfs())
                while(int d=dfs(s,INF))ans+=d;
        return ans;
}
int main()
{
      
        cin>>n>>m>>s>>t;
        memset(head,-1,sizeof head);
        for(int i=1;i<=m;i++)
        {
                cin>>u>>v>>val;
                add(u,v,val);
                add(v,u,0);
        }
        cout<<Dinic()<<endl;
        return 0;
}
