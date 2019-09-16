/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月11日 星期三 16时26分53秒
*******************************/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e4+10;
const int inf=0x7fffffff;
int head[maxn],cnt,n,size[maxn],ans[maxn],tot,res=inf;
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
struct edge{
    int to,next;
}e[maxn<<1];
void add(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void dfs(int now,int fa)
{
    int tmp=-inf;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,now);
            size[now]+=size[e[i].to];
            if(size[e[i].to]>tmp)tmp=size[e[i].to];
        }
    size[now]++;
    tmp=max(tmp,n-size[now]);
    if(res==tmp)ans[++tot]=now;
    if(res>tmp)
        res=tmp,ans[tot=1]=now;
}
int main()
{
    freopen("poj3107.in","r",stdin);
    freopen("poj3107.out","w",stdout);
    int u,v;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v);
        add(v,u);
    }
    dfs(1,0);
    sort(ans+1,ans+tot+1);
    for(int i=1;i<=tot;i++)
        printf("%d ",ans[i]);
    putchar('\n');
    return 0;
}
