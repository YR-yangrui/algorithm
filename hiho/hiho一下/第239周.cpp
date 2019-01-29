/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月29日 星期二 14时19分25秒
*******************************/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int T,cd,k,cnt;
string s;
int main()
{
        freopen("第239周.in","r",stdin);
        freopen("第239周.out","w",stdout);
        cin>>T;
        while(T--)
        {
                cin>>s;
                cd=k=cnt=0;
                for(int i=0;i<s.size();i++)
                {
                        if(s[i]=='A')cnt++;
                        if(s[i]=='L')k++,cd=max(cd,k);
                        else k=0;
                }
                if(cnt>1 or cd>2)
                     cout<<"NO\n";   
                else cout<<"YES\n";
        }
        return 0;
}
