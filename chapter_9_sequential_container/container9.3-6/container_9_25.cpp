#include<iostream>
#include<vector>
using namespace std;
int main(){
vector<int> vec(10,1);
vector<int>::iterator iter1=vec.begin(),iter2=iter1;
vec.erase(iter1,iter2);
cout<<vec.size()<<endl;
iter1=vec.end(),iter2=iter1;
vec.erase(iter1,iter2);
cout<<vec.size()<<endl;
return 0;
}
