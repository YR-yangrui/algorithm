/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月06日 星期五 17时29分33秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=2e5+10;
struct Node{
    int ch[26],len,fa;
    Node(){memset(ch,0,sizeof ch);}
}d[maxn<<2];
int last=1,tot=1;
int vis[maxn];
int n,ans[maxn];
string s[maxn];
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
void update(int x,int y)
{
    for(;x and vis[x]!=y and vis[x]!=-1;x=d[x].fa)
        if(vis[x]!=0)vis[x]=-1;
        else vis[x]=y;
}
int main()
{
    freopen("generalized_sam.in","r",stdin);
    freopen("generalized_sam.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]; last=1;
        for(int j=0;j<s[i].size();j++)
            add(s[i][j]-'a');
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0,x=1;j<s[i].size();j++)
            update(x=d[x].ch[s[i][j]-'a'],i);
    }
    for(int i=1;i<=tot;i++)
        if(vis[i]!=-1)
            ans[vis[i]]+=d[i].len-d[d[i].fa].len;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<endl;
    return 0;
}
