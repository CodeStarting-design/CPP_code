#include<iostream>
#include<string>
#include<sstream>
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
    string line;
    getline(cin,line);
    istringstream istring(line);
    print(istring);
}