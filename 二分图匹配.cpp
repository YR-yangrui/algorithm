/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月05日 星期六 15时46分45秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5005;
int n,m,k;
struct edge{
        int to,next;
}e[5000000];
int head[maxn],cnt;
void add(int u,int v)
{
        e[++cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
}
int link[maxn*2];
bool vis[2*maxn];
int find(int u)
{
        for(int i=head[u];i;i=e[i].next)
                if(!vis[e[i].to])
                {
                        vis[e[i].to]=1;
                        if(!link[e[i].to] or find(link[e[i].to]) )
                        {
                                link[e[i].to]=u;
                                return true;
                        }
                }
        return false; 
}
int main()
{
       freopen("二分图匹配.in","r",stdin);
       freopen("二分图匹配.out","w",stdout);
       cin>>n>>m>>k;
       for(int i=1;i<=k;i++)
       {
               int u,v;
               cin>>u>>v;
               if(v<=m)
               add(u,v);
       }
       int ans=0;
       for(int i=1;i<=n;i++)
       {
               ans+=find(i);
               memset(vis,0,sizeof vis);
       }
       cout<<ans<<endl;
}
