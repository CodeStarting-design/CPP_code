/* ************************************************************************
> File Name:     container_9_39.cpp
> Author:        mark
> Created Time:  2023年03月05日 星期日 15时24分47秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<string> vec;
    vec.reserve(10);
    cout<<vec.capacity()<<endl;
    vec.resize(20,"111");
    cout<<vec.capacity()<<endl;
}
