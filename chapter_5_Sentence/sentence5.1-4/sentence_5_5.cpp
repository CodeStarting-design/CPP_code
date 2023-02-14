#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    vector<string> vec={"F","D","C","B","A","A++"};
    int grade;
    string legrade;
    while(cin>>grade&&grade<=100&&grade>=0){
        if(grade<60)
        cout<<"F"<<endl;
        else{
            legrade=vec[(grade-50)/10];
            if(grade!=100){
                if((grade%10)>2){
                    if((grade%10)>6)
                    legrade+="+";
                }
                else{
                    legrade+="-";
                }
            }
            cout<<legrade<<endl;
        }
    }
    return 0;
}