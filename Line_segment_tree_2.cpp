/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年07月15日 星期一 19时23分41秒
*******************************/
#include<iostream>
#include<cstdio>
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
const int maxn=1e5+10;
long long mod,n,m,x,y,opt,z,sum[maxn<<2],lazy_m[maxn<<2],lazy_a[maxn<<2];
inline void update(int k) { sum[k]=(sum[k<<1]+sum[k<<1|1])%mod; }
void build(int k,int l,int r)
{
    lazy_m[k]=1;
    if(l==r)
    {
        cin>>sum[k];
        sum[k]%=mod;
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    update(k);
}
#define ls (k<<1)
#define rs (k<<1|1)
inline void pushdown(int k,int l,int r,int mid)
{
    sum[ls]=sum[ls]*lazy_m[k]%mod;
    sum[rs]=sum[rs]*lazy_m[k]%mod;
    sum[ls]=(sum[ls]+lazy_a[k]*(mid-l+1))%mod;
    sum[rs]=(sum[rs]+lazy_a[k]*(r-mid))%mod;
    lazy_m[ls]=lazy_m[ls]*lazy_m[k]%mod;
    lazy_m[rs]=lazy_m[rs]*lazy_m[k]%mod;
    lazy_a[ls]=(lazy_a[ls]*lazy_m[k])%mod;
    lazy_a[rs]=(lazy_a[rs]*lazy_m[k])%mod;
    lazy_a[ls]=(lazy_a[ls]+lazy_a[k])%mod;
    lazy_a[rs]=(lazy_a[rs]+lazy_a[k])%mod;
    lazy_a[k]=0;lazy_m[k]=1;
}
int ql,qr,qa,qm;
void add(int k,int l,int r)
{
    if(ql<=l and r<=qr)
    {
        lazy_a[k]=(lazy_a[k]+qa)%mod;
        sum[k]=(sum[k]+qa*(r-l+1))%mod;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(k,l,r,mid);
    if(ql<=mid) add(ls,l,mid);
    if(qr>mid) add(rs,mid+1,r);
    update(k);
}
void mul(int k,int l,int r)
{
    if(ql<=l and r<=qr)
    {
        lazy_m[k]=lazy_m[k]*qm%mod;
        lazy_a[k]=(lazy_a[k]*qm)%mod;
        sum[k]=sum[k]*qm%mod;
        return;
    }
    int mid=(l+r)>>1;
    pushdown(k,l,r,mid);
    if(ql<=mid) mul(ls,l,mid);
    if(qr> mid) mul(rs,mid+1,r);
    update(k);
}
long long ans;
void query(int k,int l,int r)
{
    if(ql<=l and r<=qr){ ans=(ans+sum[k])%mod; return;}
    int mid=(l+r)>>1;
    pushdown(k,l,r,mid);
    if(ql<=mid) query(ls,l,mid);
    if(qr> mid) query(rs,mid+1,r);
}
#undef ls
#undef rs
int main()
{
        //freopen("p3373.in","r",stdin);
        //freopen("p3373.out","w",stdout);
        cin>>n>>m>>mod;
        build(1,1,n);
        while(m--)
        {
            cin>>opt;
            if(opt==1)
            {
                cin>>ql>>qr>>qm;
                mul(1,1,n);
            }
            if(opt==2)
            {
                cin>>ql>>qr>>qa;
                add(1,1,n);
            }
            if(opt==3)
            {
                cin>>ql>>qr;
                ans=0,query(1,1,n);
                printf("%lld\n",ans);
            }
        }
}
