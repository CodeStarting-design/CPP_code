#include<iostream>
#include<string>
using namespace std;
struct Person{
    private:
    string name;
    string address;
    public:
    string getName() const;
    string getAddress() const;
    Person(const string &n,const string &a):name(n),address(a){}
    Person(const string &n):name(n){}
    Person()=default;
    Person(istream &is);
};
string Person::getName()const{
    return name;
}
string Person::getAddress() const{
    return address;
}
// istream &read(Person &person,istream &is){
//     is>>person.getName()>>person.getAddress();
//     return is;
// }
ostream &print(const Person &person, ostream &os){
    os<<person.getName()<<" "<<person.getAddress()<<" ";
    return os; 
}
Person::Person(istream &is){
    //read(*this,is);
}
int main(){
Person p1; // 默认初始化
Person p2("aaa");
Person p3("aaa","bbb");
Person p4(cin);
print(p1,cout);
print(p2,cout);
print(p3,cout);
print(p4,cout);
}