#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<const char *> roster1{"123\0","111\0"};
    vector<const char *> roster2{"12\0","11\0"};
    bool flag=equal(roster1.cbegin(),roster1.cend(),roster2.cbegin());
    cout<<flag<<endl;
}