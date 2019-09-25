/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月17日 星期四 19时36分32秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1005;
const int INF=0x7fffffff;
struct edge{
    int to,next,cost,w;
}e[maxn*maxn*50];
int head[maxn*10],cnt,path[maxn*10],pre[maxn*10],dis[maxn*10];
void add(int u,int v,int w,int c)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].cost=c;
    e[cnt].w=w;
    head[u]=cnt++;
}
bool SPFA(int s,int t)
{
    memset(pre,-1,sizeof pre);
    memset(dis,0x7f,sizeof dis);
    dis[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();  q.pop();
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(e[i].w>0 and dis[u]+e[i].cost<dis[e[i].to])
            {
                dis[e[i].to]=dis[u]+e[i].cost;
                pre[e[i].to]=u;
                path[e[i].to]=i;
                q.push(e[i].to);
            }
        }
    }
    return (pre[t]!=-1);
}
int MinCost_Flow(int s,int t)
{
    int cost=0,flow=0;
    while(SPFA(s,t))
    {
        int f=INF;
        for(int u=t;u!=s;u=pre[u])
        {
            if(e[path[u]].w<f)
                f=e[path[u]].w;
        }
        flow+=f;
        cost+=dis[t]*f;
        for(int u=t;u!=s;u=pre[u])
        {
            e[path[u]].w-=f;
            e[path[u]^1].w+=f;
        }
    }
    return cost;
}
