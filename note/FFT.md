#FFT快速傅里叶变换

参考和部分摘自:
[博客1](https://blog.csdn.net/ggn_2015/article/details/68922404)
[博客2](https://blog.csdn.net/leo_h1104/article/details/51615710)
### 1.系数表示法与点值表示法
系数表表示法，就是用一个多项式的各个项的系数表示这个多项式，也就是我们平时所用的表示法。例如，我们可以这样表示：
　f(x)=$a_0$+$a_1$x+$a_2x^2$+..+$a_nx^n$ ⇔ f (x)={$a_0$,$a_1$,$a_2$,..,$a_n$} -> f(x)={a[0],a[1],a[2],...a[n]}
点值表示法:一个最高次为n-1次的多项式f(x)，可以表示为n个其图像上点(x,y)，例如2x^2+3x+1可以表示为(0,1) (1,6) (2,15)

* **DFT:** 把一个多项式转化为“离散的点”表示的方法就叫做“ＤＦＴ”（离散傅里叶变换） 
* **IDFT**　把“离散的点”还原回多项式的方法就叫做“ＩＤＦＴ”（离散傅里叶反变换）

### 2.复数的引入

   1. i=$\sqrt{-1}$表示这个”虚数单位“，”ｉ“对于虚数的意义相当于”数字１“对于实数的意义
   2. 复数x被定义为二元有序实数对(a,b) ，记为z=a+bi,这里a和b是实数，i是虚数单位。 
   3. z=a+bi 或z=r*cos(θ)+r*sin(θ)i
   ![](https://i.loli.net/2019/01/17/5c3fcc6e2fcd5.png)
    
   4. **单位复根** 能够通过k次方运算回到“1”的数，我们叫它“复根”用“ω”表示。如果ωk=1，那么我们称“ω为1的k次复根”计做“$ω_n^k$”;
   以“四次负根”“$ω_n^4$”为例：

   ![](https://img-blog.csdn.net/20170331142853692?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvR0dOXzIwMTU=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

   你会发现：其实k次负根就相当于是给图中的圆周平均分成k个弧，弧与弧之间的端点就是“复根”，

   另外$ω_2^4$=−1=$i^2=(ω_1^4)^2,ω_3^4=−i=i^3=(ω_1^4)^3，ω_0^4$是这个圆与“Real”轴正半轴的交点，所以无论k取多少，$ω_0^4$始终=1。我们只需要知道$ω_1^4$，就能求出$ω_n^k$，所以我们称“$ω_1^k$ ”为“单位复根”。

    其实，我们用“$ω_k$”表示单位复根，$ω_1^k$表示的是“单位复根”的“1次方”也就是它本身,其他的就叫做k次单位复根的n次方。

   5. 性质:
       0. w=cos(2π/n)+i*sin(2π/n)
       1. $w_n^{2k}$=$w_{n/2}^k$ 
       2. $w_n^k$=-$w_n^{k+n/2}$  //ｎ为偶数
       3. $w^x$*$w^x$=$w^{2x}$
       4. $w^x*w^y=w^{x+y}$
       5. $w^{k+n/2}=-w^k$

### 3.DFT

* 利用分治思想求x=$ω_n^k$
```你可以把一个多项式分成奇数次数项，和偶数次数项两部分，然后再用分治的思想去处理它的“奇数次项”和“偶数次项”。```

对于A(x)=a[0]+a[1]*x+a[2]*$x^2$+...+a[n-1]*$x^{n-1}$ //n为偶数

设O(x)=a[1]+a[3]*x+a[5]*x^2+...+a[n-1]*$x^{n/2-1}$

E(x)=a[0]+a[2]*x+a[4]*$x^2$+...+a[n-2]*$x^{n/2-1}$

 则有A(x)=x*O($x^2$)+E($x^2$)

```c++
void FFT(complex<double>a[],int len)
{
        complex<double>buf[len];
        int mid=len>>1;
        for(int i=0;i<mid;i++)buf[i]=a[2*i],buf[i+mid]=a[2*i+1];
        for(int i=0;i<len;i++)a[i]=buf[i];
        FFT(a,mid);FFT(a+mid,mid);
        complex<double> wn(cos(2*PI/len),sin(2*PI/n)),w=complex(1,0);
        for(int i=0;i<mid;i++)
        {
                buf[i]=a[i]+wn*a[i+mid];
                buf[i+mid]=a[i]-wn*a[i+mid];
                w=w*wn;
        }
        for(int i=0;i<len;i++)a[i]=buf[i];
}
```

### 4.IDFT

* *设$y_0,y_1,y_2,...,y_{n-1}$为($a_0,a_1,a_2,...a_{n-1}$)的点值表示)*
* 设有另一个向量($c_0,c_1,c_2,...c_{n-1}$)满足$c_k$=$\sum_{i=0}^{n-1}{y_i(w_n^{-k})^i}$

   可得:$a_k=c_k/n$

<details>
<summary>证明</summary>
 
![](https://i.loli.net/2019/01/17/5c4027a2068c1.png)
![](https://i.loli.net/2019/01/17/5c4027a204190.png)
![](https://i.loli.net/2019/01/17/5c4027a1c4305.png)

</details>

``` cpp
void IDFT(complex<double>a[],int len)
{
        complex<double>buf[len];
        int mid=len>>1;
        for(int i=0;i<mid;i++)buf[i]=a[2*i],buf[i+mid]=a[2*i+1];
        for(int i=0;i<len;i++)a[i]=buf[i];
        IDFT(a,mid);IDFT(a+mid,mid);
        complex<double> wn=complex(cos(2*PI/len),-sin(2*PI/len)),w=complex(1,0);
        for(int i=0;i<mid;i++)
        {
                buf[i]=a[i]+w*a[i+mid];
                buf[i+mid]=a[i]-w*a[i+mid];
                w=w*wn;
        }
        for(int i=0;i<len;i++)a[i]=buf[i];
}
//代码与FFT相似，可以带个参数合在一起。
```

### 5.高效FFT实现——迭代法

* **雷德算法**

> 上述代码花费了大量空间用于创建和维护数组，而我们可以使用迭代法避免这一部分的空间使用
  为了迭代，首先数组被分治到的部分必须连续，观察递归调用的过程可以发现，分治是按照二进制的末位开始分类的，如n=8时,分治顺序如下

>             0,1,2,3,4,5,6,7

>            (0,2,4,6)(1,3,5,7)

>            (0,4)(2,6)(1,5)(3,7)

>  写成二进制000,100,010,110,001,101,011,111

>  将二进制翻转000,001,010,011,100,101,110,111这不正是0~7的单增序列吗？
>  原理是翻转后末位变首位，而高位恰恰决定了数的大小
  于是我们递推预处理出rev数组

  ```cpp
 void get_rev(int bit)
{
	for(int i=0;i<(1<<bit);i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}
  ```

然后根据rev对a重新排序，就可以进行迭代fft了，我们已知含一个元素的DFT为系数本身，那么将其按次序使用蝴蝶操作两两合并就能得到两个元素的DFT，然后再合并得到四元素DFT，以此类推，就可以得到整个式子的DFT

具体：对于**顺序数ｉ**，**倒序数ｊ**存在关系：

```
ｉ＝ｊ时，不交换。

ｉ<ｊ时，交换储存器内容

ｉ>ｊ时，不交换，直接更新序数值
```

```cpp
typedef complex<double>cd;
void fft(cd * a,int n,int on)//len必须是$2^k$形式,on:ifft,fft切换
{
        for(int i=0;i<n;i++) if(i<rev[i])swap(a[i],a[rev[i]]);
        for(int step=2;step<=n;step<<=1)
        {
                cd wn=cd(cos(2*PI/step),sin(on*2*PI/step));//单位复根
                for(int j=0;j<n;j+=step)
                {
                        cd w(1,0);//旋转因子
                        for(int k=j;k<j+step/2;k++)
                        {
                                cd u=a[k],t=w*a[k+h/2];
                                a[k]=u+t;a[k+h/2]=u-t;//合并操作
                                w=w*wn;//更新旋转因子
                        }
                }
        }
}
```

---------------------

