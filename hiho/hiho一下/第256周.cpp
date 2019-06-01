/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月01日 星期六 11时02分58秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
long long n,q,k,ans;
int main()
{
        freopen("第256周.in","r",stdin);
        freopen("第256周.out","w",stdout);
        cin>>n>>q;
        k=n/(q<<1);
        long long t=k;
        k=0;
        while(t)
            k++,t>>=1;
        ans=k*q+(n+(1LL<<k)-1)/(1LL<<k);
        cout<<ans<<endl;
        return 0;
}
