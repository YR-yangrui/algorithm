/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月28日 星期五 20时26分16秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e5+10;
int n,m,l,r,k,cnt,root[maxn],ref[maxn];
struct edge{
    int val,id,s;
}a[maxn];
bool cmp(const edge & x,const edge & y) { return x.val<y.val; }
bool _cmp(const edge & x,const edge & y) { return x.id<y.id; }
struct Tree{
    int l,r,sum;
    Tree():l(0),r(0),sum(0){}
}tree[maxn*32];
int build(int l,int r)
{
    int now=++cnt,mid=(l+r)>>1;
    if(l<r)
    {
        tree[now].l=build(l,mid);
        tree[now].r=build(mid+1,r);
    }
    return now;
}
int insert(int l,int r,int last,int x)
{
    int now=++cnt;
    tree[now].sum=tree[last].sum+1;
    tree[now].l=tree[last].l,tree[now].r=tree[last].r;
    if(l==r)return now;
    int mid=(l+r)>>1;
    if(x<=mid)tree[now].l=insert(l,mid,tree[last].l,x);
    else tree[now].r=insert(mid+1,r,tree[last].r,x);
    return now;
}

int query(int l,int r,int x,int y,int k)
{
    if(l==r)return l;
    int sum=tree[tree[y].l].sum-tree[tree[x].l].sum,mid=(l+r)>>1;
    if(k<=sum) return query(l,mid,tree[x].l,tree[y].l,k);
    else
        return query(mid+1,r,tree[x].r,tree[y].r,k-sum);
}
int main()
{
        freopen("主席树.in","r",stdin);
        freopen("主席树.out","w",stdout);
        ios::sync_with_stdio(false);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i].val,a[i].id=i;
        sort(a+1,a+n+1,cmp);
        int p=1; a[1].s=1;ref[1]=a[1].val;
        for(int i=2;i<=n;i++)
        {
            if(a[i].val!=a[i-1].val)p++;
            a[i].s=p; ref[p]=a[i].val;
        }
        sort(a+1,a+n+1,_cmp);
        root[0]=build(1,p);
        for(int i=1;i<=n;i++)
            root[i]=insert(1,p,root[i-1],a[i].s);
        while(m--)
        {
            cin>>l>>r>>k;
            cout<<ref[query(1,p,root[l-1],root[r],k)]<<endl;
        }
        return 0;
}
