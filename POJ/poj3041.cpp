/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 20时51分46秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=10010;
int n,k;
struct edge{
        int to,next;
}e[maxn];
int head[505],cnt;
void add(int u,int v)
{
        e[++cnt].next=head[u];
        e[cnt].to=v;
        head[u]=cnt;
}
int ans;
int link[maxn],vis[maxn];
bool dfs(int x)
{
        for(int i=head[x];i;i=e[i].next)
        {
                if(!vis[e[i].to])
                {
                        vis[e[i].to]=1;
                        if(!link[e[i].to] or dfs(link[e[i].to]))
                        {
                                link[e[i].to]=x;
                                return true;
                        }
                }
        }
        return false;
}
int main()
{
       freopen("poj3041.in","r",stdin);
       freopen("poj3041.out","w",stdout);
       cin>>n>>k;
       for(int i=1;i<=k;i++)
       {
               int x,y;
               cin>>x>>y;
               add(x,y+n);
       }
       for(int i=1;i<=n;i++)
       {
               memset(vis,0,sizeof vis);
               if(dfs(i))ans++;
       }
       cout<<ans<<endl;
       return 0;
}
