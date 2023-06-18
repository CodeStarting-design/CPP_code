#include<iostream>
#include<vector>
#include<new>
using std::vector;
using std::cout;
using std::cin;
vector<int>* createVector(){
    vector<int>* vec=new vector<int>;
    return vec;
}
void readVeetor(vector<int>* vec){
    int a;
    while(cin>>a){
        vec->push_back(a);
    }
}
void printVcetor(vector<int>* vec){
    for(auto a:*vec){
        cout<<a<<" ";
    }
    cout<<std::endl;
}
int main(){
    vector<int> *p=createVector();
    readVeetor(p);
    printVcetor(p);
    delete p;
}
