#include<iostream>
#include<forward_list>
#include<string>
using namespace std;
int main(){
    forward_list<int> fl1={
        1,2,3,4,5,6,7,8,9,10
    };
    forward_list<int>::iterator iter1=fl1.before_begin(),iter2=fl1.begin();
    while(iter2!=fl1.end()){
        if((*iter2)%2){
            iter2=fl1.erase_after(iter1);
        }else{
            iter2++;
            iter1++;
        }
    }
    for(auto &a:fl1)
        cout<<a<<" ";
    cout<<endl;
}
