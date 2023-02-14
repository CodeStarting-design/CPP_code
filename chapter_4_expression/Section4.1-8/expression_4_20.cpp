#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> strings={"111","23","34"};
    auto iter=strings.begin();
    // (*iter)++; string对象不允许++
    return 0;
}