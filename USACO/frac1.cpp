/*
ID:galaxy_6
LANG:C++
TASK:frac1
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n;
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
struct edge{
        int a,b;
        double ans;
        edge(){a=b=ans=0;}
        edge(int x,int y){a=x;b=y;ans=double(a)/b;}
        bool operator<(const edge x)const {
                return ans>x.ans;
        }
};
priority_queue<edge>q;
int main()
{
       freopen("frac1.in","r",stdin);
       freopen("frac1.out","w",stdout);
       cin>>n;
       cout<<0<<'/'<<1<<endl;
       for(int a=1;a<n;a++)
               for(int b=n;b>a;b--)
                       if(gcd(a,b)==1)
                               q.push(edge(a,b));
       while(!q.empty())
       {
               edge u=q.top();q.pop();
               cout<<u.a<<'/'<<u.b<<endl;
       }
       cout<<1<<'/'<<1<<endl;
       return 0;

}
