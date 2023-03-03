#include<iostream>
#include<string>
using namespace std;
class Screen{
    public:
    typedef string::size_type pos;
    Screen()=default;
    Screen(pos width,pos high):width(width),high(high),contents(width*high,' '){};
    Screen(pos width,pos high,char s):width(width),high(high),contents(width*high,s){};
    private:
    string contents;
    pos width=0,high=0;
    pos curpos=0;
};

int main(){
Screen s1;
Screen s2(1,2);
Screen s3(1,2,'n');

}