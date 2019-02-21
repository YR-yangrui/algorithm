/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月13日 星期三 16时03分16秒
*******************************/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<set>
using namespace std;
const int maxn=1e7;
struct edge{
        int a;
        bool operator<(const edge & x)const
        {
                return a<x.a;
        }
}e[maxn];
class js{
        public:
                int a;
                bool operator<(const js & x)const
                {
                        return a<x.a;
                }
}g[maxn];
set<edge>E;
set<js>J;
int main()
{
        time_t t=clock(),c;
        for(int i=1;i<=maxn-1;i++)
                e[i].a=i;
        cout<<"struct =:"<<clock()-t<<endl;
        t=clock();
        for(int i=1;i<=maxn-1;i++)
                g[i].a=i;
        c=clock();
        cout<<"class =:"<<c-t<<endl;
        t=clock();
        for(int i=1;i<=maxn-1;i++)
                E.insert(e[i]);
        c=clock();
        cout<<"struct insert:"<<c-t<<endl;
        t=clock();
        for(int i=1;i<=maxn-1;i++)
                J.insert(g[i]);
        c=clock();
        cout<<"class insert:"<<c-t<<endl;
}
