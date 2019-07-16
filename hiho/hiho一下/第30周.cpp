/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月15日 星期六 15时16分02秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
const int mine=995;
const int not_mine=-1;
int T,n,a[maxn],b[maxn];
void check(int loc,int & p)
{
    if(p==0)b[loc]=not_mine;
    if(b[loc]==not_mine)return;
    if(b[loc]==mine){p--;return;}
    b[loc]++;
}
void dfs(int now)
{
}
int main()
{
        freopen("第30周.in","r",stdin);
        freopen("第30周.out","w",stdout);
        cin>>T;
        while(T--)
        {
            cin>>n;
            for(int i=1;i<=n;i++)
                cin>>a[i];
            for(int i=1;i<=n;i++)
                for(int j=i-1;j<=i+1;j++)
                    check(j,a[i]);
        }
}

