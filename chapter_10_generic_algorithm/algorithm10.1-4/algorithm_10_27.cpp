#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
using std::cout;
using std::cin;
using std::endl;
int main(){
    std::list<int> l;
    std::vector<int> vec{2,2,3,4,7,9,1,2,3,4,5,6,7,8,9};
    std::unique_copy(vec.begin(),vec.end(),std::inserter(l,l.end()));
    for(auto a:l)
    cout<<a<<endl;
}