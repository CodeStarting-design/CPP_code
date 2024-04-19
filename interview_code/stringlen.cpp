#include <iostream>
#include<string>
using namespace std;

int main() {
    string s;
    while (cin >> s) { // 注意 while 处理多个 case
        int res=0;
        for(int i=s.size()-1;i>-1&&s[i]!=' ';i--,res++);
        cout<<res;
    }
}