/*
ID:galaxy_6
LANG:C++
TASK:sort3
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1005;
int n,a[maxn],s[4],ans;
bool check(int i)
{
        for(int j=s[a[i]-1]+1;j<=s[a[i]];j++)
                if(s[a[j]]>=i and s[a[j]-1]<i and a[i]!=a[j])
               {
                       ans++;
                       swap(a[i],a[j]);
                       return true;
               }
       return false;
}
int main()
{
       freopen("sort3.in","r",stdin);
       freopen("sort3.out","w",stdout);
       cin>>n;
       for(int i=1;i<=n;i++)cin>>a[i];
       for(int i=1;i<=n;i++) s[a[i]]++; 
       s[2]+=s[1];
       s[3]+=s[2];
       for(int i=1;i<=n;i++)
       {
               if(i<=s[a[i]] and i>s[a[i]-1])continue;
               else 
               {
                       if(check(i))continue;
                       else 
                               for(int j=s[a[i]-1]+1;j<=s[a[i]];j++)
                                       if(a[j]!=a[i])
                                       {
                                               swap(a[j],a[i]);
                                               ans++;
                                               i--;
                                               continue;
                                       }
               }
       }
       cout<<ans<<endl;
       return 0;
}
