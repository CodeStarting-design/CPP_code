#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using std::ifstream;
using std::vector;
using std::string;
class len{
public:    
    bool operator()(string &s,int val){
        return s.size()==val;
    }
};
int main(){
    vector<int> res(10,0);
    string filename;
    std::cin>>filename;
    ifstream is(filename);
    string world;
    
}