/* ************************************************************************
> File Name:     algorithm_10_3.cpp
> Author:        mark
> Created Time:  2023年03月08日 星期三 10时37分44秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
    vector<int> vec{
        1,2,3,4,5,6,7,8
    };
    int sum=accumulate(vec.cbegin(),vec.cend(),0);
    cout<<sum<<endl;
}
