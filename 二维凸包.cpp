/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月25日 星期三 15时58分00秒
*******************************/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

struct Point{
    double x,y;
    bool operator<(const Point & p)const
    {
        if(x==p.x)return y<p.y;
        return x<p.x;
    }
    Point(double a=0.0,double b=0.0):x(a),y(b){}
    Point operator-(const Point & p)const { return Point(x-p.x,y-p.y); }
};

typedef Point Vector;

const int maxn=10010;
Point p[maxn],s[maxn];
int n;
double ans,mid;

double Cross(const Vector & a,const Vector & b) 
{
    return (a.x*b.y-b.x*a.y); 
}

template<typename T>
T pf(const T & x) 
{
    return x*x; 
}

double dis(const Point & x,const Point & y)
{
    return sqrt(pf(x.x-y.x)+pf(x.y-y.y));
}

void solve()
{
    sort(p+1,p+n+1);
    int m=0;
    for(int i=1;i<=n;i++)
    {
        while(m>1 && Cross(s[m]-s[m-1],p[i]-s[m-1])<=0)m--;
        s[++m]=p[i];
    }
    int k=m;
    for(int i=n-1;i;i--)
    {
        while(m>k && Cross(s[m]-s[m-1],p[i]-s[m-1])<=0)m--;
        s[++m]=p[i];
    }
    for(int i=2;i<=m;i++)
        ans+=dis(s[i],s[i-1]);
    if(n>1)m--;
    printf("%.2lf\n",ans);
    return;
}

int main()
{
    //freopen("p2742.in","r",stdin);
    //freopen("p2742.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
    solve();
    return 0;
}
