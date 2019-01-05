/*
ID:galaxy_6
LANG:C++
TASK:combo
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[3],b[3];
void to_next(int & x) { x++; if(x>n)x=1; return; }
void to_last(int & x) { x--; if(x<1)x=n; return; }
struct edge{
        int a,b,c;
        bool operator==(edge x){
                if(a==x.a and b==x.b and c==x.c)return true;
                return false;
        }
}q[300];
bool cmp(edge x,edge y)
{
        if(x.a==y.a)
        {
                if(x.b==y.b)
                {
                        return x.c<y.c;
                }
                return x.b<y.b;
        }
        return x.a<y.a;
}
int num;
void add(int * a)
{
       for(int i=a[0],gi=0;gi<5;gi++,to_next(i))
               for(int j=a[1],gj=0;gj<5;gj++,to_next(j))
                       for(int k=a[2],gk=0;gk<5;gk++,to_next(k))
                       {
/*                               cerr<<i<<' '<<j<<' '<<k<<endl;*/
                               q[++num].a=i;
                               q[num].b=j;
                               q[num].c=k;
                       }
       return;
}
int main()
{
       freopen("combo.in","r",stdin);
       freopen("combo.out","w",stdout);
       cin>>n;
       for(int i=0;i<=2;i++)cin>>a[i];
       for(int i=0;i<=2;i++)cin>>b[i];
       for(int i=0;i<=2;i++)
               for(int j=1;j<=2;j++)
                       to_last(a[i]),to_last(b[i]);
       add(a);add(b);
       sort(q+1,q+num+1,cmp);
       int ans=unique(q+1,q+num+1)-(q+1);
       cout<<ans<<endl;
}
