/*
ID:galaxy_6
LANG:C++
TASK:beads
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=505;
int n1,n,n2,ans;
int l[maxn],r[maxn];
char ch[maxn],c1,c2;
bool check(int k,char p)
{
	if(ch[k]=='w')return true;
	return (p==ch[k]);
}
int p1,p2;
bool ok;
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ch[i];
        for(int i=1;i<=n+1;i++)l[i]=i-1,r[i]=i+1;
        for(int i=1;i<=n;i++){if(ch[i]!='w')ok=1;break;}
        l[1]=n;r[n]=1;
        for(int i=1;i<=n;i++)
	{
		n1=n2=0;
                p1=i,p2=i+1;
                c1=ch[i],c2=ch[i+1];
                while(c1=='w' and ok)c1=ch[(p1=l[p1])];
                while(c2=='w' and ok) c2=ch[(p2=r[p2])];
                int j1=i,j2=i+1;
                if(j2==n+1)j2=1;
                for(;;j1=l[j1])
                {
                        if(check(j1,c1))n1++;
                        else break;
                        if(j1==j2)break;
                }
                if(j1!=j2)
                {
                        for(;;j2=r[j2])
                        {
                                if(check(j2,c2))n2++;
                                else break;
                                if(j1==j2)break;
                        }
                }
                ans=max(ans,n1+n2);
	}
	cout<<ans<<endl;
	return 0;
}
