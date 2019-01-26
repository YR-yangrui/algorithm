/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月25日 星期五 21时24分21秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,l,t,cnt,st,dis[maxn];
struct ants{
        long long dir,id,loc;
}m[maxn];
int main()
{
        freopen("Ants_on_a_circle.in","r",stdin);
        freopen("Ants_on_a_circle.out","w",stdout);
        cin>>n>>l>>t;
        for(int i=1;i<=n;i++) cin>>m[i].loc>>m[i].dir,m[i].id=i;
        for(int i=1;i<=n;i++)m[i].dir==2?m[i].dir=-1:m[i].dir=1;
        st=m[1].loc;
        for(int i=1;i<=n;i++) 
        {
                m[i].loc=(m[i].loc+m[i].dir*t);
                if(m[i].loc<0)m[i].loc++;
                m[i].loc%=l;
                if(m[i].loc>st)cnt++; else if(m[i].loc<=st) cnt--;
                dis[i]=(m[i].loc+l)%l;
        }
        sort(dis+1,dis+1+n);
        cnt=(cnt+n)%n;
        for(int i=1;i<=n;i++)
        {
                cout<<dis[cnt]<<endl;
                if(++cnt>n)cnt-=n;
        }
        return 0;
}
