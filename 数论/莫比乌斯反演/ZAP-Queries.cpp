/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月28日 星期一 16时39分58秒
*******************************/
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=50010;
long long tot,prime[maxn],mu[maxn],sum[maxn],n,a,b,k;
bool vis[maxn];
inline void get_mu(int n)
{
        mu[1]=1;
        for(int i=2;i<=n;i++)
        {
                if(!vis[i]){prime[++tot]=i;mu[i]=-1;}
                for(int j=1;j<=tot and prime[j]*i<=n;j++)
                {
                        vis[prime[j]*i]=1;
                        if(i%prime[j]==0)break;
                        mu[i*prime[j]]=-mu[i];
                }
        }
        return;
}
long long solve(long long a,long long b)
{
        long long ans=0,rep=min(a,b);
        for(int l=1,r;l<=rep;l=r+1)
        {
                r=min(a/(a/l),b/(b/l));
                ans+=(a/(l*k))*(b/(l*k))*(sum[r]-sum[l-1]);
        }
        return ans;
}
int main()
{
        freopen("ZAP-Queries.in","r",stdin);
        freopen("ZAP-Queries.out","w",stdout);
        scanf("%lld",&n);
        get_mu(50000);
        for(int i=1;i<=50000;i++)sum[i]=sum[i-1]+mu[i];
        while(n--)
        {
                //cin>>a>>b>>k;
                scanf("%lld%lld%lld",&a,&b,&k);
                printf("%lld\n",solve(a,b));
        }
        return 0;
}
