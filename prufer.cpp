/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月16日 星期一 19时21分42秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
const int maxn=1e6+10;
int n,prufer[maxn],head[maxn],cnt,du[maxn];
struct edge{
    int from,to,next;
    edge(int c=0,int a=0,int b=0):from(c),to(a),next(b){}
}e[maxn<<1];
void add(int u,int v)
{
    e[++cnt]=edge(u,v,head[u]);
    head[u]=cnt;
}
int vis[maxn],used[maxn];
set<int>S;
void clear()
{
    memset(vis,0,sizeof vis);
    memset(used,0,sizeof used);
    memset(prufer,0,sizeof prufer);
    memset(head,0,sizeof head);
    S.clear();
    cnt=0;
}
void GetPrufer()
{
    /*
     * S表示叶子节点
     */
    clear();
    cin>>n;
    int u,v;
    for(int i=1;i<n;i++)
    {
        cin>>u>>v;
        add(u,v),add(v,u);
        du[u]++,du[v]++;
    }
    for(int i=1;i<=n;i++)
        if(du[i]==1)
        {
            S.insert(i);
            vis[i]=1;
        }
    set<int>::iterator it;
    int id=0;
    while(id<=n-3)
    {
        int u=(*(it=S.begin()));
        S.erase(u);
        for(int i=head[u];i;i=e[i].next)
            if(!vis[e[i].to])
            {
                du[e[i].to]--;
                prufer[++id]=e[i].to;
                if(du[e[i].to]==1)
                {
                    S.insert(e[i].to);
                    vis[e[i].to]=1;
                }
            }
    }
    return;
}
void DecodePrufer()
{
    /*
     * S表示最小没有出现在prufer数列中的数
     */
    clear();
    cin>>n;
    for(int i=1;i<=n-2;i++)
    {
        cin>>prufer[i];
        vis[prufer[i]]++;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
            S.insert(i);
    set<int>::iterator it;
    for(int i=1;i<=n-2;i++)
    {
        int v=(*(it=S.begin())),u=prufer[i];
        add(u,v); add(v,u);
        S.erase(v);
        vis[u]--;
        if(!vis[u] and !used[u])
        {
            S.insert(u);
        }
    }
    it=S.begin();
    int u=*it,v=*(++it);
    add(u,v); add(v,u);
    return;
}
