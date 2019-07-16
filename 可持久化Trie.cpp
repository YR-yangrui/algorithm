/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年07月15日 星期一 15时04分21秒
*******************************/
#include<iostream>
#include<cstdio>
using namespace std;
struct Trie{
    enum{maxn=1000010};
    int ch[maxn][26],cnt,v[maxn],sum[maxn];
    inline int insert(int x,int val)
    {
        int o,y;o=y=++cnt;
        for(int i=23;i>=0;i--)
        {
            ch[y][0]=ch[x][0];
            ch[y][1]=ch[x][1];
            sum[y]=sum[x]+1;
            int c=(val&(1<<i))>>i;
            x=ch[x][c];
            y=ch[y][c]=++cnt;
        }
        sum[y]=sum[x]+1;
        return o;
    }
    inline int query(int l,int r,int val)
    {
        int ans=0;
        for(int i=23;i>=0;i--)
        {
            int c=(val&(1<<i))>>i;
            if(sum[ch[r][c^1]]-sum[ch[l][c^1]])
            {
                ans+=(1<<i);
                r=ch[r][c^1];
                l=ch[l][c^1];
            }
            else
            {
                r=ch[r][c^1];
                l=ch[l][c^1];
            }
        }
        return ans;
    }
};
