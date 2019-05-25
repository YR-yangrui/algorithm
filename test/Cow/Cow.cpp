#include "Cow.h"
#include<cstring>
#include<iostream>
#ifndef _COW_DEF_
#define _COW_DEF_
Cow::Cow()
{
    strcpy(name,"no name");
    hobby=nullptr;
    weight=0;
}
Cow::Cow(const char * nm,const char * ho,double wt)
{
    strcpy(name,nm);
    int tl=strlen(ho);
    hobby=new char [tl+1];
    strcpy(hobby,ho);
    weight=wt;
}
Cow::Cow(const Cow & t)
{
    strcpy(name,t.name);
    strcpy(hobby,t.hobby);
    weight=t.weight;
}
Cow::~Cow(){}
Cow & Cow::operator=(const Cow & c)
{
    strcpy(name,c.name);
    strcpy(hobby,c.hobby);
    weight=c.weight;
    return *this;
}
void Cow::ShowCow()const
{
    std::cout<<"------------------\n";
    std::cout<<std::left<<"` name:   "<<name<<std::endl;
    std::cout<<std::left<<"` hobby:  "<<hobby<<std::endl;
    std::cout<<std::left<<"` weight: "<<weight<<std::endl;
    std::cout<<"------------------\n";
}
#endif
