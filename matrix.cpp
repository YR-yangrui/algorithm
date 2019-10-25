/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年09月04日 星期三 14时34分28秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=405;
int n=100;
const int mod=1e9+7;
int ksm(int a,int b)
{
    a%=mod;
    int res=1;
    while(b)
    {
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
struct Matrix{
    int a[maxn][maxn];
    Matrix() { memset(a,0,sizeof a); }//初始化
    Matrix(int k)//初始化k阶单位矩阵
    {
        k=min(k,n);
        memset(a,0,sizeof a);
        for(int i=1;i<=k;i++) a[i][i]=1;
    }
    int * operator[](const int i){ return a[i]; }
    const int * operator[](const int i)const { return a[i]; }
    void print()const//打印矩阵
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<a[i][j]<<' ';
            cout<<endl;
        }
    }
    /*{{{初等行变换*/
    void swap(const int x,const int y) { for(int i=1;i<=n;i++)swap(a[x][i],a[y][i]); }//交换行和列
    void mul(const int x,const int k) { for(int i=1;i<=n;i++) a[x][i]=(1ll*a[x][i]*k)%mod; }//某一行乘上k
    void md(const int x,const int y,int k)//把第y行乘上k，再加打第x行上
    {
        for(int i=1;i<=n;i++)
            a[x][i]=(a[x][i]+1ll*a[y][i]*k%mod+mod)%mod;
    }
    /*}}}*/
    Matrix operator*(const Matrix & p)const//矩阵乘法
    {
        Matrix t;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    t[i][j]=(1ll*a[i][k]*p[k][j]+t[i][j])%mod;
        return t;
    }
    Matrix operator+(const Matrix & p)const//矩阵加法
    {
        Matrix t;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                t[i][j]=(a[i][j]+p[i][j])%mod;
        return t;
    }
    bool get_inv(Matrix &t)//矩阵求逆
    {
        memset(t.a,0,sizeof t.a);
        for(int i=1;i<=n;i++) t.a[i][i]=1;
        for(int i=1;i<=n;i++)//转换成上三角矩阵
        {
            if(!a[i][i])
            {
                for(int j=i+1;j<=n;j++)
                    if(a[j][i])
                    {
                        this->swap(i,j);
                        t.swap(i,j);
                        break;
                    }
            }
            if(!a[i][i]) { printf("No Solution\n"); return 0; }
            t.mul(i,ksm(a[i][i],mod-2));
            this->mul(i,ksm(a[i][i],mod-2));//第i行第i列元素值为1
            for(int j=i+1;j<=n;j++)
                t.md(j,i,-a[j][i]),this->md(j,i,-a[j][i]);//转换
        }
        for(int i=n-1;i;i--)//转换成单位矩阵
            for(int j=i+1;j<=n;j++)
                t.md(i,j,-a[i][j]),this->md(i,j,-a[i][j]);
        return 1;
    }
}A,B;
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    //矩阵求逆为例
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    if(A.get_inv(B))
        B.print();
    return 0;
}
