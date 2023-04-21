#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<fstream>
#include<sstream>
using std::unordered_map;
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::ifstream;
using std::istringstream;
unordered_map<string,string> buildMap(ifstream &map_file){ // 读取转换规则并建立map
    unordered_map<string,string> trans_map;
    string word,rule;
    while(map_file>>word&&getline(map_file,rule)){
        if(rule.size()>1){
            trans_map.insert({word,rule.substr(1)});
        }else{
            cout<<"error"<<std::endl;
        }
    }
    return trans_map;
}
const string transform(const string s,const unordered_map<string,string> m){
    if(m.find(s)!=m.end()){
        return m.at(s);
    }else{
        return s;
    }
}
void word_transform(ifstream &map_file,ifstream &input){
    auto trans_map=buildMap(map_file);
    string line;
    while(getline(input,line)){
        istringstream is(line); // 来自头文件 sstream中
        string word;
        bool flag=true;
        while(is>>word){
            if(flag){
                flag=false;
            }else{
                std::cout<<" ";
            }
            std::cout<<transform(word,trans_map);
        }
        std::cout<<std::endl;
    }

}
int main(){
    ifstream map_file("./associative_container_11_3_6/conversion_rules.txt");
    ifstream input("./associative_container_11_3_6/source.txt");
    word_transform(map_file,input);
}