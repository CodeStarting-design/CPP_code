#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using std::istringstream;
using std::map;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;
map<string,string> buildMap(ifstream &map_file){ // 读取转换规则并建立map
    map<string,string> trans_map;
    string rule;
    while(getline(map_file,rule)){ // 先读取一行
        string::size_type divide=rule.find(" ");
        string key,value;
        for(string::size_type i=0;i<divide;i++){
            key+=rule[i];
        }
        for(string::size_type i=divide+1;i<rule.size();i++){
            value+=rule[i];
        }
        trans_map.insert({key,value});
    }
    return trans_map;
}
const string &transform(const string &s,map<string,string> &m){
    auto map_it=m.find(s);
    if(map_it==m.end()){
        return s;
    }else{
        return m[s];
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
    ifstream map_file("conversion_rules.txt");
    ifstream input("source.txt");
    word_transform(map_file,input);
}
