#include<iostream>
#include<vector>
#include<list>
using namespace std;
bool list_and_vector(list<int> l1,vector<int> v1){
    vector<int> v2;
    v2.assign(l1.cbegin(),l1.cend());
    return v1==v2;
}
int main(){
    vector<int> v1(10,2);
    vector<int> v2(11,2);
    bool vec=v1==v2;
    list<int> l1(10,3);
    bool lis=list_and_vector(l1,v1);
    cout<<vec<<" "<<lis<<endl;
}