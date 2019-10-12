
## K-Dimension-Tree (KDT)
[宣传一波个人博客](https://www.galaxyyr.site)

顾名思义，kd树其实就是多维二叉树（空间二叉树的一种特殊情况）， 里面储存着k维的点的信息，是对k维空间进行划分的一种数据结构。
在竞赛中一般用来解决二维空间和三维空间的信息检索

KD树可以解决以下几个任务:

1. KNN问题。即查询离某个点第k邻近的点

2. 查询最近最远（就是 KNN问题）

3. 查询矩阵和

4. 图像处理（与竞赛无关）

对于KD树,我们可以把它分为两部分

* **KD树的构建**

* **对于KNN问题的最邻近查找算法**

## KD树的构建

KD树是一种平衡二叉树，它的各种操作都与我们学过的数据结构方法相似，对于我们一点也不陌生，很好理解。（目的是使我们能完成KNN问题）

KD树的构建有两种方法：一种利用方差，一种根据维度来划分。我们在竞赛中采用后者，因为后者更方便，也更好理解（而且十分简单）。

具体操作:

对于一个k维的超平面（维度>3想象不出来，就叫超平面），在KD树每一层的构建中都选择一个维度来进行划分，将**k维的数据空间分为两部分**，并使其尽量平衡。然后如此递归下去。

也就是说假如我们要储存n个三维的点(x,y,z)信息。

我们先按x坐标sort一遍，选出中间值 $x_{mid}$作为根节点，然后所有x比$x_{mid}$小的点在左子树，比$x_{mid}$大的在右子树。

然后左,右子树分别按照y坐标sort一遍选出中间值作为子树的根节点，接着再在子树中按照z坐标sort一遍。接着再按x坐标...以此类推。

sort顺序即为:x->y->z->x->y->z->x...

当然每一层的划分方法可以自己来决定，但一般都是按照维度$d_1,d_2,d_3...d_k$来进行划分。你也可以按照自己的顺序来进行(例如:先按$d_1$ sort两遍,再按$d_2$ sort两遍...

一维的KD树即为一颗平衡二叉树

在构建过程中我们需要一个函数来选出中间值,但我们强大的STL里已经有了这个函数,所以我们不必再去手打一个

```
nth_element(a+start,a+nth,a+end)
```

这个函数作用是把a数组从a[start]到a[end]中的第n大的元素放在第n个位置,且nth左边元素都比a[nth]小,右边都比a[nth]大(类似快排的一部分)

时间复杂度为O(n)

那么我们整个build的时间复杂度即为O(nlogn)


这里举个例子: 将(4,7),(9,6),(8,1),(2,3),(5,4),(7,2),构造成一颗KD树。

(这里直接复制我自己的 PPT）

![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTRiMjViYmEyNC5wbmc?x-oss-process=image/format,png)
![2](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmMzMzc5MC5wbmc?x-oss-process=image/format,png)![1](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmJmMmJjMy5wbmc?x-oss-process=image/format,png)
![4](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmM0MmYzOS5wbmc?x-oss-process=image/format,png)
![6](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmNlYmIzNS5wbmc?x-oss-process=image/format,png)
![3](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmMzNTdlMC5wbmc?x-oss-process=image/format,png)
![5](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg0NmM0Y2E3YS5wbmc?x-oss-process=image/format,png)

代码

```cpp
const int dim=2;//定义维度数量
const int Maxn=5e5+10;
struct node{
        int l,r,d[dim];//d为维度
        inline void maintain()//初始化
        {
                l=r=0;
        }
}tree[2*Maxn];

int d;//表示按d维排序

bool operator<(const node & a,const node & b){ return a.d[d]<b.d[d]; }

int build(int l,int r,int now)
{
    int mid=(l+r)>>1;
    d=now;
    nth_element(tree+l,tree+mid,tree+r+1);
    tree[mid].maintain();
    if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
    if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
    push_up(mid);//这个函数为后面的更新操作,这里请先无视
    return mid;
}
```

## 最邻近算法

![1](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg2MDFhNGE4ZC5wbmc?x-oss-process=image/format,png)
![3](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg2MDIxMmIyZi5wbmc?x-oss-process=image/format,png)
![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9pLmxvbGkubmV0LzIwMTkvMDQvMTMvNWNiMTg2MDFjZWEyOC5wbmc?x-oss-process=image/format,png)

这个时候我们每个节点就需要维护一个最大空间（二维就是最大矩阵）

这里说明就用二维说明
```cpp
struct node{
        int l,r,d[dim],maxn[dim],minn[dim];//maxn为矩阵的右上角，minn为左下角
        inline void maintain()//初始化
        {
                l=r=0;
                for(int i=0;i<dim;i++)
                        maxn[i]=minn[i]=d[i];
        }
}tree[2*Maxn];
```

**为什么要维护这个矩阵?**

在上图中，我们在建树时将其分为了好几个矩阵，矩阵所存的就是以它为根节点root的子树的把所有点包括进来的最小矩阵

这个矩阵代表的就相当与当前根节点的父亲f[root]划分出来的矩形，因为只有这么多个点，所以维护的矩阵就是整个平面。

例如之前(7,2)把平面划分为了左右两部分，节点(5,4)中存的矩阵就将是包括(5,4),(2,3),(4,7)的最小矩阵，也就是左边这个平面。



在找到近似点x后的画圆操作就相当于求出查询点y到x的矩阵的距离，然后比较是否比左右儿子的矩阵的距离大，如果大则可能存在点z在左右子树中比当前点距离更进。那么就去搜索。

所以我们每次直接从根节点开始搜索，再来比较就行了。

查询复杂度O$(KN^{1-1/k})$

如果还没懂的话请结合代码理解。（作者语文不好）

如需查找k邻近就直接用优先队列储存就行了
```cpp
/******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月17日 星期日 14时28分34秒
*******************************/
#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+10;
const int dim=2;
const int inf=0x3f3f3f3f;
struct node{
        int l,r,d[dim],maxn[dim],minn[dim];//maxn,minn表示当前节点能维护到的矩阵
        inline void maintain()
        {
                l=r=0;
                for(int i=0;i<dim;i++)
                        maxn[i]=minn[i]=d[i];
        }
}tree[2*Maxn];
int d,root,ans;
bool operator<(const node & a,const node & b) { return a.d[d]<b.d[d]; }
void push_up(int p)//更新
{
        int son[2]={tree[p].l,tree[p].r};
        for(int i=0;i<2;i++)
        {
                if(!son[i])continue;
                for(int j=0;j<dim;j++)
                {
                        tree[p].maxn[j]=max(tree[son[i]].maxn[j],tree[p].maxn[j]);
                        tree[p].minn[j]=min(tree[son[i]].minn[j],tree[p].minn[j]);
                }
        }
}
int build(int l,int r,int now)
{
        int mid=(l+r)>>1;
        d=now;
        nth_element(tree+l,tree+mid,tree+r+1);
        tree[mid].maintain();
        if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
        if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
        push_up(mid);
        return mid;
}
void insert(int & o,int k,int now)
{
        if(o==0) { o=k; return; }
        if(tree[k].d[now]<tree[o].d[now])insert(tree[o].l,k,(now+1)%dim);
        else insert(tree[o].r,k,(now+1)%dim);
        push_up(o);
}
inline int dis_min(int o,int k)//曼哈顿距离
{
        int rst=0;
        for(int i=0;i<dim;i++)
        {
                if(tree[k].d[i]>tree[o].maxn[i])rst+=tree[k].d[i]-tree[o].maxn[i];
                if(tree[k].d[i]<tree[o].minn[i])rst+=tree[o].minn[i]-tree[k].d[i];
        }
        return rst;
}
inline int dis_max(int o,int k)
{
        int rst=0;
        for(int i=0;i<dim;i++)
                rst+=max(abs(tree[k].d[i]-tree[o].minn[i]),abs(tree[k].d[i]-tree[o].maxn[i]));
        return rst;
}
int ansmin,ansmax;
void query_min(int o,int k)
{
        int dm=abs(tree[o].d[0]-tree[k].d[0])+abs(tree[o].d[1]-tree[k].d[1]);
        if(o==k)dm=inf;
        if(dm<ansmin)ansmin=dm;
        int dl=tree[o].l?dis_min(tree[o].l,k):inf;
        int dr=tree[o].r?dis_min(tree[o].r,k):inf;
        if(dl<dr)
        {
                if(dl<ansmin)query_min(tree[o].l,k);
                if(dr<ansmin)query_min(tree[o].r,k);
        }
        else
        {
                if(dr<ansmin)query_min(tree[o].r,k);
                if(dl<ansmin)query_min(tree[o].l,k);
        }
}
void query_max(int o,int k)
{
        int dm=abs(tree[o].d[0]-tree[k].d[0])+abs(tree[o].d[1]-tree[k].d[1]);
        if(dm>ansmax)ansmax=dm;
        int dl=tree[o].l?dis_max(tree[o].l,k):0;
        int dr=tree[o].r?dis_max(tree[o].r,k):0;
        if(dl>dr)
        {
                if(dl>ansmax)query_max(tree[o].l,k);
                if(dr>ansmax)query_max(tree[o].r,k);
        }
        else
        {
                if(dr>ansmax)query_max(tree[o].r,k);
                if(dl>ansmax)query_max(tree[o].l,k);
        }
}
int main()
{
        ios::sync_with_stdio(false);
        int n;
        return 0;
}
```

## 例题

[K远点对](https://www.luogu.org/problemnew/show/P4357)

用优先队列

```cpp
#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e5+10;
const int dim=2;
const int inf=0x3f3f3f3f;
struct Node{
        long long l,r,d[dim],maxn[dim],minn[dim];//maxn,minn表示当前节点能维护到的矩阵
        inline void maintain()
        {
                l=r=0;
                for(int i=0;i<dim;i++)
                        maxn[i]=minn[i]=d[i];
        }
}tree[Maxn];
long long d,root,ans;
bool operator<(const Node & a,const Node & b) { return a.d[d]<b.d[d]; }
void push_up(int p)
{
        long long son[2]={tree[p].l,tree[p].r};
        for(int i=0;i<2;i++)
        {
                if(!son[i])continue;
                for(int j=0;j<dim;j++)
                {
                        tree[p].maxn[j]=max(tree[son[i]].maxn[j],tree[p].maxn[j]);
                        tree[p].minn[j]=min(tree[son[i]].minn[j],tree[p].minn[j]);
                }
        }
}
int build(int l,int r,int now)
{
        int mid=(l+r)>>1;
        d=now;
        nth_element(tree+l,tree+mid,tree+r+1);
        tree[mid].maintain();
        if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
        if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
        push_up(mid);
        return mid;
}
inline long long pf(long long x){return x*x;}
inline long long dis(const Node & x,const Node & y)
{
        long long rst=0;
        for(int i=0;i<dim;i++)
                rst+=pf((long long)x.d[i]-y.d[i]);
        return rst;
}
inline long long dis_max(int o,int k)//欧式距离
{
        long long rst=0;
        for(int i=0;i<dim;i++)
                rst+=max(pf(tree[o].minn[i]-tree[k].d[i]),pf(tree[o].maxn[i]-tree[k].d[i]));
        return rst;
}
priority_queue<long long, vector<long long>,greater<long long> >Q;
void query_max(int o,int k)
{
        long long dm=dis(tree[o],tree[k]);
        if(dm>Q.top())
        {
                Q.pop();
                Q.push(dm);
        }
        long long dl=tree[o].l?dis_max(tree[o].l,k):-inf;
        long long dr=tree[o].r?dis_max(tree[o].r,k):-inf;
        if(dl>dr)
        {
                if(dl>Q.top())query_max(tree[o].l,k);
                if(dr>Q.top())query_max(tree[o].r,k);
        }
        else
        {
                if(dr>Q.top())query_max(tree[o].r,k);
                if(dl>Q.top())query_max(tree[o].l,k);
        }
}
int main()
{
        //freopen("p4357.in","r",stdin);
        //freopen("p4357.out","w",stdout);
        ios::sync_with_stdio(false);
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=2*k;i++)
                Q.push(0);
        for(int i=1;i<=n;i++)
                for(int j=0;j<dim;j++)
                        cin>>tree[i].d[j];
        root=build(1,n,0);
        for(int i=1;i<=n;i++)
                query_max(root,i);
        printf("%lld\n",Q.top());
        return 0;
}

```

[简单题](https://www.luogu.org/problemnew/show/P4148)

KDT矩阵求和操作

```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年03月14日 星期四 16时55分06秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
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
using std::cout; using std::endl;
const int Maxn=5e5+10;
const int dim=2;
struct Node{
        int l,r,sum,val,d[dim],maxn[dim],minn[dim];
        void maintain()
        {
                l=r=0; sum=val;
                for(int i=0;i<dim;i++)
                        maxn[i]=minn[i]=d[i];
        }
}tree[Maxn];
int d;
bool operator<(const Node & x,const Node & y) { return x.d[d]<y.d[d]; }
void push_up(int o)
{
        int son[2]={tree[o].l,tree[o].r};
        for(int i=0;i<2;i++)
        {
                if(!son[i])continue;
                for(int j=0;j<dim;j++)
                {
                        tree[o].maxn[j]=std::max(tree[o].maxn[j],tree[son[i]].maxn[j]);
                        tree[o].minn[j]=std::min(tree[o].minn[j],tree[son[i]].minn[j]);
                }
        }
        tree[o].sum=tree[son[0]].sum+tree[son[1]].sum+tree[o].val;
}
int build(int l,int r,int now)
{
        int mid=(l+r)>>1;
        d=now;
        std::nth_element(tree+l,tree+mid,tree+r+1);
        tree[mid].maintain();
        if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
        if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
        push_up(mid);
        return mid;
}
void insert(int& o,int k,int now)
{
        //if(tree[o].d[0]==tree[k].d[0] and tree[o].d[1]==tree[k].d[1]){tree[o].val+=tree[k].val;return;}
        if(o==0) { o=k; return; }
        if(tree[o].d[now]<tree[k].d[now])insert(tree[o].r,k,(now+1)%dim);       
        else insert(tree[o].l,k,(now+1)%dim);
        push_up(o);
}
int xl,yl,xr,yr,n,opt,root,pos=1;
long long ans;
void query(int o)
{
        if(xr<tree[o].minn[0] or xl>tree[o].maxn[0] or
           yr<tree[o].minn[1] or yl>tree[o].maxn[1])
                return;
        if(xl<=tree[o].minn[0] and xr>=tree[o].maxn[0] and 
           yl<=tree[o].minn[1] and  yr>=tree[o].maxn[1]) {
                ans+=tree[o].sum;
                return;
        }
        if(xl<=tree[o].d[0] and xr>=tree[o].d[0] and yl<=tree[o].d[1] and yr>=tree[o].d[1]) ans+=tree[o].val;
        if(tree[o].l)query(tree[o].l);
        if(tree[o].r)query(tree[o].r);
}
int main()
{
        //freopen("p4148.in","r",stdin);
        //freopen("p4148.out","w",stdout);
        cin>>n;
        while(true)
        {
                cin>>opt;
                if(opt==3)break;
                if(opt==1)
                {
                        cin>>tree[pos].d[0]>>tree[pos].d[1]>>tree[pos].val;
                        tree[pos].d[0]^=ans;tree[pos].d[1]^=ans;tree[pos].val^=ans;
                        tree[pos].maintain();
                        insert(root,pos,0);
                        pos++;
                        if(pos%10000==0)root=build(1,pos-1,0);
                }
                else
                {
                        cin>>xl>>yl>>xr>>yr;
                        xl^=ans;yl^=ans;xr^=ans;yr^=ans;
                        ans=0;
                        query(root);
                        printf("%lld\n",ans);
                }
        }
        return 0;
}

```

[巧克力王国](https://www.luogu.org/problemnew/show/P4475)

有一个限制

```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年03月06日 星期三 21时46分54秒
*******************************/
#include<cstdio>
#include<algorithm>
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
const int Maxn=5e4+10;
const int dim=2;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
struct node{
        int l,r,w,d[dim],minn[dim],maxn[dim],val;
        long long sum;
        void maintain()
        {
                l=r=0; sum=val;
                for(int i=0;i<dim;i++)
                        minn[i]=maxn[i]=d[i];
        }
}tree[Maxn];
int d;
int root,n,m;
long long a,b,c;
bool operator<(const node & x,const node & y) { return x.d[d]<y.d[d]; }
inline void push_up(int o)
{
        int son[2]={tree[o].l,tree[o].r};
        for(int i=0;i<2;i++)
        {
                if(!son[i])continue;
                for(int j=0;j<dim;j++)
                {
                        tree[o].maxn[j]=max(tree[o].maxn[j],tree[son[i]].maxn[j]);
                        tree[o].minn[j]=min(tree[o].minn[j],tree[son[i]].minn[j]);
                }
        }
        tree[o].sum=tree[son[0]].sum+tree[son[1]].sum+tree[o].val;
}
int build(int l,int r,int now)
{
        d=now;
        int mid=(l+r)>>1;
        std::nth_element(tree+l,tree+mid,tree+r+1);
        tree[mid].maintain();
        if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
        if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
        push_up(mid);
        return mid;
}
bool check(long long x,long long y) { return (x*a+y*b<c); }
long long ans;
void query(int o)
{
        int q=0;
        if(check(tree[o].maxn[0],tree[o].minn[1]))q++;
        if(check(tree[o].minn[0],tree[o].maxn[1]))q++;
        if(check(tree[o].maxn[0],tree[o].maxn[1]))q++;
        if(check(tree[o].minn[0],tree[o].minn[1]))q++;
        if(q==0)return;
        if(q==4){ans+=tree[o].sum; return;}
        if(check(tree[o].d[0],tree[o].d[1]))ans+=tree[o].val;
        if(tree[o].l)query(tree[o].l);
        if(tree[o].r)query(tree[o].r);
}
int main()
{
        //freopen("p4475.in","r",stdin);
        //freopen("p4475.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
                cin>>tree[i].d[0]>>tree[i].d[1]>>tree[i].val;
        root=build(1,n,0);
        while(m--)
        {
                cin>>a>>b>>c;
                ans=0;
                query(root);
                printf("%lld\n",ans);
        }
        return 0;
}

```
