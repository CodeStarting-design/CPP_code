#include<iostream>
namespace name1
{
    int i=0;
    namespace name2{
        int j=1;
    }
} // namespace name1
using namespace name1;
using std::cout;
using std::endl;
int main(){
    cout<<i<<name2::j<<endl;
}