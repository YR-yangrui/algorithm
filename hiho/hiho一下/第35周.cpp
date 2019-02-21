/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 21时24分35秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5005;
int n,m;
struct edge{
        int to,next;
}e[maxn*2];
int head[maxn*2],cnt;
void add(int u,int v)
{
        e[++cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
}
int ans,vis[maxn],link[maxn];
bool find(int x)
{
        for(int i=head[x];i;i=e[i].next)
        {
                if(!vis[e[i].to])
                {
                        vis[e[i].to]=true;
                        if(!link[e[i].to] or find(link[e[i].to]))
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
       freopen("35.in","r",stdin);
       freopen("35.out","w",stdout);
       int n,m;
       cin>>n>>m;
       for(int i=1;i<=m;i++)
       {
               int u,v;
               cin>>u>>v;
               add(u,v);
               add(v,u);
       }
       for(int i=1;i<=n;i++)
       {
               memset(vis,0,sizeof vis);
               ans+=find(i);
       }
       ans>>=1;
       cout<<ans<<endl<<(n-ans)<<endl;
       return 0;
}
