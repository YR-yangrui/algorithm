/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月31日 星期六 09时07分50秒
*******************************/
#include<cstdio>
#include<algorithm>
using namespace std;
struct IO{
       template<typename T>
               IO & operator>>(T&res)
               {
                      char ch=getchar();
                      T q=1;
                      while(ch<'0' or ch>'9'){if(ch=='-')q=-q;ch=getchar();}
                      res=(ch^48);
                      while((ch=getchar())>='0' and ch<='9')
                      res=(res<<1)+(res<<3)+(ch^48);
                      res*=q;
                      return *this;
              }
}cin;
const int inf=1e7+10;
const int maxn=100010;
int n,m,head[maxn],cnt;
struct edge{
    int to,next,w;
}e[maxn<<1];
void add(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
int md[maxn],size[maxn],dis[maxn],rem[maxn];
int vis[maxn],test[inf],judge[inf],q[maxn],query[1010],rt,ans,sum;
void get_rt(int u,int fa)
{
    size[u]=1;md[u]=0;
    for(int i=head[u];i;i=e[i].next)
        if(e[i].to!=fa and !vis[e[i].to])
        {
            get_rt(e[i].to,u);
            size[u]+=size[e[i].to];
            md[u]=max(md[u],size[e[i].to]);
        }
    md[u]=max(md[u],sum-size[u]);
    if(md[u]<md[rt])rt=u;
}
void get_dis(int u,int fa)
{
    rem[++rem[0]]=dis[u];
    for(int i=head[u];i;i=e[i].next)
        if(e[i].to!=fa and !vis[e[i].to])
        {
            dis[e[i].to]=dis[u]+e[i].w;
            get_dis(e[i].to,u);
        }
}
void count(int u)
{
    int p=0;
    for(int i=head[u];i;i=e[i].next)
        if(!vis[e[i].to])
        {
            rem[0]=0;dis[e[i].to]=e[i].w;
            get_dis(e[i].to,u);
            for(int j=rem[0];j;j--)
                for(int k=1;k<=m;k++)
                    if(query[k]>=rem[j])
                        test[k]|=judge[query[k]-rem[j]];
            for(int j=rem[0];j;j--)
                q[++p]=rem[j],judge[rem[j]]=1;
        }
    for(int i=1;i<=p;i++)
        judge[q[i]]=0;
}
void solve(int u)
{
    vis[u]=judge[0]=1;
    count(u);
    for(int i=head[u];i;i=e[i].next)
        if(!vis[e[i].to])
        {
            sum=size[e[i].to];md[rt=0]=inf;
            get_rt(e[i].to,0);solve(rt);
        }
}
int main()
{
    freopen("点分治.in","r",stdin);
    freopen("点分治.out","w",stdout);
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        add(u,v,w);
        add(v,u,w);
    }
    for(int i=1;i<=m;i++)
        cin>>query[i];
    md[rt]=sum=n;
    get_rt(1,0);
    solve(rt);
    for(int i=1;i<=m;i++)
    {
        if(test[i])printf("AYE\n");
        else printf("NAY\n");
    }
    return 0;
}
