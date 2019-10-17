## 题目描述

![屏幕截图.png](https://i.loli.net/2019/10/17/3xmptjHKlhR6kcy.png)

## 题解

首先可以想到要使最大公因数最多为$logn+1$,也就是选$2^{logn}$作为开头，如果可能，也可以选

$2^{logn-1}\times3$作为开头。接着每次减小一个因数来构造答案排列。但题目要求求答案排列的

个数，那么在某一个状态$2^x3^y$时，我们的下一个数有三种可能：

1. 如果$x>0$,把$2$的因数减少一个。

2. 如果$y>0$,把$3$的因数减少一个。

3. 如果范围允许把某一个$2$或$3$改成数。

(考场上想到这就没有然后了。。。mmp考这么久了看到方案竟然没想到dp！)

注意到这3种可能转移，最大公因数都只会含有$2,3$的幂，且$3$最多只有$1$个，那么我们可以

自然得想到设$f(i,x,y)$表示用了$i$个数，最大公因数为$2^x3^y~~~(y\leq 1)$,考虑这么转移：

1.  如果是$2^{x+1}3^y$减少了一个$2$而来的，那么第$i$个位置填的数一定是$2^x3^y$的倍数而不是$2^{x+1}3^y$的倍数。那么有

$$ f(i,x,y)+=f(i-1,x+1,y) \times (\frac{n}{2^x3^y}-\frac{n}{2^{x+1}3^y}) $$

2.  如果是$2^{x}3^{y+1}$减少了一个$3$而来的，那么第$i$个位置填的数一定是$2^x3^y$的倍数而不是$2^{x}3^{y+1}$的倍数。那么有

$$ f(i,x,y)+=f(i-1,x,y+1) \times (\frac{n}{2^x3^y}-\frac{n}{2^{x}3^{y+1}}) $$

3. 如果第$i$个数填的是$2^x3^y$的倍数，那么要注意把已经填了的个数减去。

$$ f(i,x,y)+=f(i-1,x,y) \times (\frac{n}{2^x3^y} -(i-1) )$$

那么这样就做完了。

## $\mathcal{Code}$

```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年10月17日 星期四 09时48分24秒
*******************************/
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=1e6+10;
const int mod=1e9+7;
const int LG=20;
int n,f[maxn][LG][2],cs,tmp;

inline int calc(int x, int y)
{
    if (y)
        return n / 3 / (1 << x);
    else
        return n / (1 << x);
}


int main()
{
    //freopen("gcd.in","r",stdin);
    //freopen("gcd.out","w",stdout);
    cin>>n;
    tmp=1;
    while(tmp*2<=n)cs++,tmp*=2;
    f[1][cs][0]=1;
    if(tmp/2*3<=n)
        f[1][cs-1][1]=1;
    for(int i=2;i<=n;i++)
        for(int x=0;x<=cs;x++)
            for(int y=0;y<=1;y++)
            {
                f[i][x][y]=1ll*f[i-1][x][y]*(calc(x,y)-(i-1))%mod;
                if(x<cs)
                    f[i][x][y]=(f[i][x][y]+1ll*f[i-1][x+1][y]*(calc(x,y)-calc(x+1,y)%mod))%mod;
                if(y<1)
                    f[i][x][y]=(f[i][x][y]+1ll*f[i-1][x][y+1]*(calc(x,y)-calc(x,y+1))%mod)%mod;
            }
    cout<<f[n][0][0]<<endl;
    return 0;
}

```
