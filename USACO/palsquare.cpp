/*
ID:galaxy_6
LANG:C++
TASK:palsquare
*/
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int B;
long long bs[100];
char ch[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string turn(int n)
{
        string s;
        int i;
        for(i=0;i<=100;i++)if(bs[i+1]>n)break;
        for(;i>=0;i--)
        {
                if(bs[i]<=n) s+=ch[n/bs[i]];
                else s+='0';
                n%=bs[i];
        }
        return s;
}
bool check(string s)
{
        int len=s.size();
        for(int i=0;i<=len/2;i++)
                if(s[i]!=s[len-i-1])return false;
        return true;
}
int main()
{
        freopen("palsquare.in","r",stdin);
        freopen("palsquare.out","w",stdout);
        cin>>B;
        bs[0]=1;
        for(int i=1;i<=100;i++) bs[i]=bs[i-1]*B;
        for(int i=1;i<=300;i++)
        {
                string s=turn(i*i);
                if(check(s))
                {
                        cout<<turn(i)<<' '<<s<<endl;
                }
        }
        return 0;
}
