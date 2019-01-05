/*******************************
Author:galaxy yr
LANG:C++
Created Time:2018年12月31日 星期一 11时39分33秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x7ffffff;
const int maxn=100;
int go[maxn],w[maxn][maxn],n,pre[maxn],sum;
/*{{{maxflow-base*/
int dfs(int u,int t)
{
        if(u==t)return go[u];
        for(int i=1;i<=n;i++)
        {
                if(!go[i] and w[u][i])
                {
                        go[i]=min(go[i],w[u][i]);
                        int d=dfs(i,t);
                        if(d>0)
                        {
                                w[u][i]-=d;w[i][u]+=d;
                                return d;
                        }
                }
        }
        return 0;
}
int ford_fulkerson(int s,int t)
{
        int f,flow=0;
        while(true)
        {
                memset(go,0,sizeof go);go[s]=INF;
                if(f=dfs(s,t))flow+=f;
                else return flow;
        }
}
int bfs(int s,int t)
{
        queue<int>q;memset(go,0,sizeof go);q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=1;i<=n;i++)
                        if(!go[i] and w[u][i])
                        {
                                go[i]=min(go[u],w[u][i]);
                                pre[i]=u;
                                q.push(i);
                                if(i==u)return go[i];
                        }
        }
}
int Edmonds_Karp(int s,int t)
{
        int m;
        while(m=bfs(s,t))
        {
                sum+=m;int tmp=t;
                for(int i=t;i!=s;i=pre[i])
                {
                        w[pre[i]][i]-=m;
                        w[i][pre[i]]+=m;
                }
        }
}
/*}}}*/
/*{{{maxflow-Dinic*/
int depth[maxn];
int dfs(int u,int t,int dist)
{
        if(u==t)return dist;
        for(int i=1;i<=n;i++)
        {
                if((depth[u]==depth[i]+1) and w[u][i]>0)
                {
                        int d=dfs(i,t,min(dist,w[u][i]));
                        if(d>0)
                        {
                                w[u][i]-=d;
                                w[i][u]+=d;
                                return d;
                        }
                }
        }
}
bool bfs2(int s,int t)
{
        queue<int>q;
        memset(depth,-1,sizeof depth);
        depth[t]=0;q.push(s);
        while(!q.empty())
        {
                int v=q.front();q.pop();
                for(int u=1;u<=n;u++)
                {
                        if(w[u][v] > 0 and depth[u] < 0)
                        {
                                depth[u]=depth[v]+1;
                                q.push(u);
                        }
                }
        }
}
int Dinic()
{
        int ans=0;
        while(!q.empty())
        {
                bfs();
                if(depth[s] < 0)return ans;
                while(int d=dfs(s,t,INF))ans+=d;
        }
        return ans;
}
/*}}}*/
int main()
{
}
