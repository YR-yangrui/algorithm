/*
ID:galaxy_6
LANG:C++
TASK:hamming
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100;
int n,b,d;
int ans[maxn],top;
int lowbit(int x){return (x & -x);}
int get_num(int a)
{
        int num=0;
        while(int t=lowbit(a))num++,a-=t;
        return num;
}
int check() {
        static int i=0;
        i++;
        for(int j=top;j;j--)
                if(get_num(i^ans[j])<d)
                        return check();
        return i;
}
int main()
{
       freopen("hamming.in","r",stdin);
       freopen("hamming.out","w",stdout);
       cin>>n>>b>>d;
       ans[1]=0;
       int i=1;
       for(top=2;top<=n;top++)
               ans[top]=check();
       for(int i=1;i<=n;i++)
       {
               cout<<ans[i];
               if(i%10==0 and i!=n)cout<<endl;
               else if(i!=n)cout<<' ';
       }
       cout<<endl;
       return 0;
}
