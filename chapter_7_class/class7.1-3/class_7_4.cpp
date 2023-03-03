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
int main(){

}