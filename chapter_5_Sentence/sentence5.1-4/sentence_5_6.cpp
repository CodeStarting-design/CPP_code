#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> vec={"F","D","C","B","A","A++"};
    int grade;
    string legrade;
    while(cin>>grade&&grade<=100&&grade>=0){
       legrade=(grade<60?"F":vec[(grade-50)/10]);
       legrade+=
       ((grade==100||grade<60)?"":(grade%10<3?"-":(grade%10>6?"+":"")));
       cout<<legrade<<endl;
    }
    return 0;
}