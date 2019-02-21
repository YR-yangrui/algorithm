/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月12日 星期二 16时37分39秒
*******************************/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=1e5+10;
const int N=1e5+10;
map<int,int>mp;
vector<int>L[maxn],R[maxn];
int n,s[maxn],gs,last,T[maxn],m[maxn],re[maxn],opt,t,l,r,ans,tree[maxn][2];
void add(int x,int v,int q=0) { while(x<=N) { tree[x][q]+=v; x+=x&-x; } return; }
int sum(int x,int q=0) { int ans=0; while(x) { ans+=tree[x][q]; x-=x&-x; } return ans; }
int main()
{
        freopen("p1034.in","r",stdin);
        freopen("p1034.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i]>>m[i]>>re[i];
        for(int i=1;i<=n;i++) T[i]=(m[i]+re[i]-1)/re[i];
        cin>>opt;
        for(int i=1;i<=opt;i++)
        {
                cin>>t>>l>>r;
                L[l].push_back(t);
                R[r+1].push_back(t);
        }
        vector<int>::iterator vit;
        map<int,int>::iterator mit;
        mp[0]++;
        for(int i=1;i<=n;i++)
        {
                for(vit=L[i].begin();vit!=L[i].end();vit++)
                {
                        mp[(*vit)]++;
                        mit=mp.lower_bound((*vit));
                        mit--;
                        add((*vit)-(mit->first),1);
                        add((*vit)-(mit->first),(*vit)-(mit->first),1);
                }
                for(vit=R[i].begin();vit!=R[i].end();vit++)
                {
                        mp[*vit]--;
                        if(mp[(*vit)]==0)mp.erase((*vit));
                        mit=mp.lower_bound(*vit);
                        mit--;
                        add(*vit-mit->first,-1);
                        add((*vit)-(mit->first),(mit->first)-(*vit),1);
                }
                gs=sum(N)-sum(T[i]);
                last=sum(T[i],1);
                ans+=last*re[i]+gs*m[i];
                mit=mp.find(0);
                mit++;
                if(mit->second>=T[i])continue;
                ans+=min(s[i],m[i]-mit->second*re[i]);
        }
        cout<<ans<<endl;
        return 0;
}
