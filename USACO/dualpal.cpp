/*
ID:galaxy_6
LANG:C++
TASK:dualpal
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
char ch[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool check(string s)
{
        int len=s.size();
        for(int i=0;i<=len/2;i++)
                if(s[i]!=s[len-i-1])return false;
        return true;
}
string turn(int n,int b)
{
        string s;
        int i,now=1;
        for(i=0;;i++)
                if(now*b>n) 
                        break;
                else 
                        now*=b;
        for(;i>=0;i--,now/=b)
        {
                if(now<=n) s+=ch[n/now];
                else s+='0';
                n%=now;
        }
        return s;
}
bool is_this(int k)
{
        int gs=0;
        for(int i=2;i<=10;i++)
        {
                if(check(turn(k,i)))
                {
                        gs++;
                        if(gs==2)return true;
                }
        }
        return false;
}
int N,S;
int main()
{
        freopen("dualpal.in","r",stdin);
        freopen("dualpal.out","w",stdout);
        cin>>N>>S;
        int gs=0;
        for(int i=S+1;gs<N;i++)
                if(is_this(i))
                {
                        cout<<i<<endl;
                        gs++;
                }
}
