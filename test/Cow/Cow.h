#ifndef _COW_H_
#define _COW_H_
#include<iostream>
class Cow{
    char name[20];
    char * hobby;
    double weight;
    public:
    Cow();
    Cow(const char * nm,const char * ho,double wt);
    Cow(const Cow& t);
    ~Cow();
    Cow & operator=(const Cow & c);
    void ShowCow()const;//display all cow data
    friend std::ostream & operator<<(std::ostream & os,const Cow & c);
};
#endif
