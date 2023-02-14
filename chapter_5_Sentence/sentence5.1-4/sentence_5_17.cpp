#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> num1;
    vector<int> num2;
    int num;
    while(cin>>num&&num!=999)
    num1.push_back(num);
    while(cin>>num&&num!=999)
    num2.push_back(num);
    if(num1.size()==0||num2.size()==0)
    cout<<"Error input data"<<endl;
    int i;
    for(i=0;i<num1.size()&&i<num2.size()&&num1[i]==num2[i];i++);
    if(i==num1.size()||i==num2.size())
    cout<<"Comparison"<<endl;
    else cout<<"Fail comparison"<<endl;
    return 0;
}