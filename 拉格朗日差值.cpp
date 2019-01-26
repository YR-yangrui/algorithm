/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月24日 星期四 20时12分58秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const long long mod=998244353;
int read()
{
       char ch=getchar();
       int q=1,res;
       while(ch<'0' or ch>'9'){if(ch=='-')q=-q; ch=getchar();}
       res=(ch^48);
       while((ch=getchar())>='0' and ch<='9')res=(res<<1)+(res<<3)+(ch^48);
       return res*=q;
}
long long n,k,u,d,x[2019],y[2019],ans,h,g;
void ex_gcd(long long a,long long b,long long & x,long long & y)
{
        if(b==0){x=1,y=0;return ;}
        ex_gcd(b,a%b,x,y);
        long long t=x;
        x=y;y=t-a/b*y;
        return;
}
int main()
{
        freopen("拉格朗日差值.in","r",stdin);
        freopen("拉格朗日差值.out","w",stdout);
        n=read(),k=read();
        for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
        for(int i=1;i<=n;i++)
        {
                u=y[i],d=1;
                for(int j=1;j<=n;j++)
                {
                        if(j==i)continue;
                        u=u*(k+mod-x[j])%mod;
                        d=d*(x[i]+mod-x[j])%mod;
                }
                ex_gcd(d,mod,h,g);h=(h%mod+mod)%mod;
                ans=(ans+u*h%mod)%mod;
        }
        cout<<ans<<endl;
        return 0;
}
