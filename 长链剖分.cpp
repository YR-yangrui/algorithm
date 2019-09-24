/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019/08/12 15:36:12
 *******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e6+10;
struct edge{
    int to,next;
}e[maxn<<1];
int tmp[maxn],*id=tmp,*dp[maxn],head[maxn],n,ans[maxn],f[maxn],len[maxn],son[maxn],cnt;
void add(int u,int v)
{
    e[++cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
void dfs(int now,int fa)
{
    f[now]=fa;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,now);
            if(len[e[i].to]>len[son[now]])
                son[now]=e[i].to;
        }
    len[now]=len[son[now]]+1;
}
void dfs(int now)
{
    dp[now][0]=1;
    if(son[now])dp[son[now]]=dp[now]+1,dfs(son[now]),ans[now]=ans[son[now]]+1;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=f[now] and e[i].to!=son[now])
        {
            dp[e[i].to]=id;id+=len[e[i].to];
            dfs(e[i].to);
            for(int j=1;j<=len[e[i].to];j++)
            {
                dp[now][j]+=dp[e[i].to][j-1];
                if((j<ans[now] and dp[now][j]>=dp[now][ans[now]]) or (j>=ans[now] and dp[now][j]>dp[now][ans[now]]))
                    ans[now]=j;
            }
        }
    if(dp[now][ans[now]]==1)
        ans[now]=0;
}
int main()
{
    ////freopen("CF1009.in","r",stdin);
    ////freopen("CF1009.out","w",stdout);
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        //cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    dp[1]=id;id+=len[1];
    dfs(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    //cout<<ans[i]<<endl;
    return 0;
}
