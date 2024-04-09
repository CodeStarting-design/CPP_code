#include<iostream>

class test_stack
{
private:
    /* data */
    static const int STACK_SIZE = (1024*1024);
    char stack_[STACK_SIZE];
public:
    test_stack(/* args */);
    ~test_stack();
    char* getStack_(int id){
        return &stack_[id]; 
    }
};

test_stack::test_stack(/* args */)
{
}

test_stack::~test_stack()
{
}

int main(){
    test_stack a =test_stack();
    char c='1';
    char *b=&c;
    std::cout<<std::hex<<static_cast<void*>(b)<<std::endl;
    std::cout<<static_cast<void*>(a.getStack_(0))<<" "<<static_cast<void*>(a.getStack_(1))<<std::endl;
}
