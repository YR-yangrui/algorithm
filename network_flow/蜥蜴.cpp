/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月15日 星期二 08时14分06秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=530;
const int INF=9999;
const int k=500;
const int s=245;
const int t=233;
struct edge{
        int a,b;
        edge():a(0),b(0){}
        edge(int x,int y):a(x),b(y){}
};
struct eg{
        edge to;
        int next;
}e[maxn*maxn*5];
eg st;
int head[maxn][maxn],cnt;
int w[maxn*maxn*5];
int r,c,d;
void add(edge u,edge v,int f)
{
        e[cnt].to=v;
        e[cnt].next=head[u.a][u.b];
        head[u.a][u.b]=cnt;
        w[cnt++]=f;
}
double jl(int a,int b,int x,int y) { return sqrt(double(a-x)*double(a-x)+double(b-y)*double(b-y)); }
void connect(int a,int b,int di,int dd)
{
        add(edge(a+k,b+k),edge(a,b),di);
        add(edge(a,b),edge(a+k,b+k),0);
        for(int i=1;i<=r;i++)
                for(int j=1;j<=c;j++)
                        if(jl(a,b,i,j)<=d)
                        {
                                add(edge(i,j),edge(a+k,b+k),dd);
                                add(edge(a+k,b+k),edge(i,j),0);
                        }
}
int depth[maxn][maxn];
bool bfs(eg st)
{
        memset(depth,-1,sizeof depth);depth[st.to.a][st.to.b]=0;
        queue<eg>q;q.push(st);
        bool ok=0;
        while(!q.empty())
        {
                eg u=q.front();q.pop();
                for(int i=head[u.to.a][u.to.b];i!=-1;i=e[i].next)
                                if(depth[e[i].to.a][e[i].to.b]==-1 and w[i])
                                {
                                        depth[e[i].to.a][e[i].to.b]=depth[u.to.a][u.to.b]+1;
                                        q.push(e[i]);
                                }
        }
        return (depth[t][t]>=0);
}
int dfs(edge u,int dist)
{
        if(u.a==t and u.b==t)
        {
#ifdef find1
                cout<<"-----------"<<dist<<"--------------------\n";
#endif
                return dist;
        }
        for(int i=head[u.a][u.b];i!=-1;i=e[i].next)
        {
                if(depth[e[i].to.a][e[i].to.b]==depth[u.a][u.b]+1 and w[i]>0)
                {
                        int de=dfs(e[i].to,min(dist,w[i]));
                        if(de>0)
                        {
#ifdef find1
                                cout<<u.a<<' '<<u.b<<' '<<e[i].to.a<<' '<<e[i].to.b<<' '<<w[i]<<' '<<w[i^1]<<' '<<de<<endl;
#endif
                                w[i]-=de;
                                w[i^1]+=de;
                                return de;
                        }
                }
        }
        return 0;
}
int ans;
void dinic()
{
        while(bfs(st))
                while(int de=dfs(edge(s,s),INF))
                        ans-=de;
        cout<<ans<<endl;
        return;
}
int main()
{
       //freopen("蜥蜴.in","r",stdin);
       //freopen("蜥蜴.out","w",stdout);
       st.to.a=s;st.to.b=s;
       memset(head,-1,sizeof head);
       cin>>r>>c>>d;
       memset(w,127,sizeof w);
       while(cin.get()!='\n');
       for(int i=1;i<=r;i++)
       {
               for(int j=1;j<=c;j++)
               {
                       int t=cin.get()-'0';
                       if(t>0)
                       {
                               connect(i,j,t,INF);
                       }
               }
               cin.get();
       }
       char ch;
       for(int i=1;i<=r;i++)
               for(int j=1;j<=c;j++)
               {
                       cin>>ch;
                       if(ch=='L')
                       {
                               add(edge(s,s),edge(i+k,j+k),1);
                               add(edge(i+k,j+k),edge(s,s),0);
                               ans++;
                       }
               }
       for(int i=0;i<=r+1;i++)
       {
               add(edge(i,0),edge(t,t),INF);
               add(edge(t,t),edge(i,0),0);
               connect(i,0,INF,INF);
               add(edge(i,c+1),edge(t,t),INF);
               add(edge(t,t),edge(i,c+1),0);
               connect(i,c+1,INF,INF);
       }
       for(int i=1;i<=c;i++)
       {
               add(edge(0,i),edge(t,t),INF);
               add(edge(t,t),edge(0,i),0);
               connect(0,i,INF,INF);
               add(edge(r+1,i),edge(t,t),INF);
               add(edge(t,t),edge(r+1,i),0);
               connect(r+1,i,INF,INF);
       }
       dinic();
       return 0;
}
