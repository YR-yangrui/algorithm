/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月05日 星期六 17时53分58秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
const int maxn=1005;
int link[maxn],usex[maxn],usey[maxn],cx[maxn],cy[maxn],w[maxn][maxn];
int n,ans,m;
bool find(int x)
{
        usex[x]=1;
        for(int i=1;i<=m;i++)
                if(usey[i]==0 and cx[x]+cy[i]==w[x][i])
                {
                        usey[i]=true;
                        if(link[i]==false or find(link[i]))
                        {
                                link[i]=x;
                                return true;
                        }
                }
        return false;
}
int km()
{
        for(int i=1;i<=n;i++)
        {
                while(true)
                {
                        int d=INF;
                        memset(usex,0,sizeof usex);
                        memset(usey,0,sizeof usey);
                        if(find(i))break;
                        for(int j=1;j<=n;j++)
                                if(usex[j])
                                        for(int k=1;k<=m;k++)
                                                if(!usey[k])
                                                        d=min(d,cx[j]+cy[k]-w[j][k]);
                        if(d==INF)return -1;
                        for(int j=1;j<=n;j++)
                                if(usex[j])cx[j]-=d;
                        for(int j=1;j<=m;j++)
                                if(usey[j])cy[j]+=d;
                }
        }
        ans=0;
        for(int i=1;i<=m;i++)
                ans+=w[link[i]][i];
        return ans;
}
int main()
{
       freopen("二分图最佳匹配.in","r",stdin);
       freopen("二分图最佳匹配.out","w",stdout);
        while(cin>>n>>m)
        {
                memset(cy,0,sizeof cy);
                memset(w,0,sizeof w);
                memset(cx,0,sizeof cx);
                for(int i=1;i<=n;i++)
                {
                        int d=0;
                        for(int j=1;j<=n;j++)
                        {
                                cin>>w[i][j];
                                d=max(d,w[i][j]);
                        }
                        cx[i]=d;
                }
                memset(link,0,sizeof link);
                cout<<km()<<endl;
        }
        return 0;
}
