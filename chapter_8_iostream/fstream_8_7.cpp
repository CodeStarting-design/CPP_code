#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
int main(int argc,char *argv[]){ // 传递的是一个char* 类型的数组
    string infilename=argv[1];
    string outfilename=argv[2];
    ifstream in(infilename);
    ofstream out(outfilename,ofstream::app);
    string word;
    vector<string> text;
    while(in>>word){
        text.push_back(word);
    }
    for(auto &s:text){
        cout<<s<<endl;
        out<<s;
    }
}