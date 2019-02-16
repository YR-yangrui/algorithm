/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月16日 星期六 14时05分09秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
const int maxn=1e5+10;
const int N=2e5+10;
int n,k,tree[2*maxn],z,y,p,ans[maxn*2];
struct edge{
        int x,y,z,id,res;
        bool operator<(const edge & k)const
        {
                return y<k.y;
        }
        bool operator==(const edge & k)const
        {
                return (x==k.x) and (y==k.y) and (z==k.z);
        }
}f[maxn],t[maxn];
bool cmp(const edge & a,const edge & b) 
{ 
        if(a.x==b.x)
        {
                if(a.y==b.y)return a.z<b.z;
                else return a.y<b.y;
        }
        return a.x<b.x;
}
void add(int x,int v) { while(x<=N) { tree[x]+=v; x+=x&-x; } return; }
int sum(int x) { int res=0; while(x) { res+=tree[x]; x-=x&-x; } return res; }
void msort(int l,int r)
{
        if(l>=r)return;
        int mid=(l+r)>>1;
        msort(l,mid);
        msort(mid+1,r);
        z=l,y=mid+1;p=l;
        while(z<=mid and y<=r)
        {
                if(f[z].y<=f[y].y) t[p++]=f[z],add(f[z++].z,1);
                else
                {
                        f[y].res+=sum(f[y].z);
                        t[p++]=f[y++];
                }
        }
        while(y<=r)
        {
                f[y].res+=sum(f[y].z);
                t[p++]=f[y++];
        }
        for(int i=l;i<z;i++)add(f[i].z,-1);
        while(z<=mid) t[p++]=f[z++];
        for(int i=l;i<=r;i++)
                f[i]=t[i];
        return;
}
int main()
{
        freopen("三维偏序.in","r",stdin);
        freopen("三维偏序.out","w",stdout);
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d%d%d",&f[i].x,&f[i].y,&f[i].z),f[i].id=i;
        sort(f+1,f+n+1,cmp); msort(1,n);
        for(int i=n;i>=1;i--)
        {
                if(f[i]==f[i+1]) f[i].res=f[i+1].res;
                ans[f[i].res]++;
        }
        for(int i=0;i<n;i++) printf("%d\n",ans[i]);
        return 0;
}
