/*
 *    This line segment tree can only achieve interval sum and interval summation
 *    https://www.luogu.org/problemnew/show/P3372#sub
 */
#include <bits/stdc++.h>
using namespace std;
const long long N=100005;
long long n,m,lazy[N*4],b[N];
long long sum[4*N];
void build(long long k,long long l,long long r)
{
	if(l==r) 
	{
		sum[k]=b[l];
		return ;
	}
	long long mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}

void add(long long k,long long l,long long r,long long v)
{
	lazy[k]+=v;
	sum[k]+=v*(r-l+1);
}

void pushdown(long long k,long long l,long long r,long long mid)
{
    if (lazy[k]==0) return ;
        add(k<<1,l,mid,lazy[k]);
        add(k<<1|1,mid+1,r,lazy[k]);
        lazy[k]=0;
}

long long query(long long k,long long l,long long r,long long x,long long y)
{
	if(x<=l&&r<=y) return sum[k];
	long long mid=(l+r)>>1;
	long long ans=0;
	pushdown(k,l,r,mid);
	if(x<=mid) ans+=query(k<<1,l,mid,x,y);
	if(mid<y) ans+=query(k<<1|1,mid+1,r,x,y);
	return ans;
}

void Update(long long k,long long l,long long r,long long x,long long y,long long v)
{
    if(l>=x&&r<=y)  {add(k,l,r,v);return ;}
    long long mid=l+r>>1;
    pushdown(k,l,r,mid);
    if(x<=mid) Update(k<<1,l,mid,x,y,v);
    if(mid<y) Update(k<<1|1,mid+1,r,x,y,v);
    sum[k]=sum[k<<1]+sum[k<<1|1];
}

int main()
{
	long long t,x,y,k;
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++)
	scanf("%lld",&b[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++){
		scanf("%lld",&t);
		if(t==1){
		    scanf("%lld%lld%lld",&x,&y,&k);
		    Update(1,1,n,x,y,k);
		}else
		    {
			    scanf("%lld%lld",&x,&y);
			    printf("%lld\n",query(1,1,n,x,y));
		    }
    }
		return 0;
}
