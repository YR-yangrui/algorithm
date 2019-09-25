#include<iostream>
#include<string>
int main()
{
    std::string s="hello world\n";
    const void * s1=(void *)s.c_str();
    const void * s2=(void*)s.data();
    std::cout<<s<<(s1)<<' '<<(s2)<<std::endl;
}
