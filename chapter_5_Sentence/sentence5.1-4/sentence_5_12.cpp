#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int ffnt=0,fint=0,flnt=0;
    char pc;
    for(auto &c:str){
        switch (c)
        {
       case 'f':
       if(pc=='f')
       ffnt++;
       break;
       case 'i':
       if(pc=='f')
       fint++;
       break;
       case 'l':
       if(pc=='f')
       flnt++;
       break;
        default:
            break;
        }
        pc=c;
    }
    cout<<ffnt<<" "<<fint<<" "<<flnt<<endl;
    return 0;
}