
## 题目描述

![](https://s2.ax1x.com/2019/10/10/u7Z6Nd.png)

数据范围为$\mathtt{L,R \leq 10^{500000}}$


## 题解与思路历程

这一看数据范围就能想到<font size="5">数位dp</font>

然后数位dp都是套路差不多的方法。

考虑快速计算1 ~ n的答案，那么可以简单的用1~R的答案减去1~L-1的答案即可。

首先可以写出如下的框架：


```cpp
void dp(int now,int lim,int sum) //now:当前dp到第几位,前一位是否有限制
//根据题目，还需要求出前面位中的逆序对。
{
    if(!lim) { return count(len-now+1); } //没有限制则直接计算答案
    if(now==len+1) { ans+=sum; return; } //一直到末位了，计算答案

    {
        //继续递归限制
    }
    //递归没有限制
}
```

考虑怎么求$count()$函数。

$count()$函数需要做的就是求出剩下所有位随便填相互造成的"鲳对"数,以及对前面已经选择的数 造成的"鲳对"数


* 对于前者

考虑怎么求1~$10^{len}$中的所有"鲳对"：

若$len \leq 1$,则无"鲳对"

否则：

考虑第$i$位摆$x$，右边的$n-i$位上任意的某一位若摆小于$x$的数，则有一个"鲳对"

因为$x=0...9$,右边某一位的取值分别为$0...1,0...2,...,0...8$

所以对于第$i$位，右边某一位的取值方案有$45$种,一共有$45 \times (len-i)$种,每一位单独考虑
其余位置都有$10^{len-2}$的放数方法。


所以答案应该为

$$
\sum_{i=1}^{len}{45 \times (len-i) \times 10^{len-2}}
$$

设上面这玩意儿为$s[len]$,显然可以$O(n)$预处理出$s$数组。

```cpp
void init()
{
    ten[0]=1;
    long long x=45,t=0;
    for(int i=1;i<=5e5;i++)
    {
        ten[i]=ten[i-1]*10LL%mod;
        t+=i;
        t%=mod;
        s[i+1]=1ll*x*ten[i-1]%mod*t%mod;
    }
}

```

* 对于后者

我们设$gs[0$~$9]$表示前面已经选择了有哪些数(gs=个数),后面还剩$len$个位置

对于$gs[i]$显然有$"鲳对"=gs[i] \times 10^{len-1} \times i \times len$

所以得出$count()$函数为:

```cpp
void count(int len)
{
    ans+=s[len];
    if(ans>mod) ans-=mod;
    for(int i=1;i<10;i++)
        ans=(ans+1ll*gs[i]*ten[len-1]%mod*(1ll*i*len)%mod)%mod;
}
```

* 但这样我们还漏掉了一个地方的贡献（就是这个地方导致我调了1h!!!)

那就是我们在dp时已知前面确定了的数字之间的"鲳对"为$sum$,那么后面我们不管怎么填都有至少$sum$个"鲳对"。

只要考虑好以上几点我们就可以很好的写出dp的所有部分了，最后记得是计算$L-1$的贡献

## $\mathcal{Code}$
```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年10月09日 星期三 14时16分22秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define int long long

using namespace std;

const int maxn=1e6+10;
const int mod=998244353;
int T,id,ten[maxn],s[maxn],gs[11],len;
long long ans,res;
string ss;

void init()
{
    ten[0]=1;
    long long x=45,t=0;
    for(int i=1;i<=5e5;i++)
    {
        ten[i]=ten[i-1]*10LL%mod;
        t+=i;
        t%=mod;
        s[i+1]=1ll*x*ten[i-1]%mod*t%mod;
    }
}

void count(int len)
{
    ans+=s[len];
    if(ans>mod) ans-=mod;
    for(int i=1;i<10;i++)
        ans=(ans+1ll*gs[i]*ten[len-1]%mod*(1ll*i*len)%mod)%mod;
}

void dp(int now,int lim,int sum)
{
    //没有限制，则计算答案
    if(!lim) { ans=(ans+(sum*ten[len-now+1])%mod)%mod; return count(len-now+1) ;}
    if(now==len+1) { ans+=sum; return; }
    int c=ss[now]-'0',tmp=0;
    //先考虑有限制
    {
        gs[c]++;
        for(int i=c+1;i<10;i++)
        {
            tmp+=gs[i];
            tmp%=mod;
        }
        dp(now+1,1,(sum+tmp)%mod);
        gs[c]--;
    }
    //考虑没有限制
    for(int i=0;i<c;i++)
    {
        gs[i]++;
        tmp=0;
        for(int j=i+1;j<10;j++)
            tmp+=gs[j];
        dp(now+1,0,(sum+tmp)%mod);
        gs[i]--;
    }
}

//计算L这个数的"鲳对"
void add()
{
    for(int i=1;i<=len;i++)
    {
        int c=ss[i]-'0';
        gs[c]++;
        for(int j=c+1;j<10;j++)
            ans-=gs[j];
        ans=(ans+mod)%mod;
    }
    for(int i=0;i<10;i++)
        gs[i]=0;
}

signed main()
{
    //freopen("pair.in","r",stdin);
    //freopen("pair.out","w",stdout);
    ios::sync_with_stdio(false);
    init();
    cin>>T>>id;
    while(T--)
    {
        ans=res=0;
        cin>>ss;
        len=ss.size(); ss="$"+ss;
        dp(1,1,0); add();
        res=ans,ans=0;
        cin>>ss;
        len=ss.size(); ss="$"+ss;
        dp(1,1,0);
        cout<<(ans-res+mod)%mod<<endl;
    }
    return 0;
}

```

一定要记得开`long long`,考试时就是这个原因导致$WA$和$RE$
