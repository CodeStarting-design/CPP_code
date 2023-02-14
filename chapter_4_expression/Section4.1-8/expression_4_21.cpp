#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec={1,2,3,4,5,6,7};
    for(auto &a:vec)
        a%2?a*=2:a;
    for(auto &a:vec)
    cout<<a<<endl;
    return 0;
}