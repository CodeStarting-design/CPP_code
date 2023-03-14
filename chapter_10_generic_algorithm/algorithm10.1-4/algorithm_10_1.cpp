/* ************************************************************************
> File Name:     algorithm_10_1.cpp
> Author:        mark
> Created Time:  2023年03月08日 星期三 09时48分38秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
using namespace std;
int main(){
    vector<int> vec{
        1,2,3,4,5,6,7,2,3,4,5,5,2,1,2
    };
    list<string> l{
        "121","123","1343","121","123","121"
    };
    int vNum=count(vec.begin(),vec.end(),2);
    int lNum=count(l.begin(),l.end(),"121");
    cout<<vNum<<" "<<lNum<<endl;
}
