#include<iostream>
#include<string>
using namespace std;
istream& print(istream &is){
    string s;
    while(is>>s){
        if(is.eof())
        break;
        cout<<s<<endl;
    }
    is.clear();
    return is;
}
int main(){
    print(cin);
}