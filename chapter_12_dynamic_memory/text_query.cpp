#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using std::ifstream;
using std::string;
using std::istringstream;
using std::vector;
using std::getline;
using std::endl;
using std::cout;
struct text
{
    int line;
    string str;
    text(int l,string s):line(l),str(s){}
};
vector<text> query(string file_name,string word,int &count){
    ifstream is(file_name);
    string line_str;
    int i=0;
    vector<text> res;
    while(getline(is,line_str)){
        i++;
        istringstream istr(line_str);
        string line_word;
        bool flag=false;
        while(istr>>line_word){
            if(line_word==word){
                count++;
                flag=true;
            }
        }
        if(flag){
            res.emplace_back(i,line_str);
        }
    }
    return res;
}
int main(){
    string file_name="./text.txt";
    string word="nice";
    int count=0;
    vector<text> res=query(file_name,word,count);
    cout<<word<<" occurs "<<count<<" times"<<endl;
    for(auto r:res){
        cout<<"(line"<<r.line<<") "<<r.str<<endl;
    }
    return 0;
}
