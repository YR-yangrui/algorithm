/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月16日 星期三 09时12分50秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
const int maxn=105;
const int INF=0x7fffffff;
int T,n,m,depth[maxn*3],w[maxn*maxn*200],head[maxn*3],cnt,s,t;
//{{{
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
//}}}
struct edge{
    int next,to;
}e[maxn*maxn*200];
void add(int u,int v,int p)
{
    e[cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt;
    w[cnt++]=p;
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
    return depth[t]!=-1;
}
int dfs(int u,int dist)
{
    if(u==t)return dist;
    for(int i=head[u];i!=-1;i=e[i].next)
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
    return 0;
}
int dinic()
{
    int ans=0;
    while(bfs())
        while(int d=dfs(s,INF))
            ans+=d;
    return ans;
}
int tot;
int main()
{
    freopen("二分图多重匹配.in","r",stdin);
    freopen("二分图多重匹配.out","w",stdout);
    cin>>T;
    int k;
    while(T--)
    {
        memset(head,-1,sizeof head);
        tot=cnt=0;
        cin>>n>>m;
        s=0;t=n+m+1;
        for(int i=1;i<=m;i++)
        {
            cin>>k;
            tot+=k;
            add(i+n,t,k);
            add(t,i+n,0);
        }
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            add(s,i,a);
            add(i,s,0);
            while(b--)
            {
                cin>>a;
                add(i,a+n,1);
                add(a+n,i,0);
            }
        }
        std::cout<<(dinic()==tot?"Yes":"No")<<std::endl;
    }
    return 0;
}
