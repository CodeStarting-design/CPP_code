#include<iostream>
#include<string>
using namespace std;
class Screen{
    public:
    typedef string::size_type pos;
    Screen()=default;
    Screen(pos width,pos high):width(width),high(high),contents(width*high,' '){};
    Screen(pos width,pos high,char s):width(width),high(high),contents(width*high,s){};
    inline Screen &set(char s);
    inline Screen &move(pos w,pos h);
    inline Screen &display(ostream &os);
    inline const Screen &display(ostream &os) const;
    private:
    string contents;
    pos width=0,high=0;
    pos curpos=0;
    void do_display(ostream &os) const { os<<contents<<endl; }
};
Screen& Screen::move(pos w,pos h){
    curpos=w*width;
    curpos+=h;
    return *this;
}
Screen &Screen::set(char s){
    contents[curpos]=s;
    return *this;
}
Screen &Screen::display(ostream &os){
    do_display(os);
    return *this;
}
const Screen& Screen::display(ostream &os) const{
    do_display(os);
    return *this;
}
int main(){
Screen s1;
Screen s2(1,2);
Screen s3(5,5,'x');
s3.move(4,0).set('#').display(cout);
s3.display(cout);
}