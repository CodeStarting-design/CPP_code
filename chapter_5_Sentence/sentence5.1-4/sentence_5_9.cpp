#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int nt=0;
    for(auto &c:str){
        switch (c)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        nt++;
        default:
            break;
        }
    }
    cout<<nt<<endl;
    return 0;
}