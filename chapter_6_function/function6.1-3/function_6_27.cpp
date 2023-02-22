#include<iostream>
#include<initializer_list>
using namespace std;
void print_sum(initializer_list<int> list){
    int sum=0;
    for(const auto &a:list){
        sum+=a;
    }
    cout<<sum<<endl;
}
int main(){
    print_sum({1,2,3,34,4});
    print_sum({132,234,5});
    return 0;
}