/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月13日 星期三 18时46分04秒
*******************************/
#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;
const int n=1e5;
int main()
{
        freopen("p1034.in","w",stdout);
        cout<<n<<endl;
        srand(time(0));
        for(int i=1;i<=n;i++)
        {
                int m,s,r;
                m=rand()%n;
                s=rand()%m;
                r=rand()%n;
                cout<<s<<' '<<m<<' '<<r<<endl;
        }
        cout<<n<<endl;
        int t=0;
        for(int i=1;i<=n;i++)
        {
                int r,l;
                r=rand()%n+1;
                l=rand()%r+1;
                t+=rand()%n;
                cout<<t<<' '<<l<<' '<<r<<endl;
        }
}
