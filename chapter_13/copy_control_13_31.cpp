#include "copy_control_13_31.h"
#include<vector>
#include<algorithm>
using std::vector;
using std::string;
using std::sort;
using std::cout;
int main(){
    vector<HasPtr> vhp;
    for(int i=0;i<10;i++){
        vhp.push_back(HasPtr(string(i,'a')));
    }
    for(auto &a:vhp){
        a.show();
    }
    sort(vhp.begin(),vhp.end(),isshorter);
    return 0;
}