/*
ID:galaxy_6
LANG:C++
TASK:wormhole
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=15;
struct edge{
        int x,y;
        bool operator<(edge a)
        {
                if(y==a.y)return x<a.x;
                return y<a.y;
        }
}e[maxn];
bool chos[maxn];
int n;
int ans;
bool go[maxn];
int _next[maxn];
int to[maxn];
bool check(int x)
{
        memset(go,0,sizeof go);
        while(_next[x]!=-1)
        {
                if(go[x])return true;
                go[x]=1;
                x=to[_next[x]];
        }
        return false;
}
void check_()
{
        for(int i=0;i<n;i++)
                if(check(i))
                {
                        ans++;
                        return;
                }
        return;
}
void dfs(int now)
{
        if(now>=n)
        {
                check_();
                return;
        }
        if(chos[now])return dfs(now+1);
        for(int i=now+1;i<n;i++)
                if(chos[i]==0)
                {
                        chos[i]=chos[now]=1;
                        to[i]=now;to[now]=i;
                        dfs(now+1);
                        chos[i]=chos[now]=0;
                }
        return;
}
int main()
{
       freopen("wormhole.in","r",stdin);
       freopen("wormhole.out","w",stdout);
       cin>>n;
       for(int i=0;i<n;i++) cin>>e[i].x>>e[i].y;
       sort(e,e+n);
       memset(_next,-1,sizeof _next);
       for(int i=0;i<n-1;i++) if(e[i].y==e[i+1].y) _next[i]=i+1;
       dfs(0);
       cout<<ans<<endl;
}
/*
        -0123-----------
       0|**             
       1|**             
       2|               
       3|               
        ----------------
*/
