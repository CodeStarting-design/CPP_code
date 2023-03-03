#include<iostream>
#include<string>
using namespace std;
struct class_constructor
{
    class_constructor()=default;
    class_constructor(const std::string &s):bookNo(s) { }
    class_constructor(const std::string&s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n) { }
    class_constructor(std::istream &);
    // 之前已有的其他成员
    std::string isbn() const { return bookNo; }
    class_constructor& combine(const class_constructor&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold =0;
    double revenue =0.0;
};
istream &read(class_constructor &data,istream &is){
    is>>data.bookNo>>data.revenue>>data.units_sold;
    return is;
}
class_constructor::class_constructor(std::istream &is){
    read(*this,is);
}
int main(){
    
}