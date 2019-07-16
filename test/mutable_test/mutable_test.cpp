/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年06月21日 星期五 20时54分41秒
*******************************/
#include<iostream>
#include<cstdio>
#include<cstring>
class Data{
    public:
        mutable char * name;
        int age;
        Data(const char * p,int a)
        {
            name=new char [strlen(p)+1];
            strcpy(name,p);
            age=a;
        }
        Data()
        {
            name=nullptr;
            age=0;
        }
        void show()const
        {
            std::cout<<name<<std::endl
                     <<"age:"<<age<<std::endl;
        }
};
int main()
{
    const Data d("galaxy yr",15);
    d.show();
    const char * s="Galaxy yr";
    strcpy(d.name,s);
    d.show();
    delete [] s;
    return 0;
}
