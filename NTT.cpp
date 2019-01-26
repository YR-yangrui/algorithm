/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月25日 星期五 16时50分39秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=3*1e6+10;
const int p=998244353;
long long rev[maxn];
long long n,m,a[maxn],b[maxn],g=3;
struct IO{
        template<class T>
        IO & operator>>(T&res)
        {
                T q=1;
                char ch=getchar();
                while(ch<'0' or ch>'9'){if(ch=='-')q=-q;ch=getchar();}
                res=(ch^48);
                while((ch=getchar())>='0' and ch<='9')
                        res=(res<<1)+(res<<3)+(ch^48);
                res*=q;
                return *this;
        }
};
inline long long ksm(long long a,long long b,long long c)
{
        long long ans=1;
        a%=c;
        while(b)
        {
                if(b&1)ans=ans*a%c;
                a=a*a%c;
                b>>=1;
        }
        return ans;
}
inline void get_rev(int bit)
{
        for(int i=0;i<=(1<<bit);i++)
                rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
        return;
}
inline void NTT(long long *a,long long len,long long on)
{
        for(int i=0;i<len;i++) if(i<rev[i])swap(a[i],a[rev[i]]);
        for(int i=2;i<=len;i<<=1)
        {
                long long wn=ksm(g,(p-1)/i,p);
                if(on==-1)wn=ksm(wn,p-2,p);
                for(int j=0;j<len;j+=i)
                {
                        long long w=1;
                        for(int k=j;k<i/2+j;k++)
                        {
                                long long u=a[k],v=a[k+i/2]*w%p;
                                a[k]=((u+v)%p+p)%p;a[k+i/2]=(u-v+p)%p;
                                w=w*wn%p;
                        }
                }
        }
        if(on==-1)
        {
                long long inv=ksm(len,p-2,p);
                for(int i=0;i<len;i++)a[i]=a[i]*inv%p;
        }
}
int main()
{
        freopen("NTT.in","r",stdin);
        freopen("NTT.out","w",stdout);
        g=3;
        cin>>n>>m;
        for(int i=0;i<=n;i++)cin>>a[i],a[i]=(a[i]+p)%p;;
        for(int i=0;i<=m;i++)cin>>b[i],b[i]=(b[i]+p)%p;
        int len=0,s=1;
        while(s<=n+m)len++,s<<=1;
        get_rev(len);
        NTT(a,s,1),NTT(b,s,1);
        for(int i=0;i<s;i++)a[i]=a[i]*b[i]%p;
        NTT(a,s,-1);
        for(int i=0;i<=n+m;i++) cout<<a[i]<<' ';
        cout<<endl;
        return 0;

}
