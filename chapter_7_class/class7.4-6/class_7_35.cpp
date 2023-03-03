#include<iostream>
#include<string>
using namespace std;
typedef string Type;
Type initVal();
class Exercise {
    public:
        typedef double Type;
        Type setVal(Type);
        Type initVal();
        void print(ostream &os){os<<val<<endl;}
    private:
        int val;
};
Exercise::Type Exercise::setVal(Type parm){
    val = parm+initVal();
    return val;
}
Exercise::Type Exercise::initVal(){
    return 3.14;
}
int main(){
    Exercise e1;
    e1.setVal(2);
    e1.print(cout);
}