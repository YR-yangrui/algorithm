### $n ~ day$前学习了$FWT$，一直没有打，最近打了板子，来总结一下

$FWT$是利用分治的方法来求解多项式诸如

$$C_k=\sum_{i+j=k}A_i \oplus B_j ~ (\oplus=and,xor,or)$$

的运算。相比于朴素的$O(n^2)$做法，$FWT$的时间复杂度为$O(nlogn)$

## 具体做法

考虑$FFT$中系数转点值的方法是否能利用到求上述式子中来。

即对于这样的一个多项式我们能否也能做到用以下三步求解:

1. 对$A,B$进行$FWT$操作
2. 令$C_i=A_i \times B_i$
3. 对$C$进行$IFWT$操作

那么我们考虑如何来构建$A^{'},B^{'}$和$C^{'}$,使得达到第二、三步骤。

### 与运算&

考虑多项式$len=2$的情况。那么

$C_0=A_0B_1+A_1B_0+A_0B_0$

$C_1=A_1B_1$

发现若$A_1^{'}=A_1,B_1^{'}=B_1$,那么$C_1=A_1^{'}B_1^{'}$,但对于$C_0$则不好考虑，因为$C_0$中$A,B$的下标皆有$0,1$，但少了个$A_1B_1$,我们不好构造出 $ A_0^{'},B_0^{'} $ 来使得$C_0=A_0^{'}B_0^{'}$。

那么我们试着写出以下式子:

$A_0^{'}=A_0+A_1$

$B_0^{'}=B_0+B_1$

$C_0^{'}=A_0B_1+A_1B_0+A_0B_0+A_1B_1$

$C_1^{'}=A_1B_1$

那么对于第二个步骤即可解决,同时对于步骤三，我们$IFWT$时只要让$C_0=C_0^{'}-C_1^{'},C_1^{'}$不变即可($IFWT$对于$A,B$的变换也是对的)。

这样时间复杂度为$O(nlogn)$

### 异或运算^

同样考虑多项式$len=2$的情况，那么

$C_0=A_1B_1+A_0B_0$

$C_1=A_0B_1+A_1B_0$

同样要满足上面的三个步骤,那么$C_0^{'}$和$C_1^{'}$都不好求，所以我们的$C^{'}$要都包含$4$个式子。

我们试着写出以下式子:

$C_0^{'}=A_0B_0+A_1B_1+A_0B_1+A_1B_0$

$C_1^{'}=A_0B_0+A_1B_1-A_0B_1-A_1B_0$

$A_0^{'}=A_0-A_1$

$A_1^{'}=A_0+A_1$


$B_0^{'}=B_0-B_1$

$B_1^{'}=B_0-B_1$

那么第二个步骤即可解决，同时对于步骤三，我们$IFWT$时的操作即为使$C_0=(C_0^{'}+C_1^{'})/2,C_1=(C_0^{'}-C_1^{'})/2$即可

接下来的或运算是同样的方法,这里就不写了。

## 总结

对于$C_0,C_1$。

1. 若都为两项则相加，相减。

2. 若一个为$3$项，一个为$1$项,则把$3$项的加一个项

接着怎么变过去的就怎么变回来。

最后[洛谷FWT模板](https://www.luogu.org/problem/P4717)的代码如下:

```cpp
/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月28日 星期三 19时44分29秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
const int maxn=1<<18;
long long inv2,n,len=1,a[maxn],b[maxn],c[maxn];
void FWT(long long * a,long long n,long long on,int opt)//opt=0 or,opt=1 and opt=3 xor 
{
    static long long tmp;
    for(int len=2;len<=n;len<<=1)
        for(int i=0;i<n;i+=len)
            for(int j=i;j<i+len/2;j++)
            {
                if(opt==0)
                {
                    if(on) a[j+len/2]+=a[j];
                    else
                        a[j+len/2]-=a[j];
                }
                if(opt==1)
                {
                    if(on)
                        a[j]+=a[j+len/2];
                    else
                        a[j]-=a[j+len/2];
                }
                if(opt==2)
                {
                    if(on)
                        tmp=a[j], a[j]-=a[j+len/2], a[j+len/2]+=tmp;
                    else
                        tmp=a[j],a[j]=(a[j]+a[j+len/2])*inv2,a[j+len/2]=(a[j+len/2]-tmp)*inv2;
                }
                a[j]%=mod; a[j+len/2]%=mod;

            }
}
long long ksm(long long a,long long b)
{
    long long ans=1; a%=mod;
    while(b)
    {
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}
int main()
{
    //freopen("FWT.in","r",stdin);
    //freopen("FWT.out","w",stdout);
    inv2=ksm(2,mod-2);
    cin>>n; len<<=n;
    for(int i=0;i<len;i++)cin>>a[i];
    for(int i=0;i<len;i++)cin>>b[i];
    for(int i=0;i<3;i++)
    {
        FWT(a,len,1,i);
        FWT(b,len,1,i);
        for(int j=0;j<len;j++)
            c[j]=(a[j]*b[j])%mod;
        FWT(c,len,0,i);
        FWT(a,len,0,i);
        FWT(b,len,0,i);
        for(int j=0;j<len;j++)
            cout<<(c[j]%mod+mod)%mod<<' ';
        cout<<endl;
    }
    return 0;
}

```
