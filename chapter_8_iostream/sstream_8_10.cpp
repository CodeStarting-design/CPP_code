#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    string filename="./file/file_3.txt";
    ifstream in(filename);
    vector<string> sline;
    string line;
    while(getline(in,line)){
        sline.push_back(line);
    }
    string word;
    for(auto &s:sline){
        istringstream is(s);
        while(is>>word){
            cout<<word<<endl;
        }
    }
}