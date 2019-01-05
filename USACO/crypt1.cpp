/*
ID:galaxy_6
LANG:C++
TASK:crypt1
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
bool have[15];
bool check2(int k)
{
        if(k>=1000)return false;
        while(k)
        {
                if(!have[k%10])return false;
                k/=10;
        }
        return true;
}
bool check(int a,int b,int c,int f,int g)
{
        int k=a*100+b*10+c,p=f*10+g;
        if(!check2(k*f))return false;
        if(!check2(k*g))return false;
        k=k*p;
        if(k>=10000)return false;
        while(k)
        {
                if(!have[k%10])return false;
                k/=10;
        }
        return true;
}
int ans;
int main()
{
        freopen("crypt1.in","r",stdin);
        freopen("crypt1.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                int k;
                cin>>k;
                have[k]=1;
        }
        for(int i=1;i<=9;i++)
                for(int j=1;j<=9;j++)
                        for(int k=1;k<=9;k++)
                                for(int h=1;h<=9;h++)
                                        for(int u=1;u<=9;u++)
                                                if(have[i] and have[j] and have[k] and have[h] and have[u] and check(i,j,k,h,u))
                                                        ans++;
        cout<<ans<<endl;
        return 0;
}
