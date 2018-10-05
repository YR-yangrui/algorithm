//https://www.luogu.org/problemnew/show/P3382#sub
#include<iostream>
#include<iomanip>
#define find
using namespace std;
const int maxn=15;
double k[maxn],l,r;
int n;
double ans;
double js(double x)
{
	ans=k[0];
	double t=x;
	for(int i=1;i<=n;i++)
	{
		ans=ans+t*k[i];
		t*=x;
	}
	
	return ans;
}
double sanfen(double l,double r)
{
	while(r-l>=1e-6)
	{
		double mid1=(l+(r-l)/3),mid2=(r-(r-l)/3);
		if(js(mid1)>js(mid2))r=mid2;
		else l=mid1;
	}
	return l;
}
int main()
{
	cin>>n>>l>>r;
	for(int i=n;i>=0;i--)
		cin>>k[i];
	cout<<fixed<<setprecision(5)<<sanfen(l,r);
}

