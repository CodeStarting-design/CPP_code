#include<iostream>
#include<string>
using namespace std;
struct Person{
    private:
    string name;
    string address;
    public:
    string getName() const;
    private:
    string getAddress() const;
    Person(const string &n,const string &a):name(n),address(a){}
    Person(const string &n):name(n){}
    Person()=default;
    Person(istream &is);
};

int main(){
    
}