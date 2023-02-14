#include<iostream>
#include<string>
using namespace std;
int main()
{
    int grade=40;
    string res=grade>90?"high level":grade>60?"pass":"fail";
    cout<<res<<endl;
    return 0;
} 