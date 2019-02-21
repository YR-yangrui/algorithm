/*
ID:galaxy_6
LANG:C++
TASK:runround
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=20;
unsigned long long s,k;
bool used[maxn];
int a[maxn],n,q;
bool check()
{
        memset(used,0,sizeof used); q=1;
        k=s;
        int i;
        for(i=1;k;i++) a[i]=k%10,k/=10;
        i--; n=i;
        for(int j=1;j<=n;j++) {if(used[a[j]])return false;used[a[j]]=1;}
        memset(used,0,sizeof used);
        for(int j=1;j<=i;j++,i--) swap(a[i],a[j]);
        used[1]=1;
        int t=1;t=(t+a[t])%n;
        while(true)
        {
                q++;
                used[t]=1;
                t=(t+a[t])%n;
                if(t==0)t=n;
                if(q==n and t==1)return true;
                if(used[t])return false;
        }
}
int main()
{
       freopen("runround.in","r",stdin);
       freopen("runround.out","w",stdout);
       cin>>s;
       s++;
       while(!check()) s++;
       cout<<s<<endl;
       return 0;
}
