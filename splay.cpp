/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月18日 星期五 16时58分39秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cassert>
using namespace std;
struct Splay{
        enum{ maxn=100050};
        int ch[maxn][2],key[maxn],f[maxn],size[maxn],root,cnt[maxn],sz;
        Splay()
        {
                memset(ch,0,sizeof ch);
                memset(key,0,sizeof key);
                memset(f,0,sizeof f);
                memset(size,0,sizeof size);
                memset(cnt,0,sizeof cnt);
                sz=root=0;
        }
        inline void clear(int x) { ch[x][0]=ch[x][1]=f[x]=cnt[x]=key[x]=size[x]=0; }
        inline int from(int x){return ch[f[x]][1]==x;}
        inline void update(int x)
        {
                if(x)
                {
                        size[x]=cnt[x];
                        if(ch[x][0])size[x]+=size[ch[x][0]];
                        if(ch[x][1])size[x]+=size[ch[x][1]];
                }
        }
        inline void rotate(int x)
        {
                int y=f[x],z=f[y],c=from(x);
                ch[y][c]=ch[x][c^1];f[ch[y][c]]=y;
                f[y]=x;ch[x][c^1]=y;
                f[x]=z;
                if(z)
                        ch[z][ch[z][1]==y]=x;
                update(y);update(x);
        }
        inline void splay(int x)
        {
                for(int fa;(fa=f[x]);rotate(x))
                        if(f[fa])
                                rotate((from(x)==from(fa)?fa:x));
                root=x;
        }
        inline void insert(int v)
        {
                if(root==0){sz++;ch[sz][0]=ch[sz][1]=f[sz]=0;key[sz]=v;cnt[sz]=1;size[sz]=1;root=sz;return;}
                int now=root,fa=0;
                while(true)
                {
                        if(key[now]==v)
                        {
                                cnt[now]++;
                                update(now);
                                update(fa);
                                splay(now);
                                break;
                        }
                        fa=now;
                        now=ch[now][key[now]<v];
                        if(now==0)
                        {
                                sz++;
                                ch[sz][0]=0;ch[sz][1]=0;key[sz]=v;size[sz]=1;
                                cnt[sz]=1;f[sz]=fa;ch[fa][key[fa]<v]=sz;
                                update(fa);
                                splay(sz);
                                break;
                        }
                }
        }
        inline int find(int v)
        {
                int ans=0,now=root;
                while(true)
                {
                        if(v<key[now])
                                now=ch[now][0];
                        else 
                        {
                                ans+=(ch[now][0]?size[ch[now][0]]:0);
                                if(v==key[now]){splay(now);return ans+1;}
                                ans+=cnt[now];
                                now=ch[now][1];
                        }
                }
        }
        inline int findx(int x)
        {
                int now=root;
                while(true)
                {
                        if(ch[now][0] and x<=size[ch[now][0]])
                                now=ch[now][0];
                        else
                        {
                                int temp=(ch[now][0]?size[ch[now][0]]:0)+cnt[now];
                                if(x<=temp)
                                        return key[now];
                                x-=temp;now=ch[now][1];
                        }
                }
        }
        inline int pre()
        {
                int now=ch[root][0];
                while(ch[now][1])now=ch[now][1];
                return now;
        }
        inline int next()
        {
                int now=ch[root][1];
                while(ch[now][0])now=ch[now][0];
                return now;
        }
        inline void del(int x)
        {
                find(x);
                if(cnt[root]>1){cnt[root]--;update(root);return;}
                if(!ch[root][0] and !ch[root][1]){clear(root);root=0;return;}
                if(!ch[root][0]) { int oldroot=root; root=ch[root][1]; f[root]=0;clear(oldroot);return; }
                else if(!ch[root][1]){ int oldroot=root;root=ch[root][0];f[root]=0;clear(oldroot);return;}
                int l=pre(),oldroot=root;
                splay(l);
                f[ch[oldroot][1]]=root;
                ch[root][1]=ch[oldroot][1];
                clear(oldroot);
                update(root);
                return;
        }
        int sp_find(int v,int pr)
        {
                int now=root;
                int ans=(!pr?999999999:-9999999);
                while(now!=0)
                {
                        if(key[now]==v)
                        {
                                now=(pr?ch[now][0]:ch[now][1]);
                                continue;
                        }
                        if(v<key[now])
                        {
                                if(!pr and ans>key[now])ans=key[now];
                                now=ch[now][0];
                        }
                        else 
                        {
                                if(pr and ans<key[now])ans=key[now];
                                now=ch[now][1];
                        }
                }
                return ans;
        }
}s;
int n;
int main()
{
        freopen("splay.in","r",stdin);
        freopen("splay.out","w",stdout);
        cin>>n;
        while(n--)
        {
                int opt,x;
                cin>>opt>>x;
                if(opt==1)s.insert(x);
                if(opt==2)s.del(x);
                if(opt==3)cout<<s.find(x)<<endl;
                if(opt==4)cout<<s.findx(x)<<endl;
                if(opt>4) cout<<s.sp_find(x,(opt==5))<<endl;
        }
        return 0;
}
