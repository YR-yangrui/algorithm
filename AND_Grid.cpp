/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月29日 星期二 08时03分27秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=505;
int n,m,a[maxn][maxn],b[maxn][maxn],c;
char ch;
void print(int a[][505])
{
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                        cout<<a[i][j]<<' ';
                cout<<endl;
        }
        return;
}
int main()
{
        freopen("AND_Grid.in","r",stdin);
        freopen("AND_Grid.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                {
                        cin>>ch;
                        if(ch=='#')b[i][j]=1;
                }
        c=1;
        //print(b);
        for(int i=1;i<=n;i++,c=!c)
                for(int j=2;j<=m-1;j++)
                        a[i][j]=c;
        for(int i=1;i<=n;++i) a[i][1]=1;
        //print(a);
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        if(a[i][j] or b[i][j])
                                cout<<'#';
                        else cout<<'.';
                }
                cout<<endl;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
                for(int j=1;j<=m;j++)
                {
                        if(a[i][j]==0 or b[i][j])
                                cout<<'#';
                        else cout<<'.';
                }
                cout<<endl;
        }
        return 0;
}
