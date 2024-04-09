#include<iostream>
class sch{
public:
    static const int STACK_SIZE = (1024*1024);
    sch();
    virtual ~sch();
private:
    char stack_[STACK_SIZE];
};

sch::sch(){

}
sch::~sch(){

}

int main(){
    sch *s =new sch();
    std::cout<<sizeof(*s)/1024<<std::endl;
    delete s;
}

