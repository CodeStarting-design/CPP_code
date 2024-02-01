#ifndef copy_control_13_22_h
#define copy_control_13_22_h
#include<string>
using std::string;
class HasPtr{
    int num;
    string *p;
public:
    HasPtr(const HasPtr& hp):p(new string(*hp.p)),num(hp.num){}
    HasPtr& operator=(const HasPtr& hp){
        auto new_p=new string(*hp.p);
        delete p;
        p=new_p;
        num=hp.num;
        return *this;
    }
};
#endif