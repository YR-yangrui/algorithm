/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月22日 星期日 19时21分35秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

const int maxn=2e5+10;
int ans[maxn],n,head[maxn],cnt,tot=1,ch[maxn][26],now,match[maxn],fail[maxn],size[maxn];
string s,t;
queue<int>que;

struct edge{
    int to,next;
}e[maxn<<1];

void add(int u,int v)
{
    e[++cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}

void dfs(int now)
{
    for(int i=head[now];i;i=e[i].next)
    {
        dfs(e[i].to);
        size[now]+=size[e[i].to];
    }
}

int main()
{
    //freopen("p3796.in","r",stdin);
    //freopen("p3796.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        now=1;
        for(int j=0;j<(int)s.size();j++)
        {
            int c=s[j]-'a';
            if(!ch[now][c]) ch[now][c]=++tot;
            now=ch[now][c];
        }
        match[i]=now;
    }
    for(int i=0;i<26;i++) ch[0][i]=1;
    que.push(1);
    while(!que.empty())
    {
        int x=que.front(); que.pop();
        for(int i=0;i<26;i++)
            if(ch[x][i])
            {
                fail[ch[x][i]]=ch[fail[x]][i];
                que.push(ch[x][i]);
            }
            else ch[x][i]=ch[fail[x]][i];
    }
    cin>>s;
    now=1;
    for(int i=0;i<(int)s.size();i++)
    {
        int c=s[i]-'a';
        now=ch[now][c];
        size[now]++;
    }
    for(int i=2;i<=tot;i++)
        add(fail[i],i);
    dfs(1);
    for(int i=1;i<=n;i++)
        cout<<size[match[i]]<<endl;
    return 0;
}
