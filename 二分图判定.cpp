/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 11时24分49秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=40005;
int T,n,m;
struct edge{
        int to,next;
}e[maxn*2];
int head[10050],cnt;
void add(int u,int v)
{
        e[++cnt].next=head[u];
        e[cnt].to=v;
        head[u]=cnt;
}
int vis[10050],co[10050];
bool dfs(int now,int fa)
{
        vis[now]=1;
        for(int i=head[now];i;i=e[i].next)
        {
                //if(e[i].to==fa)continue;
                if(!vis[e[i].to])
                {
                        co[e[i].to]=!co[now];
                        if(!dfs(e[i].to,now))return 0;
                }
                else 
                        if(co[e[i].to]==co[now])
                                return 0;
        }
        return 1;
}
int main()
{
       freopen("二分图判定.in","r",stdin);
       freopen("二分图判定.out","w",stdout);
       cin>>T;
       while(T--)
       {
               cin>>n>>m;
               cnt=0;
               memset(head,0,sizeof head);
               memset(vis,0,sizeof vis);
               memset(co,0,sizeof co);
               int u,v;
               for(int i=1;i<=m;i++)
               {
                       cin>>u>>v;
                       add(u,v);
                       add(v,u);
               }
               int i;
               for(i=1;i<=n;i++)
                       if(!vis[i] and !dfs(i,0))
                       {
                               cout<<"Wrong\n";
                               break;
                       }
               if(i>n)
               cout<<"Correct\n";
       }
       return 0;
}
