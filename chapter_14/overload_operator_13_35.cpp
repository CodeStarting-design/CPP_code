#include<iostream>
#include<string>
#include<istream>
#include<vector>
using std::vector;
using std::string;
using std::istream;
using std::getline;
class PrintString{
public:
    PrintString(istream& in=std::cin):is(in){}
    string operator() () {
        string str;
        if(!getline(is,str)){
            str="";
        }
        return str;
    }
private:
    istream &is;
};
int main(){
    PrintString a;
    std::cout<<a();
    vector<string> strvec;
    string str;
    while((str=a())!=""){
        strvec.push_back(str);
    }
    for(auto s:strvec){
        std::cout<<s<<std::endl;
    }
}