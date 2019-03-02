/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月28日 星期四 14时21分07秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
using std::cout; using std::endl;
const int N=61000;
const int M=248000;
struct edge{
        int to,next;
}e[M];
int f[N],depth[N],size[N],son[N],top[N],seg[M],rev[M],head[N],Max[N],sum[M],num[N],cnt;
int n;
inline void add(int u,int v)
{
        e[++cnt].to=v;
        e[cnt].next=head[u];
        head[u]=cnt;
}
//f 父亲 ，depth深度 size子树节点数 son重边 top所在重链顶部节点 seg当前节点在线段树的位置 rev线段树节点对应的树节点
int Sum,Maxx;
void query(int k,int l,int r,int x,int y)
{
        if(l>y or r<x)return;
        if(l>=x and r<=y)
        {
                Sum+=sum[k];
                Maxx=std::max(Maxx,Max[k]);
                return;
        }
        int mid=(l+r)>>1;
        if(mid>=x)query(k<<1,l,mid,x,y);
        if(mid<y)query(k<<1|1,mid+1,r,x,y);
}
void change(int k,int l,int r,int v,int pos)
{
        if(pos>r or pos<l)return;
        if(l==r and l==pos)
        {
                sum[k]=v;
                Max[k]=v;
                return;
        }
        int mid=(l+r)>>1;
        if(mid>=pos)change(k<<1,l,mid,v,pos);
        if(mid<pos)change(k<<1|1,mid+1,r,v,pos);
        sum[k]=sum[k<<1]+sum[k<<1|1];
        Max[k]=std::max(Max[k<<1],Max[k<<1|1]);
}
#define v e[i].to
void dfs1(int u)
{
        size[u]=1;
        depth[u]=depth[f[u]]+1;
        for(int i=head[u];i;i=e[i].next)
                if(e[i].to!=f[u])
                {
                        f[e[i].to]=u;
                        dfs1(e[i].to);
                        size[u]+=size[e[i].to];
                        if(size[e[i].to]>size[son[u]])son[u]=v;
                }
        return;
}
void dfs2(int u,int tp)
{
        top[u]=tp,seg[u]=++seg[0], rev[seg[0]] = u;
        if(son[u]) dfs2(son[u], tp);
        for(int i=head[u];i;i=e[i].next)
        {
                if(v==f[u] or v==son[u])continue;
                dfs2(v,v);
        }
}
#undef v
void build(int k,int l,int r)
{
        int mid=(l+r)>>1;
        if(l==r) { Max[k]=sum[k]=num[rev[l]]; return; }
        build(k<<1,l,mid);
        build(k<<1|1,mid+1,r);
        sum[k]=sum[k<<1]+sum[k<<1|1];
        Max[k]=std::max(Max[k<<1],Max[k<<1|1]);
}
inline void ask(int x,int y)
{
        int fx=top[x],fy=top[y];
        while(fx!=fy)
        {
                if(depth[fx]<depth[fy])std::swap(x,y),std::swap(fx,fy);
                query(1,1,seg[0],seg[fx],seg[x]);
                x=f[fx],fx=top[x];
        }
        if(depth[x]>depth[y])std::swap(x,y);
        query(1,1,seg[0],seg[x],seg[y]);
}
int main()
{
        freopen("树链剖分.in","r",stdin);
        freopen("树链剖分.out","w",stdout);
        cin>>n;
        int a,b,m;
        char c1,c2;
        for(int i=1;i<=n-1;i++)
        {
                cin>>a>>m;
                add(a,m);add(m,a);
        }
        for(int i=1;i<=n;i++)
                cin>>num[i];
        dfs1(1);
        seg[0]=seg[1]=top[1]=rev[1]=1;
        dfs2(1,1);
        build(1,1,seg[0]);
        cin>>m;
        while(m--)
        {
                c1=getchar();c2=getchar();
                cin>>a>>b;
                if(c1=='C')
                        change(1,1,seg[0],b,seg[a]);
                else
                {
                        Sum=0;
                        Maxx=-1e6;
                        ask(a,b);
                        if(c2=='M')
                                printf("%d\n",Maxx);
                        else printf("%d\n",Sum);
                }
        }
}
