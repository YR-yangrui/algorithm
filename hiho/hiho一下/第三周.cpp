/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月13日 星期三 19时18分59秒
*******************************/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=1e6+10;
int T,nex[maxn];
string s,t;
inline void make_next(const string & s,int * next)
{
        int k=0;
        for(int i=1;i<s.size();i++)
        {
                while(k and s[i]!=s[k])k=nex[k-1];
                if(s[i]==s[k])k++;
                nex[i]=k;
        }
        return;
}
inline void kmp(const string & s,const string & t)
{
        int k=0,ans=0;
        for(int i=0;i<t.size();i++)
        {
                while(s[k]!=t[i] and k)k=nex[k-1];
                if(s[k]==t[i])k++;
                if(k==s.size())
                {
                        cout<<i-k+2<<endl;
                        k=nex[k-1];
                }
        }
        return;
}
int main()
{
        freopen("第三周.in","r",stdin);
        freopen("第三周.out","w",stdout);
        int k,ans;
        cin>>T;
        while(T--)
        {
                cin>>s>>t;
                k=ans=0;
                for(int i=1;i<s.size();i++)
                {
                        while(k and s[i]!=s[k])k=nex[k-1];
                        if(s[i]==s[k])k++;
                        nex[i]=k;
                }
                k=0;
                for(int i=0;i<t.size();i++)
                {
                        while(s[k]!=t[i] and k)k=nex[k-1];
                        if(s[k]==t[i])k++;
                        if(k==s.size())
                                ans++,k=nex[k-1];
                }
                cout<<ans<<endl;
                //make_next(s,nex);
                //kmp(s,t);
        }
}
