#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string str;
    vector<string> strs;
    while(cin>>str&&str!="#")
    strs.push_back(str);
    int cnt=0,max=0;
    string pstr="",maxStr;
    for(auto &a:strs){
        if(a==pstr)
        cnt++;
        else cnt=1;
        if(cnt>max){
            max=cnt;
            maxStr=a;
        }
        pstr=a;
    }
    if(max==1) cout<<"Do not have continuous word"<<endl;
    else
    cout<<maxStr<<" "<<max<<endl;
    return 0;
}