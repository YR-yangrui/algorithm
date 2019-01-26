/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月25日 星期五 15时07分18秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
long long a,m,phi;
long long Phi()
{
        long long res=m,t=m;
        for(int i=2;i*i<=m;i++)
        {
                if(t%i==0)
                {
                        res=res/i*(i-1);
                        while(t%i==0)t/=i;
                }
        }
        if(t>1)res=res/t*(t-1);
        return res;
}
long long ksm(long long a,long long b,long long c)
{
        long long ans=1;
        a%=c;
        if(a==0)ans=0;
        while(b)
        {
                if(b&1)ans=ans*a%c;
                a=a*a%c;
                b>>=1;
        }
        return ans%c;
}
bool fl;
int main()
{
        freopen("欧拉定理.in","r",stdin);
        freopen("欧拉定理.out","w",stdout);
        cin>>a>>m;
        phi=Phi();
        long long b=0;
        char ch=cin.get();
        while(ch<'0' or ch>'9')ch=cin.get();
        b=(ch^48);
        while((ch=cin.get())>='0' and ch<='9')
        {
                b=b*10+(ch^48);
                if(b>=phi)fl=1,b%=phi;
        }
        if(fl)b+=phi;
        cout<<ksm(a,b,m)<<endl;
}
