/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年11月06日 星期三 19时24分57秒
*******************************/
#include<cstdio>
#include<algorithm>

using namespace std;

struct IO{
    template<typename T>
    IO & operator>>(T&res)
    {
        T q=1;char ch;
        while((ch=getchar())<'0' or ch>'9')if(ch=='-')q=-q;
        res=(ch^48);
        while((ch=getchar())>='0' and ch<='9') res=(res<<1)+(res<<3)+(ch^48);
        res*=q;
        return *this;
    }
}cin;

const int primes[]={2,3,5,7,11,13,17,19,23};
const int SIZE=9;

long long mul(long long a,long long b,long long mod)
{
    long long ans=0;
    while(b)
    {
        if(b&1)
            ans=(ans+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return ans;
}

long long ksm(long long a,long long b,long long mod)
{
    long long res=1;
    while(b)
    {
        if(b&1)
            res=mul(res,a,mod);
        a=mul(a,a,mod);
        b>>=1;
    }
    return res;
}

bool Miller_Rabin(long long x)
{
    if(!(x&1))return false;
    long long tmp=x-1,s=0,k,nxt;
    while(!(tmp&1))s++,tmp>>=1;
    for(int i=0;i<SIZE;i++)
    {
        if(x==primes[i]) return true;
        k=ksm(primes[i],tmp,x);
        for(int j=1;j<=s;j++)
        {
            nxt=mul(k,k,x);
            if(nxt==1 && k!=1 && k!=x-1)
                return false;
            k=nxt;
        }
        if(k!=1) return false;
    }
    return true;
}

int main()
{
    freopen("MillerRabin.in","r",stdin);
    freopen("MillerRabin.out","w",stdout);
}
