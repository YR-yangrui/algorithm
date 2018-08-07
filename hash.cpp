#include<iostream>
#include<algorithm>
using namespace std;
const int base=131;
const int maxn=10006;
template<typename T>
size_t hash(T * s) {
	size_t ans=0;
	while(size_t ch=(size_t)*s++) {
		ans=ans*base+ch;
	}
	return ans;
}
size_t a[maxn];
char s[maxn];
int n,ans=1;
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>s;
		a[i]=hash(s);
	}
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++)
		if(a[i]!=a[i-1])
			ans++;
	cout<<ans;
	return 0;
}
