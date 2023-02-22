#include<iostream>
#include<vector>
using namespace std;
void print_vector(vector<int> vec,int index){
    if(index<vec.size()){
        cout<<vec[index]<<" ";
        print_vector(vec,++index);
    }
    return ;
}
int main(){
vector<int> vec={1,2,3,4,5,6,7,8};
print_vector(vec,0);
}