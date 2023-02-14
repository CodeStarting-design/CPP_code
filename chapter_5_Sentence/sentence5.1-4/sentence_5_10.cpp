#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int aNt=0,eNt=0,iNt=0,oNt=0,uNt=0;
    for(auto &c:str){
        switch (c)
        {
        case 'a':
        case 'A':
        aNt++;break;
        case 'e':
        case 'E':
        eNt++;break;
        case 'i':
        case 'I':
        iNt++;break;
        case 'o':
        case 'O':
        oNt++;break;
        case 'u':
        case 'U':
        uNt++;break;
        default:
            break;
        }
    }
    cout<<aNt<<" "<<eNt<<" "<<iNt<<" "<<oNt<<" "<<uNt<<endl;
    return 0;
}