/*
ID:galaxy_6
LANG:C++
TASK:ariprog
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=250020;
int n,m;
bool co[maxn];
bool check(int st,int b)
{
        if(!co[st])return false;
        if(!co[st+(n-1)*b])return false;
        for(int i=1;i<n;i++)
                if(!co[(st+=b)])return false;
        return true;
}
bool ok;
int main()
{
       freopen("ariprog.in","r",stdin);
       freopen("ariprog.out","w",stdout);
       cin>>n>>m;
       for(int i=0;i<=m;i++)
               for(int j=0;j<=m;j++)
                       co[i*i+j*j]=1;
       for(int i=1;i<=m*m;i++)
               for(int j=0;j<=m*m;j++)
               {
                       if((n-1)*i>m*m*2)break;
                       if(check(j,i))
                       {
                               cout<<j<<' '<<i<<endl;
                               ok=1;
                       }
               }
       if(!ok)cout<<"NONE\n";
       return 0;
}
