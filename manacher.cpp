/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月15日 星期五 12时10分14秒
*******************************/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int manacher(string s,int *p,int n)
{
        static int id=0,maxid,maxd=-1;
        for(int i=1;i<=n;i++)
        {
                if(maxid>i)p[i]=min(p[id*2-i],maxid-i);
                else p[i]=1;
                while(s[i+p[i]]==s[i-p[i]])p[i]++;
                if(p[i]+i>maxid)maxid=p[i]+i,id=i;
                maxd=max(maxd,p[i]);
        }
        return maxd-1;
}
const int maxn=2e7+2e6+100;
int p[maxn];
char ch;
int main()
{
        freopen("manacher.in","r",stdin);
        freopen("manacher.out","w",stdout);
        string s="##";
        while(cin>>ch)
                s+=ch,s+="#";
        cout<<manacher(s,p,s.size()-1)<<endl;
}
