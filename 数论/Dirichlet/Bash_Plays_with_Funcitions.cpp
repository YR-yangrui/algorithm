/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月23日 星期三 15时36分39秒
 *******************************/
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e6+11;
const int mod=1e9+7;
bool vis[maxn];
int Q,r,n=1e6+3,prime[maxn],tot,f[maxn][22];
struct IO{
        template<typename T>
        IO & operator>>(T&res)
        {
                char ch=getchar();
                T q=1;
                while(ch<'0' or ch>'9')
                {
                        if(ch=='-')q=-q;
                        ch=getchar();
                }
                res=(ch^48);
                while((ch=getchar())>='0' and ch<='9')
                        res=(res<<1)+(res<<3)+(ch^48);
                res*=q;
                return *this;
        }
}cin;
void add(int &x,const int y)
{
        x+=y;
        if(x>mod)x-=mod;
        return;
}
void euler_sieve()
{
        for(int i=2;i<=n;i++)
        {
                if(!vis[i])prime[++tot]=i;
                for(int j=1;j<=tot and prime[j]*i<=n;j++)
                {
                        vis[prime[j]*i]=1;
                        if(i%prime[j]==0)break;
                }
        }
        return;
}
void make(int n=1e6+3,int m=21)
{
        f[0][0]=1;
        for(int i=1;i<=m;i++)f[0][i]=2;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
                sum=0;
                for(int j=0;j<=m;j++)
                {
                        add(sum,f[i-1][j]);
                        add(f[i][j],sum);
                }
        }
}
int solve()
{
        int ans=1,m=sqrt(n+0.5);
        for(int i=1;i<=tot and prime[i]<=m;i++)
        {
                if(n%prime[i])continue;
                int t=0;
                while(!(n%prime[i]))n/=prime[i],++t;
                ans=1LL*ans*f[r][t]%mod;
        }
        if(n>1)ans=1LL*ans*f[r][1]%mod;
        return ans;
}
int main()
{
        //freopen("Bash_Plays_with_Funcitions.in","r",stdin);
        //freopen("Bash_Plays_with_Funcitions.out","w",stdout);
        euler_sieve();
        make();
        cin>>Q;
        while(Q--)
        {
                cin>>r>>n;
                printf("%d\n",solve());
        }
}
