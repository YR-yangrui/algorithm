/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月05日 星期四 20时05分40秒
*******************************/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
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
#define int long long 
map<int,int>mp;
int a,p,b,t,te,ans;
int ksm(int a,int b,int c)
{
    a%=c; int res=1;
    while(b)
    {
        if(b&1)res=1ll*res*a%c;
        a=1ll*a*a%c;
        b>>=1;
    }
    return res;
}
int gcd(int a,int b){ return (a==0?b:gcd(b%a,a));}
int BSGS(int a,int b,int p)
{
    mp.clear();
    int m=sqrt(p);b%=p;
    for(int i=1;i<=m;i++)
    {
        b=1ll*b*a%p;
        mp[b]=i;
    }
    int tmp=ksm(a,m,p);b=1;
    for(int i=1;i<=m;i++)
    {
        b=1ll*b*tmp%p;
        if(mp[b])return (i*m-mp[b]+p)%p;
    }
    return -1;
}
int EXBSGS(int a,int b,int p)
{
    if(b==1)return 0;
    if(!b and !a)return 1;
    if(!a)return -1;
    int g=gcd(a,p),k=0,na=1;
    if(!b)
    {
        while((g=gcd(a,p))!=1)
        {
            k++;p/=g;
            if(p==1)return k;
        }
        return -1;
    }
    while(g>1)
    {
        if(b%g!=0)return -1;
        k++;b/=g;na=1ll*na*(a/g)%p;
        if(na==b)return k;
        g=gcd(a,p);
    }
    int f=BSGS(a,1ll*b*ksm(na,p-2,p)%p,p);
    if(f==-1)return -1;
    return f+k;
}
signed main()
{
    freopen("BSGS.in","r",stdin);
    freopen("BSGS.out","w",stdout);
    while(true)
    {
        cin>>a>>p>>b;
        if(a==0 and p==0 and b==0)break;
        int ans=EXBSGS(a,b,p);
        if(ans!=-1)printf("%lld\n",ans);
        else printf("No Solution\n");
    }
    return 0;
}
