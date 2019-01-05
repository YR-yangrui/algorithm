/*
ID:galaxy_6
LANG:C++
TASK:milk2
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5005;
int n;
struct edge{
        int st,ed;
}e[maxn];
bool cmp(edge x,edge y)
{
        if(x.st==y.st)return x.ed<y.ed;
        return x.st<y.st;
}
int maxd,mind;
int main()
{
        freopen("milk2.in","r",stdin);
        freopen("milk2.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++)cin>>e[i].st>>e[i].ed;
        sort(e+1,e+n+1,cmp);
        int now=e[1].st,work=0;
        for(int i=1;i<=n;i++)
        {
                if(e[i].ed<now)continue;
                if(e[i].st>now)
                {
                        mind=max(mind,e[i].st-now);
                        work=e[i].ed-e[i].st;
                        maxd=max(maxd,work);
                }
                else 
                {
                        work+=e[i].ed-now;

                        maxd=max(maxd,work);
                }
                now=e[i].ed;
        }
        cout<<maxd<<' '<<mind<<endl;
        return 0;
}
