/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月11日 星期二 14时24分06秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
long long n,p,k,ans,a;
long long ksm(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1)res=res*a%p;
        a=a*a%p;
        b>>=1;
    }
    return res;
}
int main()
{
        freopen("乘法逆元2.in","r",stdin);
        freopen("乘法逆元2.out","w",stdout);
        cin>>n>>p>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            ans=(ans+k*ksm(a,p-2))%p;
            k=k*k%p;
        }
        cout<<ans<<endl;
        return 0;
}
