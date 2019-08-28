void add (int &x,int y){	x=((x+y)%mod+mod)%mod;}
//{{{FWTOR
void FWTOR (int *a,int on_off)//on_off -> 1 FWT -1 IFWT
{
	for (int len=2;len<=n;len<<=1)
		for (int i=0,hlen=len>>1;i<n;i+=len)
			for (int j=i,k=i+hlen;j<k;++j)
				add(a[j+hlen],on_off*a[j]);
}
//}}}
//{{{FWTAND
void FWTAND (int *a,int on_off)
{
	for (int len=2;len<=n;len<<=1)
		for (int i=0,hlen=len>>1;i<n;i+=len)
			for (int j=i,k=i+hlen;j<k;++j)
				add(a[j],on_off*a[j+hlen]);
}
//}}}
//{{{FWTXOR
void FWTXOR (int *a,int on_off,int inv2)//inv2 2µÄÄæÔª
{
	for (int len=2;len<=n;len<<=1)
		for (int i=0,hlen=len>>1;i<n;i+=len)
			for (int j=i,k=i+hlen;j<k;++j){
				int x=a[j],y=a[j+hlen];
				if (on_off>0)	a[j]=(x+y)%mod,a[j+hlen]=(x-y+mod)%mod;
				else	a[j]=1ll*(x+y)*inv2%mod,a[j+hlen]=1ll*(x-y+mod)%mod*inv2%mod;
			}
}
//}}}
//{{{mul
void mul ()
{
	for (int i=0;i<n;++i)	h[i]=1ll*f[i]*g[i]%mod;
}
//}}}
//{{{ksm
int ksm (int a,int b)
{
	int s=1;
	a%=mod;
	for (;b;b>>=1,a=1ll*a*a%mod)
		if (b&1)	s=1ll*s*a%mod;
	return s;
}
//}}}

