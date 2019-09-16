#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int dis[maxn],vis[maxn];
struct{
        int to,next,w;
}e[maxn];
int head[maxn],cnt;
void add(int u,int v,int w)
{
        e[++cnt].to=v;
        e[cnt].w=w;
        e[cnt].next=head[u];
        head[u]=cnt;
}
void djikstra(int start)
{
        memset(dis,127,sizeof dis);
        dis[start]=0;
        priority_queue<pair<int,int>>q;
        q.push(make_pair(0,start));
        while(!q.empty())
        {
                int x=q.top().second;q.pop();
                if(vis[x])continue;
                vis[x]=1;
                for(int i=head[x];i;i=e[i].next)
                {
                        int y=e[i].to,w=e[i].w;
                        if(dis[y]>dis[x]+w)
                        {
                                dis[y]=dis[x]+w;
                                q.push(make_pair(-dis[y],y));
                        }
                }
        }
}
int main()
{
}
