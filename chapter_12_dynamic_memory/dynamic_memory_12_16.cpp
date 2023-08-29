#include<iostream>
#include<memory>
using std::unique_ptr;
int main(){
    unique_ptr<int> p1(new int (10));
    unique_ptr<int> p2;
    // p2=p1;

    // 保存信息：
    // function "std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp> &) [with _Tp=int, _Dp=std::default_delete<int>]" (declared at line 469 of "/usr/include/c++/11/bits/unique_ptr.h") cannot be referenced -- it is a deleted function
}