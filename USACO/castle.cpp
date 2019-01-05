/*
ID:galaxy_6
LANG:C++
TASK:castle
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=55;
int n,m,house[maxn][maxn];
int num=1,c[maxn][maxn],big,a[maxn*maxn];
void dfs(int x,int y,int k)
{
        c[x][y]=num;
        a[num]++;
        int t=house[x][y];
        if(t>=8)t-=8;
        else if(!c[x+1][y])dfs(x+1,y,0);
        if(t>=4)t-=4;
        else if(!c[x][y+1])dfs(x,y+1,0);
        if(t>=2)t-=2;
        else if(!c[x-1][y])dfs(x-1,y,0);
        if(t>=1)t-=1;
        else if(!c[x][y-1])dfs(x,y-1,0);
        if(k)
        {
                if(a[num]>big)big=a[num];
                num++;
        }
        return;
}
int x,y,maxd=-1;
char ch;
void check(int x1,int y1,int x2,int y2,char cx)
{
        if(a[c[x1][y1]]+a[c[x2][y2]]>maxd){maxd=a[c[x1][y1]]+a[c[x2][y2]];x=x1;y=y1;ch=cx;}
}
int main()
{
       freopen("castle.in","r",stdin);
       freopen("castle.out","w",stdout);
       cin>>m>>n;
       for(int i=1;i<=n;i++)
               for(int j=1;j<=m;j++)
                       cin>>house[i][j];
       for(int i=1;i<=n;i++)
               for(int j=1;j<=m;j++)
                       if(!c[i][j])
                               dfs(i,j,1);
       for(int i=1;i<=m;i++)
               for(int j=n;j>=1;j--)
               {
                       if(j!=1)
                       {
                               if(c[j][i]!=c[j-1][i])
                                       check(j,i,j-1,i,'N');
                       }
                       if(i!=m)
                       {
                               if(c[j][i]!=c[j][i+1])
                                       check(j,i,j,i+1,'E');
                       }
               }
       cout<<num-1<<endl<<big<<endl<<maxd<<endl<<x<<' '<<y<<' '<<ch<<endl;
       return 0;
}
