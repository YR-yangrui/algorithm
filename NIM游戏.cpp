/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月21日 星期一 16时35分19秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10010;
int T,n,a,ans;
int main()
{
       freopen("NIM游戏.in","r",stdin);
       freopen("NIM游戏.out","w",stdout);
       cin>>T;
       while(T--)
       {
               ans=0;
               cin>>n;
               for(int i=1;i<=n;i++)
                       cin>>a,ans^=a;
               cout<<(ans?"Yes\n":"No\n");
       }
       return 0;
}
