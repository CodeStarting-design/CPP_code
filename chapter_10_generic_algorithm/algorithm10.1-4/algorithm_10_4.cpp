#include<iostream>
#include<numeric>
#include<vector>
using namespace std;
int main(){
vector<double> vec{1,2,3,4.1,3.6};
double sum=accumulate(vec.cbegin(),vec.cend(),0);
cout<<sum<<endl;
}