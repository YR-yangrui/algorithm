/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月17日 星期四 15时31分03秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<complex>
#include<cmath>
using namespace std;
const double PI=3.1415926535;
const int maxn=2097153;
typedef complex<double> cd;
string s1,s2;
cd a[maxn],b[maxn];
int rev[maxn];
void get_rev(int bit)
{
    for(int i=0;i<(1<<bit);i++)
        rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}
void FFT(cd *a,int len,int on)
{
    for(int i=0;i<len;i++)
        if(i<rev[i])
            swap(a[i],a[rev[i]]);
    for(int i=2;i<=len;i<<=1)
    {
        cd wn=cd(cos(2*PI/i),on*sin(2*PI/i));
        for(int j=0;j<len;j+=i)
        {
            cd w(1,0);
            for(int k=j;k<j+i/2;k++)
            {
                cd u=a[k],t=w*a[k+i/2];
                a[k]=u+t;a[k+i/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1)
        for(int i=0;i<len;i++)a[i]/=len;
}
int ans[maxn];
int main()
{
    freopen("FFT.in","r",stdin);
    freopen("FFT.out","w",stdout);
    cin>>s1>>s2;
    int bit=1,s=2,l1=s1.size(),l2=s2.size();
    while(s<(l1+l2-1))
    {
        s<<=1;bit++;
    }
    for(int i=0;i<l1;i++)
        a[i]=(double)(s1[l1-i-1]-'0');
    for(int i=0;i<l2;i++)
        b[i]=(double)(s2[l2-i-1]-'0');
    get_rev(bit);  FFT(a,s,1);  FFT(b,s,1);
    for(int i=0;i<s;i++)a[i]*=b[i];
    FFT(a,s,-1);
    for(int i=0;i<s;i++)
    {
        ans[i]+=(int)(a[i].real()+0.5);
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    int i;
    for(i=l1+l2;!ans[i] and i>=0;i--);
    if(i==-1){cout<<"0";}
    while(i>=0)
    {
        cout<<ans[i];
        i--;
    }
    cout<<endl;
    return 0;
}
