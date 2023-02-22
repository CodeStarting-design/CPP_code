#include<iostream>
#define MAX
#include<cassert>
using namespace std;
int main(){
    int i;
    cin>>i;
    if(i){
        #ifndef MAX
        cerr<<__func__<<"  "<<__FILE__<<"  "
        <<__LINE__<<"  "<<__TIME__<<"  "
        <<__DATE__<<endl;
        #endif
    }
}
