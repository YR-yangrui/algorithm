/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年08月23日 星期五 19时45分43秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
struct node{
    int ch[26];
    int len,fa;
    node(){memset(ch,0,sizeof ch);}
}d[maxn<<1];
int last=1,tot=1;
void add(int c)
{
    int p=last,np=last=++tot;
    d[np].len=d[p].len+1;
    for(;p and !d[p].ch[c];p=d[p].fa)d[p].ch[c]=np;
    if(!p)d[np].fa=1;
    else
    {
        int q=d[p].ch[c];
        if(d[q].len==d[p].len+1)d[np].fa=q;
        else
        {
            int nq=++tot;d[nq]=d[q];
            d[nq].len=d[p].len+1;
            d[q].fa=d[np].fa=nq;
            for(;p and d[p].ch[c]==q;p=d[p].fa)d[p].ch[c]=nq;
        }
    }
}
int main()
{
    freopen("后缀自动机.in","r",stdin);
    freopen("后缀自动机.out","w",stdout);
}
