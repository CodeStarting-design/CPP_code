/* ************************************************************************
> File Name:     container_9_41.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 09时33分04秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    vector<char> s={
        'h','e','l','l','o','\0'
    };
    //  string s1(s); 不能使用vector容器直接初始化string
    // 通过传递迭代器实现
    string s1(s.begin(),s.end());
    cout<<s1<<endl;
    string s2(10,'4');
    cout<<s2<<endl;
    string s3{
        'h','e'
    };
    string s4={
        '1','2','3'
    };
    cout<<s3<<" "<<s4<<endl;
}
