/* ************************************************************************
> File Name:     container_9_31.cpp
> Author:        mark
> Created Time:  2023年03月05日 星期日 14时51分04秒
> Description:   
 ************************************************************************/
#include<iostream>
#include<forward_list>
using namespace std;
int main(){
    forward_list<int> fl1={
        1,2,3,4,5,6
    };
    forward_list<int>::iterator iter1=fl1.before_begin(),iter2=fl1.begin();
    while(iter2!=fl1.end()){
        if(*iter2%2){
            iter1=fl1.insert_after(iter1,*iter2);
            iter1=iter2;
            iter2++;
        }else{
            iter2=fl1.erase_after(iter1);
        }
    }
    for(auto &a:fl1)
        cout<<a<<" ";
    cout<<endl;
}
