#include<bits/stdc++.h>
using namespace std;
template<class T>
void read(T&res)
{
	char ch=getchar();
	int q=1;
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')
			q=-1;
		ch=getchar();
	}
	res=(ch^48);
	while((ch=getchar())>='0' and ch<='9')
		res=(res<<1)+(res<<3)+(ch^48);
	res*=q;
	return;
}
//{{{Kosaraju O(n+m)
struct kosaraju{
	static const int maxn=1e3+10;
	int vis[maxn],num,stk[maxn];
	int n,m;
	bool mp[maxn][maxn];
	void get()
	{
		read(n);read(m);
		static int u,v;
		for(int i=1;i<=m;i++)
		{
			read(u),read(v);
			mp[u][v]=1;
		}
	}
	void dfs1(int x)
	{
		vis[x]=1;
		for(int i=1;i<=n;i++)
			if(!vis[x] and mp[x][i])
				dfs1(i);
		stk[++num]=x;
	}
	void dfs2(int x)
	{
		vis[x]=num;
		for(int i=1;i<=n;i++)
			if(!vis[i] and mp[i][x])
				dfs2(i);
	}
	int solve()
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])dfs1(i);
		memset(vis,0,sizeof vis);
		num=0;
		for(int i=n;i>=1;i--)
			if(!vis[stk[i]])
			{
				num++;
				dfs2(stk[i]);
			}
		return num;
	}
};
//}}}
namespace edge{
	const int Maxn=1e6+10;
	int head[Maxn],cnt;
	struct edge{
		int to,next,w;
	}e[Maxn];
	void add(const int & u,const int & v,const int & w)
	{
		e[++cnt].to=v;
		e[cnt].w=w;
		e[cnt].next=head[u];
		head[u]=cnt;
	}
}
//Tarjan
using namespace edge;
int col,dfn[Maxn],low[Maxn],st[Maxn],co[Maxn],top,num;
void Tarjan(int u)
{
        dfn[u]=low[u]=++num;
        st[++top]=u;
        for(int i=head[u];i;i=e[i].next)
        {
                int v=e[i].to;
                if(!dfn[v])
                {
                        Tarjan(v);
                        low[u]=min(low[u],low[v]);
                }
                else if(!co[v])
                        low[u]=min(low[u],dfn[v]);
        }
        if(low[u]==dfn[u])
        {
                co[u]=++col;
                while(st[top]!=u)
                {
                        co[st[top]]=col;
                        --top;
                }
                --top;
        }
}
int main()
{
	kosaraju t;
	t.get();
	cout<<t.solve()<<endl;
}
