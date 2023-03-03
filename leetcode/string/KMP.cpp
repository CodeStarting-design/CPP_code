#include<iostream>
#include<string>
#include<vector>
using namespace std;
// 此处的处理方式为，将索引为0的位置置空不使用
vector<int> get_next(string subStr){
    subStr.insert(subStr.begin(),' ');  // 对字符串设置哨兵
    vector<int> next(subStr.size());   // 此时创建的也是一个首位不使用的哨兵
    next[1]=0;
    int i=1,j=0;
    while(i<next.size()){
        if(j==0||subStr[i]==subStr[j]){
            i++,j++;
            next[i]=j;
        }else{
            j=next[j];
        }
    }
    return next;
}
int strStr(string haystack, string needle) {
        // 此处就是KMP算法的匹配过程实现
        vector<int> next=get_next(needle);
        // 在字符串中设置哨兵
        haystack.insert(haystack.begin(),' ');
        needle.insert(needle.begin(),' ');
        int i=1,j=1;
        while(i<haystack.size()&&j<needle.size()){
            if(j==0||haystack[i]==needle[j]){
                i++,j++;
            }else{
                j=next[j];
            }
        }
        if(j==needle.size()) return i-j+1;
        return -1;
    }
int main(){
    string str;
    string subStr;
    cin>>str>>subStr;
    int index=strStr(str,subStr);
    cout<<index<<endl;
}