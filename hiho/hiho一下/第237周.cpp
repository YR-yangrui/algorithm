/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月15日 星期二 14时25分39秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int T,n;
int f[maxn],w[maxn],tot;
int sum[maxn],ans1,ans2,cnt[maxn],cnt2[maxn];
struct edge{
        int to,next;
}e[maxn];
int head[maxn],ct,s;
void add(int u,int v)
{
        e[++ct].next=head[u];
        e[ct].to=v;
        head[u]=ct;
}
void dfs(int u)
{
        for(int i=head[u];i!=-1;i=e[i].next)
        {
                dfs(e[i].to);
                sum[u]+=sum[e[i].to];
                cnt[u]+=cnt[e[i].to];
        }
        sum[u]+=w[u];
        if(sum[u]==tot/3)cnt[u]++;
}
void dfs2(int u)
{
        cnt2[u]=cnt2[f[u]]+(u!=0&&(sum[f[u]]==s));
        for(int i=head[u];i!=-1;i=e[i].next) dfs2(e[i].to);
}
int main()
{
       freopen("237.in","r",stdin);
       freopen("237.out","w",stdout);
       cin>>T;
       while(T--)
       {
               memset(head,-1,sizeof head);
               memset(sum,0,sizeof sum);
               memset(cnt,0,sizeof cnt);
               memset(cnt2,0,sizeof cnt2);
               tot=ct=ans1=ans2=0;
               cin>>n;
               for(int i=1;i<=n;i++) 
               {
                       cin>>w[i]>>f[i];
                       tot+=w[i];
                       add(f[i],i);
               }
               if(tot%3!=0){cout<<0<<endl;continue;}
               s=tot/3;
               dfs(0);dfs2(0);
               for(int i=1;i<=n;i++)
                       if(sum[i]==s)ans1+=cnt[0]-cnt[i]-cnt2[i];
                       else if(sum[i]==s*2)ans2+=cnt[i]-(sum[i]==s);
               cout<<(ans1/2+ans2)<<endl;
       }
       return 0;
}
