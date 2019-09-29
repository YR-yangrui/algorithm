/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月22日 星期二 15时53分29秒
 *******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n=1e6,prime[maxn],vis[maxn],tot,mn[maxn],e[maxn],phi[maxn],d[maxn],mu[maxn];
//e最小质因子的个数
void euler_sieve()
{
    mu[1]=1;phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]) { prime[++tot]=i;mn[i]=i;e[i]=1;phi[i]=i-1;d[i]=2;mu[i]=-1; }
        for(int j=1;j<=tot and prime[j]*i<=n;j++)
        {
            vis[prime[j]*i]=1;
            mn[prime[j]*i]=prime[j];
            e[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                e[prime[j]*i]=e[i]+1;
                d[i*prime[j]]=d[i]/(e[i]+1)*(e[i]+2);
                mu[i*prime[j]]=0;
                break;
            }
            else phi[i*prime[j]]=phi[i]*(prime[j]-1);
            mu[i*prime[j]]=-mu[i];
            d[i*prime[j]]<<=1;
        }
    }
}
int main()
{
}
