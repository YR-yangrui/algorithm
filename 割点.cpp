/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019/08/05 18:39:19
*******************************/
#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=20005;
const int maxm=100010;
int n,m,x,y,head[maxn],cnt,low[maxn],dfn[maxn],tot,root=1;
struct edge{
    int to,next;
}e[maxm*2];
void add(int u,int v)
{
    e[++cnt].next=head[u];
    e[cnt].to=v;
    head[u]=cnt;
}
int son;
set<int>S;
void Tarjan(int u,int fa)
{
    if(u==root)
        son=0;
    dfn[u]=low[u]=++tot;
    for(int i=head[u];i;i=e[i].next)
    {
        if(dfn[e[i].to]==0)
        {
            if(u==root)
                son++;
            Tarjan(e[i].to,u);
            low[u]=min(low[u],low[e[i].to]);
            if(u!=fa and low[e[i].to]>=dfn[u])
                S.insert(u);
        }
        low[u]=min(low[u],dfn[e[i].to]);
    }
    if(u==root and son>1)
        S.insert(u);
}
int main()
{
    freopen("p3388.in","r",stdin);
    freopen("p3388.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    for(int i=1;i<=n;i++)
        if(dfn[i]==0)Tarjan(i,i);
    cout<<S.size()<<endl;
    for(set<int>::iterator it=S.begin();it!=S.end();it++)
        cout<<*it<<' ';
    cout<<endl;
    return 0;
}
