/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月26日 星期六 16时45分07秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e7+10;
int T,p,phi[maxn],prime[maxn],tot;
bool vis[maxn];
void euler_sieve(int n=1e7+2)
{
        for(int i=2;i<=n;i++)
        {
                if(!vis[i]){prime[++tot]=i;phi[i]=i-1;}
                for(int j=1;j<=tot and prime[j]*i<=n;j++)
                {
                        vis[i*prime[j]]=1;
                        if(i%prime[j]==0){phi[i*prime[j]]=phi[i]*prime[j];break;}
                        else phi[i*prime[j]]=phi[i]*(prime[j]-1);
                }
        }
}
long long ksm(long long a,long long b,long long mod)
{
        long long ans=1;
        while(b)
        {
                if(b&1)ans=ans*a%mod;
                a=a*a%mod;
                b>>=1;
        }
        return ans;
}
int solve(int mod)
{
        if(mod==1)return 0;
        return ksm(2,solve(phi[mod])+phi[mod],mod);
}
int main()
{
        freopen("p4139.in","r",stdin);
        freopen("p4139.out","w",stdout);
        euler_sieve();
        cin>>T;
        while(T--)
        {
                cin>>p;
                                cout<<solve(p)<<endl;
        }
        return 0;
}
