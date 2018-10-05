//https://www.luogu.org/problemnew/show/P3375#sub
//kmp 算法
#include<iostream>
#include<string>

using namespace std;
const int maxn=1e+6+5;
string T,P;
int next[maxn],i,j;
#ifdef find
char c1,c2;
#endif
void make_next(const string & s,int * next)
{
	next[0]=0;
	int k=0,q;
	for(q=1;q<s.size();q++)
	{
		while(k>0 and s[q] not_eq s[k])
			k=next[k-1];
		if(s[k]==s[q])
			k++;
		next[q]=k;
	}
	return;
}
void kmp(const string & T,const string & P,int * next)
{
	make_next(P,next);
	#ifdef find
	for(i=0;i<P.size();i++)cout<<next[i]<<' ';
	cout<<endl;
	#endif
	for(i=0,j=0;i<T.size();i++)
	{

#ifdef find
c1=T[i];c2=P[j];
#endif
	while(j and T[i] not_eq P[j])j=next[j-1];
		if(T[i]==P[j])
		{
			j++;
		}
		if(j==P.size())
		{
			cout<<i-j+2<<endl;
			j=next[j-1];
		}
	}
}
int main()
{
	cin>>T>>P;
	kmp(T,P,next);
	for(i=0;i<P.size();i++)
		cout<<next[i]<<' ';
	return 0;
}

