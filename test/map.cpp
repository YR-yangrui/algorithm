/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年02月13日 星期三 15时36分34秒
*******************************/
#include <map>  
#include <string>  
#include <iostream>  
using namespace std;  
int main()  
{  
        map<int,int>m;
        m[1]=1;
        m[2]=2;
        m[3]=3;
        map<int,int>::iterator it=m.begin();
    return 0;  
} 
