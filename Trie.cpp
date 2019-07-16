/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月27日 星期四 16时19分59秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int ch[maxn][27],cnt=1,num[maxn],b[maxn],c;
void insert(string s)
{
    int now=1;
    for(int i=0;i<s.size();i++)
    {
        c=s[i]-'a';
        if(!ch[now][c])ch[now][c]=++cnt;
        now=ch[now][c];
    }
    num[now]++;
}
int find(string s)
{
    int now=1;
    for(int i=0;i<s.size();i++)
    {
        c=s[i]-'a';
        if(!ch[now][c])return 0;
        now=ch[now][c];
    }
    return b[now];
}
int main()
{
        freopen("Trie.in","r",stdin);
        freopen("Trie.out","w",stdout);
}
