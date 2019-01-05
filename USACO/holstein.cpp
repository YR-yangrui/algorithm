/*
ID:galaxy_6
LANG:C++
TASK:holstein
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=30;
int n,a[maxn],m;
int s[maxn][maxn];
int x[maxn];
bool check()
{
        for(int i=1;i<=n;i++)
                if(x[i]<a[i])return false;
        return true;

}
bool chos[maxn],ok;
void dfs(int lim,int now,int loc)
{
        if(ok)return;
        if(now==lim)
        {
                if(check())
                {
                        cout<<lim<<' ';
                        for(int i=1;i<=m;i++)
                                if(chos[i])
                                {
                                        cout<<i;
                                        for(++i;i<=m;i++)
                                                if(chos[i])
                                                        cout<<' '<<i;
                                        break;
                                }
                        cout<<endl;
                        ok=1;
                        return;
                }
        }
        for(int i=loc+1;i<=m;i++)
        {
                if(ok)return;
                chos[i]=1;
                for(int j=1;j<=n;j++)
                        x[j]+=s[i][j];
                dfs(lim,now+1,i);
                for(int j=1;j<=n;j++)
                        x[j]-=s[i][j];
                chos[i]=0;
        }
}
int main()
{
       freopen("holstein.in","r",stdin);
       freopen("holstein.out","w",stdout);
       cin>>n;
       for(int i=1;i<=n;i++)cin>>a[i];
       cin>>m;
       for(int i=1;i<=m;i++)
               for(int j=1;j<=n;j++)
                       cin>>s[i][j];
       for(int i=1;i<=n;i++)
       {
               if(ok)break;
               dfs(i,0,0);
       }
       return 0;
}
