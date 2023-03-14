#include<iostream>
#include<fstream>
#include<vector>
#include<iterator>
#include<string>
int main(){
    std::ifstream is("a.txt");
    std::istream_iterator<std::string> in_iter(is),eof;
    std::vector<std::string> vec;
    while(in_iter!=eof)
    vec.push_back(*in_iter++);
    for(auto a:vec)
    std::cout<<a<<std::endl;
}