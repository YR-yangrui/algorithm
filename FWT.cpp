/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月28日 星期三 19时44分29秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
const int maxn=1<<18;
long long inv2,n,len=1,a[maxn],b[maxn],c[maxn];
void FWT(long long * a,long long n,long long on,int opt)//opt=0 or,opt=1 and opt=3 xor 
{
    static long long tmp;
    for(int len=2;len<=n;len<<=1)
        for(int i=0;i<n;i+=len)
            for(int j=i;j<i+len/2;j++)
            {
                if(opt==0)
                {
                    if(on) a[j+len/2]+=a[j];
                    else
                        a[j+len/2]-=a[j];
                }
                if(opt==1)
                {
                    if(on)
                        a[j]+=a[j+len/2];
                    else
                        a[j]-=a[j+len/2];
                }
                if(opt==2)
                {
                    if(on)
                        tmp=a[j], a[j]-=a[j+len/2], a[j+len/2]+=tmp;
                    else
                        tmp=a[j],a[j]=(a[j]+a[j+len/2])*inv2,a[j+len/2]=(a[j+len/2]-tmp)*inv2;
                }
                a[j]%=mod; a[j+len/2]%=mod;

            }
}
long long ksm(long long a,long long b)
{
    long long ans=1; a%=mod;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    freopen("FWT.in","r",stdin);
    freopen("FWT.out","w",stdout);
    inv2=ksm(2,mod-2);
    cin>>n; len<<=n;
    for(int i=0;i<len;i++)cin>>a[i];
    for(int i=0;i<len;i++)cin>>b[i];
    for(int i=0;i<3;i++)
    {
        FWT(a,len,1,i);
        FWT(b,len,1,i);
        for(int j=0;j<len;j++)
            c[j]=(a[j]*b[j])%mod;
        FWT(c,len,0,i);
        FWT(a,len,0,i);
        FWT(b,len,0,i);
        for(int j=0;j<len;j++)
            cout<<(c[j]%mod+mod)%mod<<' ';
        cout<<endl;
    }
    return 0;
}
