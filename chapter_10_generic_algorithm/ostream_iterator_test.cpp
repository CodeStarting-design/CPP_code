#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>
int main(){
    std::ostream_iterator<int> out_iter(std::cout," "); // 每次输出将会输出在后面
    std::vector<int> vec{1,2,3,4,5};
    std::copy(vec.begin(),vec.end(),out_iter);
    std::cout<<std::endl;
    for(auto a:vec)
    *out_iter++=a; // 等价与out_iter=a
}