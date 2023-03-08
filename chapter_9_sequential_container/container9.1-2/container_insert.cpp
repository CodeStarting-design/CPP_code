#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> vec(10,2);
    vector<int>::iterator iter1=vec.insert(vec.begin(),10,1); // 在vec的前面插入10个1
    cout<<*iter1<<endl;
    vector<int>::iterator iter2=vec.insert(vec.begin(),{1,2,3}); // 在vec的前面插入1,2,3
    cout<<*iter2<<endl;
    vector<int> vec2={4,5,6}; 
    vector<int>::iterator iter3=vec.insert(vec.begin(),vec2.begin(),vec2.end());// 将vec2中的元素全部插入到vec前面
    cout<<*iter3<<endl;
    for(auto &a:vec)
    cout<<a<<" ";
}