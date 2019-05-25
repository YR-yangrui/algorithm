/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年03月03日 星期日 16时54分43秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
struct edge{
        int to,next;
}e[maxn*2];
int head[maxn*2],sum[maxn*4],lazy[maxn*4],son[maxn],f[maxn],depth[maxn],size[maxn],top[maxn],rev[maxn*4],seg[maxn*4],cnt,num[maxn],mod,ans;
void add(int u,int v)
{
        e[++cnt].next=head[u];
        e[cnt].to=v;
        head[u]=cnt;
}
#define v e[i].to
void dfs1(int u)
{
        size[u]=1;
        depth[u]=depth[f[u]]+1;
        for(int i=head[u];i;i=e[i].next)
                if(v!=f[u])
                {
                        f[v]=u;
                        dfs1(v);
                        size[u]+=size[v];
                        if(size[son[u]]<size[v])son[u]=v;
                }
}
void dfs2(int u,int tp)
{
        top[u]=tp;
        seg[u]=++seg[0];
        rev[seg[0]]=u;
        if(son[u]) dfs2(son[u],tp);
        for(int i=head[u];i;i=e[i].next)
                if(v!=f[u] and v!=son[u])
                        dfs2(v,v);
}
#undef v
void add(int k,int l,int r,int v)
{
        sum[k]+=(r-l+1)*v%mod;
        sum[k]%=mod;
        lazy[k]+=v;
}

void pushdown(int k,int l,int r,int mid)
{
        if(!lazy[k])return;
        add(k<<1,l,mid,lazy[k]);
        add(k<<1|1,mid+1,r,lazy[k]);
        lazy[k]=0;
}

void query(int k,int l,int r,int x,int y,int & ans)
{
        if(l>y or r<x)return;
        if(l>=x and r<=y) { ans+=sum[k]; ans%=mod; return; }
        int mid=(l+r)>>1;
        pushdown(k,l,r,mid);
        if(mid>=x)query(k<<1,l,mid,x,y,ans);
        if(mid<y)query(k<<1|1,mid+1,r,x,y,ans);
}

void modify(int k,int l,int r,int x,int y,int v)
{
        if(l>y or r<x)return;
        if(l>=x and r<=y)return add(k,l,r,v);
        int mid=(l+r)>>1;
        pushdown(k,l,r,mid);
        if(mid>=x)modify(k<<1,l,mid,x,y,v);
        if(mid<y)modify(k<<1|1,mid+1,r,x,y,v);
        sum[k]=sum[k<<1]+sum[k<<1|1];
        sum[k]%=mod;
}

void build(int k,int l,int r)
{
        if(l==r) { sum[k]=num[rev[l]]; return; }
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        sum[k]=sum[k<<1]+sum[k<<1|1];
}

void ask(int x,int y)
{
        while(top[x]!=top[y])
        {
                if(depth[top[x]]<depth[top[y]])swap(x,y);
                query(1,1,seg[0],seg[top[x]],seg[x],ans);
                x=f[top[x]];
        }
        if(depth[x]>depth[y])swap(x,y);
        query(1,1,seg[0],seg[x],seg[y],ans);
}

void change(int x,int y,int v)
{
        while(top[x]!=top[y])
        {
                if(depth[top[x]]<depth[top[y]])swap(x,y);
                modify(1,1,seg[0],seg[top[x]],seg[x],v);
                x=f[top[x]];
        }
        if(depth[x]>depth[y])swap(x,y);
        modify(1,1,seg[0],seg[x],seg[y],v);
}

int main()
{
        freopen("树链剖分.in","r",stdin);
        freopen("树链剖分.out","w",stdout);
        ios::sync_with_stdio(false);
        int n,m,root,u,v,opt,w;
        cin>>n>>m>>root>>mod;
        for(int i=1;i<=n;i++) cin>>num[i];
        for(int i=1;i<=n-1;i++)
        {
                cin>>u>>v;
                add(u,v); add(v,u);
        }
        dfs1(root); dfs2(root,root);
        build(1,1,seg[0]);
        while(m--)
        {
                cin>>opt>>u;
                if(opt!=4)cin>>v;
                if(opt==1)
                {
                        cin>>w;
                        change(u,v,w);
                }
                if(opt==2)
                {
                        ans=0;
                        ask(u,v);
                        cout<<ans<<endl;
                }
                if(opt==3)
                {
                        modify(1,1,seg[0],seg[u],seg[u]+size[u]-1,v);
                }
                if(opt==4)
                {
                        ans=0;
                        query(1,1,seg[0],seg[u],seg[u]+size[u]-1,ans);
                        cout<<ans<<endl;
                }
        }
}
