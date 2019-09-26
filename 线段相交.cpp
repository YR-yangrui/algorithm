/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月26日 星期四 16时23分39秒
*******************************/
#include<iostream>
#include<cstdio>

using namespace std;

struct Point{
    Point(int x=0,int y=0):x(x),y(y){}
    double x,y;
    bool operator<(const Point & p)const
    {
        if(x==p.x)return y<p.y;
        return x<p.x;
    }
    Point operator-(const Point & p)const
    {
        return Point(x-p.x,y-p.y);
    }
};

double Cross(const Point &a,const Point &b) { return (a.x*b.y-b.x*a.y); }

bool Intersection(Point a,Point b,Point u,Point v)
{
    if(max(a.x,b.x)<min(u.x,b.x) || max(u.x,v.x)<min(a.x,b.x) ||
            max(a.y,b.y)<min(u.y,v.y) || max(u.y,v.y)<min(a.y,b.y))
        return false;
    if(Cross(a-u,v-u)*Cross(b-u,v-u)<=0 && Cross(u-b,a-b)*Cross(v-b,a-b)<=0)
        return true;
    return false;
}

int main()
{
    freopen("线段相交.in","r",stdin);
    freopen("线段相交.out","w",stdout);
    Point a[4];
    for(int i=0;i<4;i++)
        cin>>a[i].x>>a[i].y;
    cout<<Intersection(a[0],a[1],a[2],a[3])<<endl;
    return 0;
}
