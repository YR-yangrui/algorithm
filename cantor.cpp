#include<iostream>
using namespace std;
const int mod=998244353;
const int maxn=1e6+10;
long long FAC[maxn];
long long cantor(int *a,int n)
{
    long long x=0;
    for(int i=0;i<n;i++)
    {
        int smaller=0;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])smaller++;
        }
        x+=FAC[n-i-1]*smaller;
        x%=mod;
    }
    x++;
    x%=mod;
    return x;
}
int main()
{
    freopen("cantor.in","r",stdin);
    freopen("cantor.out","w",stdout);
    int* a;
    int n;
    cin>>n;
    FAC[1]=1;
    for(int i=2;i<=n;i++)
        FAC[i]=(long long)FAC[i-1]*i%mod;
    a=new int [n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<cantor(a,n);
    return 0;
}
