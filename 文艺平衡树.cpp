/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月27日 星期日 14时08分49秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x8fffffff;
struct Splay{
        enum{maxn=1000010};
        int sz,root,size[maxn],f[maxn],ch[maxn][2],lazy[maxn],key[maxn],data[maxn];
        Splay()
        {
                memset(key,0,sizeof key);
                memset(size,0,sizeof size);
                memset(f,0,sizeof f);
                memset(ch,0,sizeof ch);
                sz=root=0;
        }
        inline int from(int x) { return (ch[f[x]][1]==x); }
        inline void pushdown(int x)
        {
                if(x and lazy[x])
                {
                        swap(ch[x][0],ch[x][1]);
                        lazy[ch[x][0]]^=1;
                        lazy[ch[x][1]]^=1;
                        lazy[x]=0;
                }
        }
        inline void update(int x)
        {
                if(x)
                {
                        size[x]=1;
                        if(ch[x][0])size[x]+=size[ch[x][0]];
                        if(ch[x][1])size[x]+=size[ch[x][1]];
                }
        }
        inline void rotate(int x)
        {
                int y=f[x],z=f[y],c=from(x);
                pushdown(y),pushdown(x);
                f[y]=x;ch[y][c]=ch[x][c^1];f[ch[y][c]]=y;
                f[x]=z;ch[x][c^1]=y;
                if(z) ch[z][ch[z][1]==y]=x;
                update(y);update(x);
        }
        inline void splay(int x,int to=0)
        {
                for(int fa;(fa=f[x])!=to;rotate(x))
                {
                        if(f[fa]!=to)
                                rotate((from(x)==from(fa)?fa:x));
                }
                if(!to)root=x;
        }
        int rnk(int x)
        {
                int now=root;
                while(true)
                {
                        pushdown(now);
                        if(x<=size[ch[now][0]])now=ch[now][0];
                        else
                        {
                                x-=size[ch[now][0]]+1;
                                if(!x)return now;
                                now=ch[now][1];
                        }
                }
        }
        int build_tree(int l,int r,int fa)
        {
                if(l>r){return 0;}
                int mid=(l+r)>>1;
                int now=++sz;
                key[now]=data[mid];f[now]=fa;lazy[now]=0;
                ch[now][0]=build_tree(l,mid-1,now);
                ch[now][1]=build_tree(mid+1,r,now);
                update(now);
                return now;
        }
        inline void re(int l,int r)
        {
                l=rnk(l);r=rnk(r+2);
                splay(l,0);splay(r,l);
                pushdown(root);
                lazy[ch[ch[root][1]][0]]^=1;
        }
        void write(int now)
        {
                pushdown(now);
                if(ch[now][0])write(ch[now][0]);
                if(key[now]!=-inf and key[now]!=inf)cout<<key[now]<<' ';
                if(key[ch[now][1]])write(ch[now][1]);
        }
}s;
int main()
{
        freopen("文艺平衡树.in","r",stdin);
        freopen("文艺平衡树.out","w",stdout);
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)s.data[i+1]=i;
        s.data[1]=-inf;s.data[n+2]=inf;
        s.root=s.build_tree(1,n+2,0);
        while(m--)
        {
                int L,R;
                cin>>L>>R;
                s.re(L,R);
        }
        s.write(s.root);
        return 0;
}
