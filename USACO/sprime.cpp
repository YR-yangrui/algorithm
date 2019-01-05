/*
ID:galaxy_6
LANG:C++
TASK:sprime
*/
#include<iostream>
#include<cstdio>
using namespace std;
int p[6]={0,1,3,5,7,9};
int n;
bool is_prime(long long k)
{
        if(k==1)return false;
        if(k==2 or k==3)return true;
        if(k%6!=1 and k%6!=5)return false;
        for(int i=5;i*i <= k;i+=6)
                if(k%i==0 or k%(i+2)==0)return false;
        return true;
}
void dfs(long long res,int k)
{
        if(!is_prime(res))return;
        if(k==n){cout<<res<<endl;return;}
        for(int i=1;i<=5;i++)
                dfs(res*10+p[i],k+1);
        return;
}
int main()
{
       freopen("sprime.in","r",stdin);
       freopen("sprime.out","w",stdout);
       cin>>n;
       dfs(2,1); dfs(3,1); dfs(5,1); dfs(7,1);
       return 0;
}
