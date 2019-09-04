/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月01日 星期日 20时30分21秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=51;
const int LIM=50;
struct LB{//Linear Basis of a sequence
    long long lb[maxn];
    int tot,len;
    LB(int p):len(p){memset(lb,0,sizeof lb);tot=0;}
    void insert(long long x)
    {
        for(int i=LIM;i>=0;i--)
            if(x&(1ll<<i))
            {
                if(lb[i])x^=lb[i];
                else 
                {
                    lb[i]=x;
                    ++tot;
                    break;
                }
            }
    }
    long long Max()
    {
        long long ans=0;
        for(int i=LIM;i>=0;i--)
            if((ans^lb[i])>ans)
                ans^=lb[i];
        return ans;
    }
    long long Min()
    {
        for(int i=0;i<=LIM;i++)
            if(lb[i])
                return lb[i];
        return 0;
    }
    long long Kth(long long k)
    {
        if(k==1 && tot<len)return 0;
        if(tot<len)k--;
        for(int i=1;i<=LIM;i++)
            for(int j=1;j<=i;j++)
                if(lb[i]&(1ll<<(j-1)))
                    lb[i]^=lb[j-1];
        long long ans=0;
        for(int i=0;i<=60;i++)
            if(lb[i]!=0)
            {
                if(k&1)ans^=lb[i];
                k>>=1;
            }
        return ans;
    }
    bool Query(long long x)
    {
        for(int i=LIM;i>=0;i--)
            if(x&(1ll<<i))
            {
                if(lb[i])x^=lb[i];
                else return 0;
            }
        return true;
    }
};
int main()
{
    freopen("Linear_Basis.in","r",stdin);
    freopen("Linear_Basis.out","w",stdout);
}
