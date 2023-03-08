#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main(){
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    list<int> l1(begin(ia),end(ia)); // 内置类型的数组是不支持赋值和拷贝的，使用迭代器的方式实现
    vector<int> vec1(begin(ia),end(ia));
    list<int>::iterator iter1=l1.begin();
    while(iter1!=l1.end()){
        if(*iter1%2){
            iter1=l1.erase(iter1);
        }else{
            iter1++;
        }
    }
    vector<int>::iterator iter2=vec1.begin();
    while(iter2!=vec1.end()){
        if(*iter2%2==0){
            iter2=vec1.erase(iter2);
        }else{
            iter2++;
        }
    }
    for(auto &a:l1)
        cout<<a<<" ";
    cout<<endl;
    for(auto &a:vec1)
        cout<<a<<" ";
    cout<<endl;
    return 0;
}
