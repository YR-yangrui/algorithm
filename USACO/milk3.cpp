/*
ID:galaxy_6
LANG:C++
TASK:milk3
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=25;
bool co[maxn];
struct edge{
        int a,b,c,la,lb,lc;
        edge(){a=b=c=la=lb=lc=0;}
        friend bool operator<(edge x,edge y){if(y.c==x.c)return x.a<y.a;return x.c<y.c;}
        friend bool operator>(edge x,edge y){if(y.c==x.c)return x.a>y.a;return x.c>y.c;}
        friend bool operator==(edge x,edge y)
        {
                if(x.a==y.a and y.b==x.b and x.c==y.c)return true;
                return false;
        }
}st;
set<edge>S;
edge move(edge x,int k)
{
        if(k==1)// a to b
        {
                if(x.b==x.lb)return x;
                int could=x.lb-x.b;
                if(could>=x.a){x.b+=x.a;x.a=0;return x;}
                x.b=x.lb;
                x.a-=could;
        }
        else if(k==2)//a to c
        {
                if(x.c==x.lc)return x;
                int could=x.lc-x.c;
                if(could>=x.a){x.c+=x.a;x.a=0;return x;}
                x.c=x.lc;
                x.a-=could;
        }
        else if(k==3)// b to a
        {
                if(x.a==x.la)return x;
                int could=x.la-x.a;
                if(could>=x.b){x.a+=x.b;x.b=0;return x;}
                x.a=x.la;
                x.b-=could;
        }
        else if(k==4)//b to c
        {
                if(x.c==x.lc)return x;
                int could=x.lc-x.c;
                if(could>=x.b){x.c+=x.b;x.b=0;return x;}
                x.c=x.lc;
                x.b-=could;
        }
        if(k==5)// c to b
        {
                if(x.b==x.lb)return x;
                int could=x.lb-x.b;
                if(could>=x.c){x.b+=x.c;x.c=0;return x;}
                x.b=x.lb;
                x.c-=could;
        }
        else if(k==6)//c to a
        {
                if(x.a==x.la)return x;
                int could=x.la-x.a;
                if(could>=x.c){x.a+=x.c;x.c=0;return x;}
                x.a=x.la;
                x.c-=could;
        }
        return x;
}
void dfs(edge x)
{
        if(S.count(x))return;
        S.insert(x);
        if(x.a==0)
        co[x.c]=1;
        if(x.a)
        {
               dfs(move(x,1));
               dfs(move(x,2));
        }
        if(x.b)
        {
                dfs(move(x,3));
                dfs(move(x,4));
        }
        if(x.c)
        {
                dfs(move(x,5));
                dfs(move(x,6));
        }
}
int main()
{
       freopen("milk3.in","r",stdin);
       freopen("milk3.out","w",stdout);
       cin>>st.la>>st.lb>>st.lc;
       st.c=st.lc;
       dfs(st);
       int i;
       for(i=0;i<=20;i++)
               if(co[i]){cout<<i;break;}
       for(i++;i<=20;i++)
               if(co[i]){cout<<' '<<i;}
       cout<<endl;
       return 0;
}
