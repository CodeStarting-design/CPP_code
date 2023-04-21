#include<iostream>
#include<utility>
#include<string>
#include<vector>
using std::string;
using std::pair;
using std::vector;
using std::cin;
using std::cout;
int main(){
    vector<pair<string,int>> vec;
    string s;
    int n;
    for(int i=0;i<10;i++){
        cin>>s>>n;
        vec.push_back({s,n});
    }
    for(auto a:vec){
        cout<<a.first<<" "<<a.second<<std::endl;
    }
}