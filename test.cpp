/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019/2/15 5:12:32
 *******************************/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;
string turn(int k)
{
    string h;
    while(k) h+=(k%10)+'0',k/=10;
    for(int i=0;i<=h.size()/2;i++) swap(h[i],h[h.size()-i-1]);
    return h;
}
bool compare(ifstream & f1,ifstream & f2)
{
    int n=0;
    char c1,c2;
    while(f1 and f2)
    {
        c1=f1.get();c2=f2.get();
        if(c1!=c2)
        {
            cout<<"WRONG!!!\n";
            cout<<"on line "<<n+1<<",read: "<<c1<<','<<c2;
            cout<<endl;
            return false;
        }
        if(c1=='\n')n++;
    }
    return true;
}
int main()
{
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
    int n;
    bool q;
    string s,k,h,t,st;
    cout<<"Is it linux?(1/0)";cin>>q;
    cout<<"Please enter filename:"; cin>>s;
    cout<<"Please enter testname:"; cin>>st;
    cout<<"Pleae enter executable file command:(./x »ò x.exe)";cin>>k;
    cout<<"Please enter the number of test files:"; cin>>n;
    cout<<"Please enter the standard anwser file prefix:(x)";cin>>h;
    for(int i=1;i<=n;i++)
    {
        t=st+turn(i);
        cout<<"Start to test "<<i<<"th test file ("<<t<<")... ";
        string m;
        if(q) m=("cp "+t+".in "+s+".in");
        else m=("copy "+t+".in "+s+".in");
        system(m.c_str());
        system(k.c_str());
        {
            const string sss=s+".out",ssr=t+".out";
            ifstream f1(sss.c_str()),f2(ssr.c_str());
            if(compare(f1,f2)) cout<<"Accept!\n";
        }
    }
    return 0;
}
