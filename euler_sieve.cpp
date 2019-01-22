/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月22日 星期二 15时53分29秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
int n=1e6,prime[maxn],vis[maxn],tot,mn[maxn],q[maxn],phi[maxn];
void euler_sieve()
{
        for(int i=2;i<=n;i++)
        {
                if(!vis[i]) { prime[++tot]=i;mn[i]=i;q[i]=1;phi[i]=i-1; }
                for(int j=1;j<=tot and prime[j]*i<=n;j++)
                {
                        vis[prime[j]*i]=1;
                        mn[prime[j]*i]=prime[j];
                        q[prime[j]*i]=1;
                        if(i%prime[j]==0)
                        {
                                phi[i*prime[j]]=phi[i]*prime[j];
                                q[prime[j]*i]=q[i]+1;
                                break;
                        }
                        else phi[i*prime[j]]=phi[i]*(prime[j]-1);
                }
        }
}
int main()
{
}
