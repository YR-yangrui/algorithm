/*
ID:galaxy_6
LANG:C++
TASK:gift1
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=15;
int n;
string name[maxn];
int money[maxn];
int give,p;
string s;
int main()
{
        freopen("gift1.in","r",stdin);
        freopen("gift1.out","w",stdout);
        cin>>n;
        for(int i=1;i<=n;i++) cin>>name[i];
        for(int i=1;i<=n;i++)
        {
                cin>>s;
                cin>>give>>p;
                if(p==0)continue;
                for(int j=1;j<=n;j++)
                        if(name[j]==s)
                        {
                                money[j]-=(give-give%p);
                                break;
                        }
                for(int j=1;j<=p;j++)
                {
                        cin>>s;
                        for(int k=1;k<=n;k++)
                                if(name[k]==s)
                                {
                                        money[k]+=give/p;
                                        break;
                                }
                }
        }
        for(int i=1;i<=n;i++)
                cout<<name[i]<<' '<<money[i]<<endl;
        return 0;
}
