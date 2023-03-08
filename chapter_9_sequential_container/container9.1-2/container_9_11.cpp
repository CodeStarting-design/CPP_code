#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v1;
    vector<int> v2(v1);
    vector<int> v3 =v1;
    vector<int> v4(v1.begin(),v1.end());
    vector<int> v5={1,2,3,4};
    vector<int> v6(10);
    vector<int> v7(10,2);
}