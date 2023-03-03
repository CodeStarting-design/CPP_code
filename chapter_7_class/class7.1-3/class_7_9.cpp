#include<iostream>
#include<string>
using namespace std;
struct Person{
    string name;
    string address;
    string getName() const;
    string getAddress() const;
};
string Person::getName()const{
    return name;
}
string Person::getAddress() const{
    return address;
}
istream &read(Person &person,istream &is){
    is>>person.name>>person.address;
    return is;
}
ostream &print(const Person &person, ostream &os){
    os<<person.getName()<<" "<<person.getAddress()<<" ";
    return os; 
}
int main(){
Person *per=new Person();
read(*per,cin);
print(*per,cout);
}