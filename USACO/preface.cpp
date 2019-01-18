/*
ID:galaxy_6
LANG:C++
TASK:preface
*/
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
struct edge{
        string num;
        int val;
        edge(){val=0;}
        edge(const string a,const int b):num(a),val(b){}
}e[100];
void make()
{
        e[1]=edge("I",1);
        e[2]=edge("IV",4);
        e[3]=edge("V",5);
        e[4]=edge("IX",9);
        e[5]=edge("X",10);
        e[6]=edge("XL",40);
        e[7]=edge("L",50);
        e[8]=edge("XC",90);
        e[9]=edge("C",100);
        e[10]=edge("CD",400);
        e[11]=edge("D",500);
        e[12]=edge("CM",900);
        e[13]=edge("M",1000);
}
string s="$IVXLCDM";
int num[20];
void solve_string(string a,int b)
{
        for(int i=0;i<a.size();i++)
                for(int j=1;j<s.size();j++)
                        if(a[i]==s[j])
                                num[j]+=b;
}
int main()
{
       freopen("preface.in","r",stdin);
       freopen("preface.out","w",stdout);
       int n;
       cin>>n;
       make();
       for(int k=1;k<=n;k++)
       {
               int i=k;
               int j=13;
               while(i)
               {
                       if(i>=e[j].val)
                       {
                               solve_string(e[j].num,i/e[j].val);
                               i%=e[j].val;
                       }
                       j--;
               }
       }
       for(int i=1;i<=s.size();i++)
               if(num[i])
                       cout<<s[i]<<' '<<num[i]<<endl;
       return 0;
}
