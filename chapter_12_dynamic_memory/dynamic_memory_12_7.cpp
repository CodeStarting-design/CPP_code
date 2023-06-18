#include<iostream>
#include<vector>
#include<memory>
using std::vector;
using std::cout;
using std::cin;
using std::shared_ptr;
using std::make_shared;
shared_ptr<vector<int>> createVector(){
    shared_ptr<vector<int>> vec= make_shared<vector<int>> ();
    return vec;
}
void readVeetor(shared_ptr<vector<int>> vec){
    int a;
    while(cin>>a){
        vec->push_back(a);
    }
}
void printVcetor(shared_ptr<vector<int>> vec){
    for(auto a:*vec){  // shared_ptr 本质上也是指针，也是支持解引用
        cout<<a<<" ";
    }
    cout<<std::endl;
}
int main(){
    shared_ptr<vector<int>> p=createVector();
    readVeetor(p);
    printVcetor(p);
}