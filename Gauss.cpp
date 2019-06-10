/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019/6/2 15:44:53
*******************************/
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
using namespace std;
const int maxn=105;
int n;
double a[maxn][maxn],b[maxn],res[maxn];
bool flag;
void Gauss()
{
    for(int i=1;i<=n;i++)
    {
        int k=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(a[j][i])>fabs(a[k][i]))
                k=j;
        if(k!=i)
        {
            for(int j=1;j<=n;j++)
                swap(a[i][j],a[k][j]);
            swap(b[i],b[k]);
        }
        if(!a[i][i]){flag=1;return ;}
        for(int j=i+1;j<=n;j++)
        {
            long double del=(long double)a[j][i]/a[i][i];
            for(int k=i;k<=n;k++)
                a[j][k]=a[j][k]-a[i][k]*del;
            b[j]=b[j]-b[i]*del;
        }
    }
    for(int i=n;i;--i)
    {
        for(int j=n;j>i;--j)
            b[i]-=(double)a[i][j]*res[j];
        res[i]=(double)b[i]/a[i][i];
    }
}
int main()
{
        //freopen("gauss.in","r",stdin);
        //freopen("gauss.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cin>>a[i][j];
            cin>>b[i];
        }
        Gauss();
        if(flag){cout<<"No Solution\n";return 0;}
        for(int i=1;i<=n;i++)
            cout<<fixed<<setprecision(2)<<res[i]<<endl;
        return 0;
}
