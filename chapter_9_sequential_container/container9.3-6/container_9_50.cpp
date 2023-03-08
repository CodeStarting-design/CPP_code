/* ************************************************************************
> File Name:     container_9_50.cpp
> Author:        mark
> Created Time:  2023年03月07日 星期二 12时56分43秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int get_sum_int(vector<string> num){
    int sum=0;
    for(auto a:num)
        sum+=stoi(a);
    return sum;
}
double get_sum_double(vector<string> num){
    double sum=0;
    for(auto a:num)
        sum+=stod(a);
    return sum;
}
int main(){
    vector<string> num_int{
        "1","2","-1","10","+10"
    };
    vector<string> num_double{
        "1.2","-1.2","+10"
    };
    int sum1=get_sum_int(num_int);
    double sum2=get_sum_double(num_double);
    cout<<sum1<<" "<<sum2<<endl;
}
