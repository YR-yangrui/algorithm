/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年05月25日 星期六 14时12分34秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int maxn=1e5+10;
int n;
struct queen{
    long long x,y,hx,hy;
    bool operator<(const queen & com)const
    {
        if(x==com.x)return y<com.y;
        return x<com.x;
    }
}e[maxn];
bool cmp(const queen & x,const queen & y) { return x.y<y.y; }
long long ans,cnt,ha;
int x[maxn<<1],mx,my,y[maxn<<1];
map<long long,int>xx,yy;
int main()
{
        freopen("第255周.in","r",stdin);
        freopen("第255周.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>e[i].x>>e[i].y;
        sort(e+1,e+n+1);
        ha=-1;
        for(int i=1;i<=n;i++)
            if(ha==e[i].x)
                e[i].hx=cnt;
            else 
                ha=e[i].x,e[i].hx=++cnt;
        mx=cnt;
        sort(e+1,e+n+1,cmp); cnt=0;
        ha=-1;
        for(int i=1;i<=n;i++)
            if(ha==e[i].y)
                e[i].hy=cnt;
            else 
                ha=e[i].y,e[i].hy=++cnt;
        my=cnt;
        for(int i=1;i<=n;i++)
            x[e[i].hx]++,y[e[i].hy]++;
        for(int i=1;i<=mx;i++)
            ans+=(x[i]-1)*x[i]/2;
        for(int i=1;i<=my;i++)
            ans+=(y[i]-1)*y[i]/2;
        //memset(x,0,sizeof x); memset(y,0,sizeof y);
        for(int i=1;i<=n;i++)
        {
            xx[e[i].x-e[i].y]++;
            yy[e[i].x+e[i].y]++;
        }
        map<long long,int>::iterator it;
        for(it=xx.begin();it!=xx.end();it++)
            ans+=it->second*(it->second-1)/2;
        for(it=yy.begin();it!=yy.end();it++)
            ans+=it->second*(it->second-1)/2;
        cout<<ans<<endl;
        return 0;
}
