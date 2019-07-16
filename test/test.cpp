/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年07月13日 星期六 19时15分22秒
 *******************************/
#include<iostream>
#include<cstdio>
#include<string>
using std::string;
class people{
    private:
        string name;
        int age;
        int height;
    public:
        people() { name="no name"; age=height=0; }
        people(const string n,const int a,const int h):name(n),age(a),height(h) { }
        people(const people  & p)
        {
            name=p.name;
            age=p.age;
            height=p.height;
        }
        virtual ~people(){}
        virtual void show()const
        {
            std::cout<<" name:"<<name<<std::endl
                <<"  age:"<<age<<std::endl
                <<"height:"<<height<<std::endl
                <<"----------------------------\n";
        }
        string _name()const { return name; }
        int _age()const { return age; }
        int _height()const { return height; }
        virtual void ss(int a)
        {
            std::cout<<"a="<<a<<std::endl;
        }
};
class worker: public people {
    private:
        string job;
        int salary;
        int money;
    public:
        worker():people() { job="no job"; salary=money=0; }
        worker(const string n, const int a,const int h,const string j,const int sa,const int mo):people(n,a,h),job(j),salary(sa),money(mo) { }
        worker(const string j,const int sa,const int mo,const people t):people(t) { job=j; salary=sa; money=mo; }
        ~worker(){}
        virtual void show()const
        {
            std::cout<<"  name:"<<_name()<<std::endl
                     <<"   age:"<<_age()<<std::endl
                     <<"height:"<<_height()<<std::endl
                     <<"   job:"<<job<<std::endl
                     <<"salary:"<<salary<<std::endl
                     <<" money:"<<money<<std::endl
                     <<"---------------------------\n";
        }
        string _job() const { return job; }
        int _salary() const { return salary; }
        int _money() const { return money; }
};
int main()
{
    //people yr("杨锐",16,164);
    //yr.show();
    //worker *Yr;
    //Yr=(worker *)&yr;
    //Yr->show();
    //worker jr("蒋锐",16,163,"student",0,100);
    //jr.show();
    //people * Jr;
    //Jr=&jr;
    //Jr->show();
    worker a;
    people b;
    return 0;
}
