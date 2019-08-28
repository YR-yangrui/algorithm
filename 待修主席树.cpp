/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月22日 星期四 15时38分04秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=100005;
struct Node{
    int v,ls,rs;
}tree[maxn*400];
struct operation{
    bool b;
    int l,r,k,pos,t;
}q[maxn];
int n,m,a[maxn],o[maxn<<1],rt[maxn],len,tot,temp[2][20],cnt[2];
char opt;
void modify(int & now,int l,int r,int pos,int val)
{
    if(!now)now=++tot;
    tree[now].v+=val;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)modify(tree[now].ls,l,mid,pos,val);
    else modify(tree[now].rs,mid+1,r,pos,val);
}
void prepare_modify(int x,int val)
{
    int k=lower_bound(o+1,o+len+1,a[x])-o;
    for(int i=x;i<=n;i+=i&-i)
        modify(rt[i],1,len,k,val);
}
int query(int k,int l,int r)
{
    if(l==r)return l;
    int mid=(l+r)>>1,sum=0;
    for(int i=1;i<=cnt[1];i++) sum+=tree[tree[temp[1][i]].ls].v;
    for(int i=1;i<=cnt[0];i++) sum-=tree[tree[temp[0][i]].ls].v;
    if(k<=sum)
    {
        for(int i=1;i<=cnt[1];i++)temp[1][i]=tree[temp[1][i]].ls;
        for(int i=1;i<=cnt[0];i++)temp[0][i]=tree[temp[0][i]].ls;
        return query(k,l,mid);
    }
    else
    {
        for(int i=1;i<=cnt[1];i++)temp[1][i]=tree[temp[1][i]].rs;
        for(int i=1;i<=cnt[0];i++)temp[0][i]=tree[temp[0][i]].rs;
        return query(k-sum,mid+1,r);
    }
}
int prepare_query(int k,int l,int r)
{
    memset(temp,0,sizeof temp);
    cnt[0]=cnt[1]=0;
    for(int i=r;i;i-=i&-i)temp[1][++cnt[1]]=rt[i];
    for(int i=l-1;i;i-=i&-i)temp[0][++cnt[0]]=rt[i];
    return query(k,1,len);
}
int main()
{
    freopen("待修主席树.in","r",stdin);
    freopen("待修主席树.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],o[++len]=a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>opt;
        q[i].b=(opt=='Q');
        if(q[i].b) cin>>q[i].l>>q[i].r>>q[i].k;
        else cin>>q[i].pos>>q[i].t,o[++len]=q[i].t;
    }
    sort(o+1,o+len+1);
    len=unique(o+1,o+len+1)-o-1;
    for(int i=1;i<=n;i++)
        prepare_modify(i,1);
    for(int i=1;i<=m;i++)
    {
        if(q[i].b)printf("%d\n",o[prepare_query(q[i].k,q[i].l,q[i].r)]);
        else
        {
            prepare_modify(q[i].pos,-1);
            a[q[i].pos]=q[i].t;
            prepare_modify(q[i].pos,1);
        }
    }
    return 0;
}
