#include<iostream>
using std::cout;

class testRAII{
public:
    testRAII(){
        cout<<"Construction"<<std::endl;
    }
    ~testRAII(){
        cout<<"Destory"<<std::endl;
    }
};

void test(){
    testRAII();
    for(int i=0;i<10;i++){
        cout<<i<<" ";
    }
    cout<<std::endl;
}
int main(){
    test();
}