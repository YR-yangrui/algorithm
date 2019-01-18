/*
ID:galaxy_6
LANG:C++
TASK:subset
*/
#include<iostream>
#include<cstdio>
#include<cassert>
using namespace std;
const int maxn=45;
long long n,sum,ans;
long long f[1000];
int main()
{
       freopen("subset.in","r",stdin);
       freopen("subset.out","w",stdout);
       cin>>n;
       for(int i=1;i<=n;i++)sum+=i;
       if(sum%2){cout<<0<<endl;return 0;}
       sum/=2;
       f[0]=1;
       for(int i=1;i<=n;i++)
               for(int j=sum;j>=i;j--)
               {
                       assert(j-i>=0);
                       f[j]+=f[j-i];
               }
       f[sum]/=2;
       cout<<f[sum]<<endl;
       return 0;
}
