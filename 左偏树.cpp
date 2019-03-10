/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年03月10日 星期日 16时28分23秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=150010;
struct node{
        int dis,val,l,r,rt;
}tree[maxn];
int n,m,x,y;
inline int merge(int x,int y)
{
        if(!x or !y)return x|y;
        if(tree[x].val>tree[y].val)swap(x,y);
        tree[x].r=merge(tree[x].r,y);
        if(tree[tree[x].l].dis<tree[tree[x].r].dis)swap(tree[x].l,tree[x].r);
        tree[x].rt=tree[tree[x].l].rt=tree[tree[x].r].rt=x;
        tree[x].dis=tree[tree[x].r].dis+1;
        return x;
}
inline void pop(int x)
{
        tree[x].val=-1;
        tree[tree[x].l].rt=tree[x].l;
        tree[tree[x].r].rt=tree[x].r;
        tree[x].rt=merge(tree[x].l,tree[x].r);
}
int get(int x)
{
        return tree[x].rt==x?x:tree[x].rt=get(tree[x].rt);
}
int main()
{
        freopen("左偏树.in","r",stdin);
        freopen("左偏树.out","w",stdout);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
                cin>>tree[i].val,tree[i].rt=i;
        int opt,u,v;
        while(m--)
        {
                cin>>opt>>u;
                if(opt==1)
                {
                        cin>>v;
                        if(tree[u].val==-1 or tree[v].val==-1) continue;
                        if(get(u)==get(v))continue;
                        merge(tree[u].rt,tree[v].rt);
                }
                else
                {
                        if(tree[u].val==-1)cout<<-1<<endl;
                        else 
                        {
                                u=get(u);
                                cout<<tree[u].val<<endl;
                                pop(u);
                        }
                }
        }
}
