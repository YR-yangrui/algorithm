#include<iostream>
using namespace std;
int a[10],b,c;
int main()
{
    a[1]=b=1;
    c=2;
    b=a[b]=c;
    cout<<a[1]<<' '<<a[2]<<' '<<b<<endl;
}
