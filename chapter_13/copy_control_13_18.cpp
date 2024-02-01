#include<iostream>
#include<string>
using std::string;
class Employee{
    string name;
    static int start;// 此处仅仅是声明
    int num;
public:
    Employee();
    Employee(string n);
};

// 在类内定义static数据成员，需要在类外进行定义和初始化
int Employee::start=0; 
Employee::Employee(){
    num=start++;
}
Employee::Employee(string n){
    name=n;
    num=start++;
}