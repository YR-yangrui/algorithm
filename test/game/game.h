#include<iostream>
const int INF=999999999;
class solider{
    private:
        int blood;
        int atk;
        int def;
        int scope;
        int _money;
        int _cost;
        char * name;
    public:
        solider(int b,int a,int d,int s,const char * p);
        solider();
        ~solider();
        void Attack(solider & enermy)const;
        bool check_enermy()const;
        bool buy(int & p)const;
        void show()const;
        friend solider & operator<<(std::ostream & os,const solider & s);
};
