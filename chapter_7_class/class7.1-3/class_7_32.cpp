#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Screen; // 先完成声明
class window_mgr{
    public:
    void clear();
    window_mgr()=default;
    // window_mgr(int i,Screen s):curScr(i),screens({s}){};
    private:
    vector<Screen> screens;
    int curScr=-1;  // 定义的默认构造函数将会使用该函数值
};
class Screen{
    friend void window_mgr::clear();
    public:
    Screen()=default;
    Screen(int w,int h,char a):width(w),high(h),contents(w*h,a) {};
    void print(ostream &os);
    private:
    int curpos=0;
    int width=0;
    int high=0;
    string contents;
};
void window_mgr::clear(){
    if(curScr!=-1)
    screens[curScr].contents="";
}
void Screen::print(ostream &os){
    os<<contents<<endl;
}
int main(){
    Screen s1(4,2,'a');
    s1.print(cout);
    window_mgr m1;
    m1.clear();
}