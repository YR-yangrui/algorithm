/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月15日 星期二 21时40分50秒
*******************************/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cassert>
const int maxn=20010;
using std::cout;
using std::endl;
struct IO{
        template<class T>
        IO & operator>>(T &res)
        {
                T q=1;
                char ch=getchar();
                while(ch<'0' or ch>'9')
                {
                        if(ch=='-')q=-q;
                        ch=getchar();
                }
                res=(ch^48);
                while((ch=getchar())>='0' and ch<='9')
                        res=res*10+ch-'0';
                return *this;
        }
}cin;
int n,m,s,t,ans;
struct edge{
        int from,to,next;
}e[maxn*10];
int head[100000],cnt,w[100000],depth[maxn];
void add(int u,int v,int p)
{
        e[cnt].from=u;
        e[cnt].to=v;
        e[cnt].next=head[u];
        w[cnt]=p;
        head[u]=cnt++;
}
bool bfs()
{
        memset(depth,-1,sizeof depth);depth[s]=0;
        std::queue<int>q;q.push(s);
        while(!q.empty())
        {
                int u=q.front();q.pop();
                for(int i=head[u];i!=-1;i=e[i].next)
                        if(depth[e[i].to]==-1 and w[i]>0)
                        {
                                depth[e[i].to]=depth[u]+1;
                                q.push(e[i].to);
                        }
        }
        return (depth[t]>=0);
}
int dfs(int u,int dist)
{
        if(u==t)return dist;
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                if(depth[e[i].to]==depth[u]+1 and w[i]>0)
                {
                        int d=dfs(e[i].to,std::min(dist,w[i]));
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
void dinic()
{
        while(bfs())
                while(int d=dfs(s,0x7fffffff))
                        ans-=d;
        return;
}
int f[2000];
int find(int x)
{
        return f[x]==x?x:f[x]=find(f[x]);
}
void output(int x)
{
        cout<<x<<' ';
        for(int i=head[x];i!=-1;i=e[i].next)
                if(w[i]==0 and e[i].to>n)
                        output(e[i].to-n);
}
int main()
{
       freopen("最小路径覆盖.in","r",stdin);
       freopen("最小路径覆盖.out","w",stdout);
       cin>>n>>m;
       ans=n;
       t=n+n+1;
       memset(head,-1,sizeof head);
       for(int i=1;i<=m;i++)
       {
               int u,v;
               cin>>u>>v;
               add(u,v+n,1);
               add(v+n,u,0);
       }
       for(int i=1;i<=n;i++)
               add(s,i,1),add(i,s,0);
       for(int i=1;i<=n;i++)
               add(i+n,t,1),add(t,i+n,0);
       dinic();
       for(int i=0;i<=n;i++)f[i]=i;
       for(int i=0;i<cnt;i++)
               if(w[i]==0 and e[i].to>n and e[i].to<=n*2 and e[i].from>0 and e[i].from<=n)
                       if(f[e[i].from]!=f[e[i].to-n])
                               f[e[i].to-n]=f[e[i].from];
       for(int i=1;i<=n;i++)
               if(f[i]==i)
                       output(i),cout<<endl;
       std::cout<<ans<<std::endl;
}
