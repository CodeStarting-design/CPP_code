#include<iostream>
#include<string>
using namespace std;
void reverse(string &s,int start,int end){
    for(int left=start,right=end;left<right;swap(s[left],s[right]),left++,right--);
}
string reverseWords(string s) {
    reverse(s,0,s.size()-1);
    // 对string进行移动,完成移动后进行单词置逆，
    // 此处采取的方式为逐个单词处理
    // 对空格增加方式为再前补0
    int idx=0;  // 当前指针
    int len =s.size();
    for(int start=0;start<len;start++){
        if(s[start]!=' '){
            if(idx!=0)
            s[idx++]=' ';
            int end=start;
            while(end<len&&s[end]!=' ')s[idx++]=s[end++];
            reverse(s,idx-(end-start),idx-1);
            start=end;
        }
    }
    s.resize(idx);
    return s;
}

int main(){
    string s=" hello world ";
    string str=reverseWords(s);
    cout<<str<<endl;
}
