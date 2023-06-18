#include<new>
#include<memory>
using std::shared_ptr;
using std::make_shared;
int main(){
    auto sp = make_shared<int>();
    auto p = sp.get();
    delete p;
}