/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月10日 星期一 19时33分34秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,fa[maxn],y[maxn],c[maxn],x[maxn],co[maxn],root,f[maxn],top,w[maxn];
int head[maxn],cnt,t,k;
bool flag;
struct edge{
    int next,to;
}e[maxn];
void add(int u,int v)
{
    e[++cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
void dp(int now)
{
    for(int i=head[now];i;i=e[i].next)
        dp(e[i].to);
    top=t=0;
    for(int i=head[now];i;i=e[i].next)
    {
        co[++top]=c[e[i].to],w[top]=x[e[i].to];
        t+=w[top];
    }
    if(t<y[now])
    {
        x[now]=0;
        c[now]=2e5;
        if(now==root)
            c[root]=-1;
        return;
    }
    memset(f,127,sizeof f);
    f[0]=0;
    for(int i=1;i<=top;i++)
        for(int j=t-w[i];j>=0;j--)
                f[j+w[i]]=min(f[j+w[i]],f[j]+co[i]);
    if(top!=0)
    {
        k=f[y[now]];
        for(int i=y[now];i<=t;i++)
            k=min(k,f[i]);
        c[now]+=k;
    }
}
int main()
{
        freopen("第258周.in","r",stdin);
        freopen("第258周.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++){ cin>>fa[i]>>y[i]>>x[i]>>c[i];add(fa[i],i);}
        root=e[head[root]].to;
        dp(root);
        cout<<c[root]<<endl;
}
