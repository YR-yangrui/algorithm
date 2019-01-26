/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月24日 星期四 15时50分16秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=60010;
int n,a,b,c,d,k;
bool vis[maxn];
int prime[maxn],tot,mu[maxn],sum[maxn];
inline void read(int &x)
{
    x=0;
    static int p;p=1;
    static char c;c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
    x*=p;   
}
long long solve(int a,int b)
{
        static int max_rep;
        static long long ans;
        ans=0;max_rep=min(a,b);
        for(int l=1,r;l<=max_rep;l=r+1)
        {
                r=min(a/(a/l),b/(b/l));
                ans+=(1LL*a/(1LL*l*k))*(1LL*b/(1LL*l*k))*(sum[r]-sum[l-1]);
        }
        return ans;
}
int main()
{
        freopen("HAOI2011_Problem_b.in","r",stdin);
        freopen("HAOI2011_Problem_b.out","w",stdout);
        n=50000;
        mu[1]=1;
        for(int i=2;i<=n;i++)
        {
                if(!vis[i]){prime[++tot]=i;mu[i]=-1;}
                for(int j=1;j<=tot and prime[j]*i<=n;j++)
                {
                        vis[i*prime[j]]=1;
                        if(i%prime[j]==0) break;
                        mu[i*prime[j]]=-mu[i];
                }
        }
        for(int i=1;i<=n;i++) sum[i]=sum[i-1]+mu[i];
        read(n);
        while(n--)
        {
                //cin>>a>>b>>c>>d>>k;
                read(a),read(b),read(c),read(d),read(k);
                printf("%lld\n",(solve(b,d)-solve(b,c-1)-solve(a-1,d)+solve(a-1,c-1)));
        }
        return 0;
}
