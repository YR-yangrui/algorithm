# prufer 数列学习笔记
今天学习了$prufer$数列(编码),可以解决无根树计数的问题(带标号的无根树)
主要参考了[这篇学习笔记](https://blog.csdn.net/morejarphone/article/details/50677172)和[Matrix67的证明](http://www.matrix67.com/blog/archives/682)。

---
### 正文
prufer数列是无根树的编码表示，对于任意一颗n个节点的带编号的无根树，有唯一一串长度为**n-2**的prufer编码。
#### 求法
对于一颗带标号的无根树，我们规定无根树中度数为1的节点是叶子节点，接着我们每次找出编号最小的叶子节点，写下与它相邻的节点的编号，然后删掉这个节点，如此反复知道这颗树只剩下两个节点为止。
例如：
对于如下的一颗节点数为6的树：

![Screenshot_2019-09-16 Graph Editor.png](https://i.loli.net/2019/09/16/rKh9sIbUQPNvy1X.png)

它的prufer数列为:`2 2 3 3`

#### 解码prufer数列
设点解V={1,2,3,...,n},每次取出prufer数列中最前面的元素u，在V中找到编号最小没有出现在prufer数列中的元素v，连接u,v，然后分别删除u,v，最后V中剩下的两个节点直接连边，最终即可得到无根树。

#### 代码实现
求prufer数列和解码prufer数列的时间复杂度均为O(nlogn)
```cpp

/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月16日 星期一 19时21分42秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int maxn=1e6+10;
int n,prufer[maxn],head[maxn],cnt,du[maxn];
struct edge{
    int from,to,next;
    edge(int c=0,int a=0,int b=0):from(c),to(a),next(b){}
}e[maxn<<1];
void add(int u,int v)
{
    e[++cnt]=edge(u,v,head[u]);
    head[u]=cnt;
}
int vis[maxn],used[maxn];
set<int>S;
void clear()
{
    memset(vis,0,sizeof vis);
    memset(used,0,sizeof used);
    memset(prufer,0,sizeof prufer);
    memset(head,0,sizeof head);
    S.clear();
    cnt=0;
}
void GetPrufer()
{
    /*
     * S表示叶子节点
     */
    clear();
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v),add(v,u);
        du[u]++,du[v]++;
    }
    for(int i=1;i<=n;i++)
        if(du[i]==1)
        {
            S.insert(i);
            vis[i]=1;
        }
    set<int>::iterator it;
    int id=0;
    while(id<=n-3)
    {
        int u=(*(it=S.begin()));
        S.erase(u);
        for(int i=head[u];i;i=e[i].next)
            if(!vis[e[i].to])
            {
                du[e[i].to]--;
                prufer[++id]=e[i].to;
                if(du[e[i].to]==1)
                {
                    S.insert(e[i].to);
                    vis[e[i].to]=1;
                }
            }
    }
    return;
}
void DecodePrufer()
{
    /*
     * S表示最小没有出现在prufer数列中的数
     */
    clear();
    cin>>n;
    for(int i=1;i<=n-2;i++)
    {
        cin>>prufer[i];
        vis[prufer[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            S.insert(i);
    set<int>::iterator it;
    for(int i=1;i<=n-2;i++)
    {
        int v=(*(it=S.begin())),u=prufer[i];
        add(u,v); add(v,u);
        S.erase(v);
        vis[u]--;
        if(!vis[u] and !used[u])
        {
            S.insert(u);
        }
    }
    it=S.begin();
    int u=*it,v=*(++it);
    add(u,v); add(v,u);
    return;
}

```
**为什么可行？(唯一对应?)**

我们可以注意到，如果一个节点A不是叶子节点，那么它至少有两条边，在如上算法过程中，每减少一个点与其相连的点的度数减一(有点类似拓扑排序),到最后整颗树只会剩下一条边,那么节点A的至少有一个节点被去掉过，那么A便会被加入到prufer数列中，反之，prufer数列中的数字不可能是这颗树（初始时）的叶子节点,我们递归考虑构造中删除一些节点后的树，我们每次都能从中选出一个叶子结点使这个过程进行下去，而解码过程中找出的最小没有出现在数列中的数一定与prufer数列中第一个数有边相连，经过出来后我们继续递归考虑后面的子树，由于没经过处理的节点数总比剩下的数列长度大2，因此我们总能时算法进行下去，这样任意一个prufer数列都唯一地对应了一颗无根树。

**prufer数列的性质**

* 我们可以发现，所有节点在prufer数列中出现的次数为其`度数-1`次
* 有多少个prufer数列就用多少个带编号的无根树。
* 若n个节点的度数依次为<math xmlns='http://www.w3.org/1998/Math/MathML'> <msub> <mrow> <mi> d </mi> </mrow> <mrow> <mn> 1 </mn> </mrow> </msub> <mo> , </mo> <msub> <mrow> <mi> d </mi> </mrow> <mrow> <mn> 2 </mn> </mrow> </msub> <mo> , </mo> <msub> <mrow> <mi> d </mi> </mrow> <mrow> <mn> 3 </mn> </mrow> </msub> <mo> &#x2026; <!-- horizontal ellipsis --> </mo> <msub> <mrow> <mi> d </mi> </mrow> <mrow> <mi> n </mi> </mrow> </msub> </math> ,那么无根树的个数为 $\dfrac {\left( n-2\right) !}{\prod ^{n}_{i=1}\left( d_{i}-1\right) !}$ 为可重集排列的方案数

#### Cayley公式
一个k阶完全图有$n^{n-2}$颗带标号的无根树
