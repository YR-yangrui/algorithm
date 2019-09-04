# 换根dp

树形$dp$的一个内容，对于有根树的$dp$值可以$O(n)$求的题目，而要求考虑无根树的方法。

方法比较简单，下面来看一道例题[POJ3585](http://poj.org/problem?id=3585)

## 题目描述
有一个树形的水系，由 N-1 条河道和 N 个交叉点组成。

我们可以把交叉点看作树中的节点，编号为 1~N，河道则看作树中的无向边。

每条河道都有一个容量，连接 x 与 y 的河道的容量记为 c(x,y)。

河道中单位时间流过的水量不能超过河道的容量。

有一个节点是整个水系的发源地，可以源源不断地流出水，我们称之为源点。

除了源点之外，树中所有度数为 1 的节点都是入海口，可以吸收无限多的水，我们称之为汇点。

也就是说，水系中的水从源点出发，沿着每条河道，最终流向各个汇点。

在整个水系稳定时，每条河道中的水都以单位时间固定的水量流向固定的方向。

除源点和汇点之外，其余各点不贮存水，也就是流入该点的河道水量之和等于从该点流出的河道水量之和。

整个水系的流量就定义为源点单位时间发出的水量。

在流量不超过河道容量的前提下，求哪个点作为源点时，整个水系的流量最大，输出这个最大值。

## 题解
考虑若为有根树(默认$root=1$)，设$g[u]$表示以$u$为根的子树中的最大值,考虑儿子节点$v$,设$d[u]$表示$u$的度数。
1. 若$d[v]=1$,则$g[u]+=w_{u,v}$
2. 若$d[v]>1$,则$g[u]+=min(w_{u,v},g[v])$

如此枚举每个点作为根节点，时间复杂度为$O(n^2)$

设$f[u]$表示以$u$为根节点的答案的最大值设$v$为与$u$相连的边
考虑换根($u->v$)后有哪些不变值，显然$g[v]$没有发生改变
考虑从已知向未知转移：
1. $f[u]=g[u] ~~ u=1$
2. 若$d[u]=1$,那么$f[v]=g[v]+w_{u,v}$
3. 若$d[u]!=1$,那么$f[v]$应该为$g[v]$加上从$v$的上面那一坨(从$u$过来的子树部分)，那么有
$f[v]=g[v]+min(f[u]-min(g[v],w_{u,v}),w_{u,v})$

时间复杂度为$O(n)$

代码:
```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月30日 星期五 20时29分21秒
*******************************/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;
int T,n,ans,d[maxn],f[maxn],g[maxn],head[maxn],cnt;
struct edge{
    int to,next,w;
}e[maxn<<1];
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
void add(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].w=w;
    head[u]=cnt;
}
void clear()
{
    ans=cnt=0;
    memset(d,0,sizeof d);
    memset(head,0,sizeof head);
}
void dfs(int now,int fa)
{
    g[now]=0;
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            dfs(e[i].to,now);
            if(d[e[i].to]==1)
                g[now]+=e[i].w;
            else 
                g[now]+=min(g[e[i].to],e[i].w);
        }
}
void dp(int now,int fa)
{
    for(int i=head[now];i;i=e[i].next)
        if(e[i].to!=fa)
        {
            if(d[now]==1)
                f[e[i].to]=g[e[i].to]+e[i].w;
            else
                f[e[i].to]=g[e[i].to]+min(f[now]-min(e[i].w,g[e[i].to]),e[i].w);
            dp(e[i].to,now);
        }
    return;
}
int main()
{
    //freopen("p3585.in","r",stdin);
    //freopen("p3585.out","w",stdout);
    cin>>T;
    int u,v,w;
    while(T--)
    {
        cin>>n;
        clear();
        for(int i=1;i<n;i++)
        {
            cin>>u>>v>>w;
            add(u,v,w);add(v,u,w);
            d[u]++;d[v]++;
        }
        dfs(1,0);
        f[1]=g[1];
        dp(1,0);
        ans=0;
        for(int i=1;i<=n;i++)
            ans=max(ans,f[i]);
        printf("%d\n",ans);
    }
    return 0;
}

```
