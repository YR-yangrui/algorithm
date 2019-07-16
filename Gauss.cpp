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
int n,m;
double a[maxn][maxn],b[maxn],res[maxn];
bool Many_solution,No_solution;
void Gauss()
{
    for(int i=1;i<=m;i++)
    {
        int k=i;
        for(int j=i+1;j<=m;j++)
            if(fabs(a[j][i])>fabs(a[k][i]))
                k=j;
        if(k!=i)
        {
            for(int j=1;j<=n;j++)
                swap(a[i][j],a[k][j]);
            swap(b[i],b[k]);
        }
        if(!a[i][i]){Many_solution=1;}
        for(int j=i+1;j<=m;j++)
        {
            long double del=(long double)a[j][i]/a[i][i];
            for(int k=i;k<=n;k++)
                a[j][k]=a[j][k]-a[i][k]*del;
            b[j]=b[j]-b[i]*del;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(b[i]>1e-14 or b[i]<-1e-14)
        {
            No_solution=true;
            for(int j=1;j<=n;j++)
                if(a[i][j]>1e-14 or a[i][j]<-1e-14)
                {
                    No_solution=false;
                    break;
                }
            if(No_solution)
                return;
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
    freopen("Gauss.in","r",stdin);
    freopen("Gauss.out","w",stdout);
    cin>>n;
    m=n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
        cin>>b[i];
    }
    Gauss();
    if(No_solution)
    {
        //cout<<"No solutions\n"; 
        cout<<-1<<endl;
        return 0;
    }
    if(Many_solution)
    {
        //cout<<"Many solutions\n";
        cout<<0<<endl;
        return 0;

    }
    for(int i=1;i<=n;i++)
    {
        cout<<"x"<<i<<"=";
        if(res[i]) cout<<fixed<<setprecision(2)<<res[i]<<endl;
        else cout<<0<<endl;
    }
    return 0;
}
