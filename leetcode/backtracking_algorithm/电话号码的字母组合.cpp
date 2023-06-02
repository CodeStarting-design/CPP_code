#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
vector<string> letter={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    string str;
    void DFS(string digits,int start){
        if(start==digits.size()){
            res.push_back(str);
            return;
        }
        string s=letter[digits[start]-'2'];
        for(int i=0;i<s.size();i++){
            str+=s[i];
            DFS(digits,start+1);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        DFS(digits,0);
        return res;
    }

int main(){
    letterCombinations("23");
    for(auto &a:res)
        std::cout<<a<<std::endl;
}

