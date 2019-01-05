/*
ID:galaxy_6
LANG:C++
TASK:barn1
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1000;
int m,s,n;
int np[maxn],loc[maxn];
struct _board{
        int len,left,right;
        _board(int a,int b,int c):len(a),left(b),right(c){}
        _board(){len=left=right=0;}
};
vector<_board>V;
int main()
{
        freopen("barn1.in","r",stdin);
        freopen("barn1.out","w",stdout);
        cin>>m>>s>>n;
        for(int i=1;i<=n;i++)cin>>loc[i];
        sort(loc+1,loc+n+1);
        for(int i=1;i<=n;i++)
                V.push_back(_board(1,loc[i],loc[i]));
        while(V.size()>m)
        {
                int k,mind=0x7fffffff;
                for(int i=1;i<V.size();i++)
                {
                        int mm=(V[i].left-V[i-1].right-1);
                        if(mm<mind){k=i;mind=mm;}
                }
                V[k].len=V[k].left-V[k-1].right-1+V[k].len+V[k-1].len;
                V[k].left=V[k-1].left;
                V.erase(V.begin()+k-1);
        }
        int ans=0;
        for(int i=0;i<V.size();i++)
                ans+=V[i].len;
                //ans=min(ans,V[i].len);
        cout<<ans<<endl;
        return 0;
}
