/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月25日 星期五 15时40分47秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
inline int Phi(int k)
{
        int res=k;
        for(int i=2;i*i<=k;i++)
        {
                if(k%i)continue;
                res=res/i*(i-1);
                while(k%i==0)k/=i;
        }
        if(k>1)res=res/k*(k-1);
        return res;
}
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
        return ans%c;
}
int q[1000000];
inline int G(int m)
{
        const int phi=Phi(m);
       int  t=phi;
        q[0]=0;
        for(int i=2;i*i<=phi;i++)
                if(t%i==0)
                {
                        q[++q[0]]=phi/i;
                        while(t%i==0)t/=i;
                }
        if(t>1)q[++q[0]]=phi/t;
        for(int g=2;;g++)
        {
                bool flag=1;
                if(ksm(g,phi,m)!=1)continue;
                for(int i=1;i<=q[0];i++)
                        if(ksm(g,q[i],m)==1)
                        {
                                flag=0;
                                break;
                        }
                if(flag)return g;
        }
}
int m,g;
int main()
{
        freopen("原根.in","r",stdin);
        freopen("原根.out","w",stdout);
        cin>>m;
        g=G(m);
        cout<<g<<endl;
        return 0;
}
