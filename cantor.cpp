#include<iostream>
using namespace std;
int cantor(int *a,int n)
{
	static const int FAC[]={1,1,2,6,24,120,720,5040,40320,362880};//factor
	int x=0;
	for(int i=0;i<n;i++)
	{
		int smaller=0;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])smaller++;
		}
		x+=FAC[n-i-1]*smaller;
	}
	return x;
}
int main()
{
	int* a;
	int n;
	cin>>n;
	a=new int [n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<cantor(a,n);
	return 0;
}
