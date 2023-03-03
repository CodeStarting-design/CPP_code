#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string filename="./file/file_1.txt";
    ifstream in;
    in.open(filename);
    vector<string> text;
    string word;
    while(in>>word){
        text.push_back(word);
    }
    for(auto &txt:text){
        cout<<txt<<endl;
    }
}