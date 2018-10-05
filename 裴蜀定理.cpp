//https://www.luogu.org/problemnew/show/P4549#sub
#include<iostream>
#include<algorithm>
using namespace std;
int ans,n,t;
int main()
{
	cin>>n;
	cin>>ans;
	while(--n)
	{
		cin>>t;
		t=abs(t);
		ans=__gcd(ans,t);
	}
	cout<<ans;
	return 0;
}

