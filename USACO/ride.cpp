/*
ID:galaxy_6
LANG:C++
TASK:ride
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=47;
string s;
long long a,b;
int main()
{
        freopen("ride.in","r",stdin);
        freopen("ride.out","w",stdout);
        cin>>s;
        a=b=1;
        for(int i=0;i<s.size();i++)
                a*=s[i]-'A'+1;
        a%=mod;
        cin>>s;
        for(int i=0;i<s.size();i++)
                b*=s[i]-'A'+1;
        b%=mod;
        if(a==b)cout<<"GO\n";
        else cout<<"STAY\n";
        return 0;
}
