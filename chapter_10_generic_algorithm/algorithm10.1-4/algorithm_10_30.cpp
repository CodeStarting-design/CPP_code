#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
int main(){
    std::vector<int> vec;
    std::istream_iterator<int> in_iter(std::cin),eof;
    while(in_iter!=eof)
    vec.push_back(*in_iter++);
    std::ostream_iterator<int> out_iter(std::cout," ");
    std::sort(vec.begin(),vec.end());
    std::copy(vec.begin(),vec.end(),out_iter);
    std::cout<<std::endl;
}