/******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月17日 星期日 14时28分34秒
*******************************/
#include<bits/stdc++.h>
using namespace std;
const int Maxn=5e5+10;
const int dim=2;
const int inf=0x3f3f3f3f;
struct node{
        int l,r,d[dim],maxn[dim],minn[dim];//maxn,minn表示当前节点能维护到的矩阵
        inline void maintain()
        {
                l=r=0;
                for(int i=0;i<dim;i++)
                        maxn[i]=minn[i]=d[i];
        }
}tree[2*Maxn];
int d,root,ans;
bool operator<(const node & a,const node & b) { return a.d[d]<b.d[d]; }
void push_up(int p)
{
        int son[2]={tree[p].l,tree[p].r};
        for(int i=0;i<2;i++)
        {
                if(!son[i])continue;
                for(int j=0;j<dim;j++)
                {
                        tree[p].maxn[j]=max(tree[son[i]].maxn[j],tree[p].maxn[j]);
                        tree[p].minn[j]=min(tree[son[i]].minn[j],tree[p].minn[j]);
                }
        }
}
int build(int l,int r,int now)
{
        int mid=(l+r)>>1;
        d=now;
        nth_element(tree+l,tree+mid,tree+r+1);
        tree[mid].maintain();
        if(l<mid)tree[mid].l=build(l,mid-1,(now+1)%dim);
        if(mid<r)tree[mid].r=build(mid+1,r,(now+1)%dim);
        push_up(mid);
        return mid;
}
void insert(int & o,int k,int now)
{
        if(o==0) { o=k; return; }
        if(tree[k].d[now]<tree[o].d[now])insert(tree[o].l,k,(now+1)%dim);
        else insert(tree[o].r,k,(now+1)%dim);
        push_up(o);
}
inline int dis_min(int o,int k)//曼哈顿距离
{
        int rst=0;
        for(int i=0;i<dim;i++)
        {
                if(tree[k].d[i]>tree[o].maxn[i])rst+=tree[k].d[i]-tree[o].maxn[i];
                if(tree[k].d[i]<tree[o].minn[i])rst+=tree[o].minn[i]-tree[k].d[i];
        }
        return rst;
}
inline int dis_max(int o,int k)
{
        int rst=0;
        for(int i=0;i<dim;i++)
                rst+=max(abs(tree[k].d[i]-tree[o].minn[i]),abs(tree[k].d[i]-tree[o].maxn[i]));
        return rst;
}
int ansmin,ansmax;
void query_min(int o,int k)
{
        int dm=abs(tree[o].d[0]-tree[k].d[0])+abs(tree[o].d[1]-tree[k].d[1]);
        if(o==k)dm=inf;
        if(dm<ansmin)ansmin=dm;
        int dl=tree[o].l?dis_min(tree[o].l,k):inf;
        int dr=tree[o].r?dis_min(tree[o].r,k):inf;
        if(dl<dr)
        {
                if(dl<ansmin)query_min(tree[o].l,k);
                if(dr<ansmin)query_min(tree[o].r,k);
        }
        else
        {
                if(dr<ansmin)query_min(tree[o].r,k);
                if(dl<ansmin)query_min(tree[o].l,k);
        }
}
void query_max(int o,int k)
{
        int dm=abs(tree[o].d[0]-tree[k].d[0])+abs(tree[o].d[1]-tree[k].d[1]);
        if(dm>ansmax)ansmax=dm;
        int dl=tree[o].l?dis_max(tree[o].l,k):0;
        int dr=tree[o].r?dis_max(tree[o].r,k):0;
        if(dl>dr)
        {
                if(dl>ansmax)query_max(tree[o].l,k);
                if(dr>ansmax)query_max(tree[o].r,k);
        }
        else
        {
                if(dr>ansmax)query_max(tree[o].r,k);
                if(dl>ansmax)query_max(tree[o].l,k);
        }
}
int main()
{
        ios::sync_with_stdio(false);
        int n;
        return 0;
}
