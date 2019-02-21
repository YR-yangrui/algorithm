/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月21日 星期四 17时37分20秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
const int maxn=1e5+10;
int n,L,lazy[maxn*4];
void build(int k,int l,int r)
{

        lazy[k]=0;
        if(l==r-1)return;
        int mid=(l+r)>>1;
        build(k<<1,l,mid);
        build(k<<1|1,mid,r);
        return;
}
void push_down(int k)
{
        if(lazy[k]==0)return;
        lazy[k<<1]=lazy[k<<1|1]=lazy[k];
        lazy[k]=0;
}
void modify(int k,int l,int r,int x,int y,int v)
{
        if(l>y or r<x or l>=r)return;
        if(l>=x and r<=y){lazy[k]=v;return;}
        int mid=(l+r)>>1;
        push_down(k);
        if(x<mid)modify(k<<1,l,mid,x,y,v);
        if(mid<y)modify(k<<1|1,mid,r,x,y,v);
}
set<int>ans;
void query(int k,int l,int r,int x,int y)
{
        if(l>y or r<x)return;
        if(lazy[k])
        {
                ans.insert(lazy[k]);
                return;
        }
        if(l==r-1)return;
        //push_down(k);
        int mid=(l+r)>>1;
        query(k<<1,l,mid,x,y);
        query(k<<1|1,mid,r,x,y);
}
int a[maxn],b[maxn],cnt;
map<int,int>mp;
int main()
{
        //freopen("第二十一周.in","r",stdin);
        //freopen("第二十一周.out","w",stdout);
        ios::sync_with_stdio(false);
        cin>>n>>L;
        for(int i=1;i<=n;i++)
        {
                cin>>a[i]>>b[i];
                mp[a[i]]++;mp[b[i]]++;
        }
        map<int,int>::iterator it=mp.begin();
        while(it!=mp.end())
                it->second=++cnt,it++;
        int m=mp.size();
        for(int i=1;i<=n;i++)
        {
                a[i]=mp[a[i]]; b[i]=mp[b[i]];
                modify(1,1,m,a[i],b[i],i);
        }
        query(1,1,m,1,m);
        cout<<ans.size()<<endl;
}
