/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月26日 星期六 15时05分55秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#define RI register int
using namespace std;
const long long maxn=2e5+10;
const long long mod=998244353,g=3,G=3;
long long n,a[maxn],b[maxn],c[maxn],rev[maxn];
inline void get_rev(long long bit)
{
        for(int i=0;i<=(1<<bit);i++)
                rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}
inline long long ksm(long long a,long long b)
{
        long long ans=1;
        while(b)
        {
                if(b&1)ans=1LL*ans*a%mod;
                a=1LL*a*a%mod;
                b>>=1;
        }
        return ans;
}
inline void NTT(long long *a,long long len,long long on)
{
        for(int i=0;i<len;i++)
                if(i<rev[i])
                        swap(a[i],a[rev[i]]);
        for(int i=2;i<=len;i<<=1)
        {
                long long wn=ksm(g,(mod-1)/i);
                if(on==-1)wn=ksm(wn,mod-2);
                for(int j=0;j<len;j+=i)
                {
                        long long w=1;
                        for(long long k=j;k<j+i/2;k++)
                        {
                                long long u=(a[k]+mod)%mod,v=1LL*a[k+i/2]*w%mod;
                                a[k]=(u+v+mod)%mod;a[k+i/2]=(u-v+mod)%mod;
                                w=1LL*w*wn%mod;
                        }
                }
        }
        if(on==-1)
        {
                long long inv=ksm(len,mod-2);
                for(int i=0;i<len;i++)
                        a[i]=1LL*a[i]*inv%mod;
        }
}
void work(long long d,long long *a,long long *b)
{
        if(d==1){b[0]=ksm(a[0],mod-2);return;}
        work((d+1)>>1,a,b);
        long long len=0,s=1;
        while(s<(d<<1))len++,s<<=1;
        get_rev(len);
        for(int i=0;i<d;i++)c[i]=a[i];
        for(int i=d;i<s;i++)c[i]=0;
        NTT(c,s,1);  NTT(b,s,1);
        for(int i=0;i<s;i++) b[i]=1LL*(2-1LL*c[i]*b[i]%mod+mod)%mod*b[i]%mod;
        NTT(b,s,-1);
        for(int i=d;i<s;i++) b[i]=0;
}
int main()
{
        freopen("多项式求逆元.in","r",stdin);
        freopen("多项式求逆元.out","w",stdout);
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        work(n,a,b);
        for(int i=0;i<n;i++) cout<<b[i]<<' ';
        cout<<endl;
        return 0;
}
