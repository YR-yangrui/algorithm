/*
ID:galaxy_6
LANG:C++
TASK:skidesign
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int n;
int h[maxn],mind=0x7ffffff;
int main()
{
       freopen("skidesign.in","r",stdin);
       freopen("skidesign.out","w",stdout);
       cin>>n;
       for(int i=1;i<=n;i++)cin>>h[i];
       for(int i=1;i<=100;i++)
       {
               int ans=0;
               for(int j=1;j<=n;j++)
                       if(h[j]<i) ans+=(i-h[j])*(i-h[j]);
                       else if(h[j]>i+17) ans+=(i+17-h[j])*(i+17-h[j]);
               mind=min(ans,mind);
       }
       cout<<mind<<endl;
       return 0;
}
