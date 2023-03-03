#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> commonChars(vector<string>& words) {
        vector<int> pre(26,0);
        vector<int> cur(26,0);
        vector<string> common;
        for(auto &s:words[0])
        pre[s-'a']++;
        for(int i=1;i<words.size();i++){
            for(auto &s:words[i]){
                cur[s-'a']++;
            }
            for(int j=0;j<26;j++)
            pre[j]=min(pre[j],cur[j]);
            fill(cur.begin(),cur.end(),0);          
        }
        for(int i=0;i<26;i++){
            if(pre[i]){
                for(int j=0;j<pre[i];j++){
                    string s;
                    s +=('a'+i);
                    common.push_back(s);
                }
            }
        }
        return common;
}
int main(){
    vector<string> words={"bella","label","roller"};
    vector<string> common=commonChars(words);
    for(auto &a:common)
    cout<<a<<endl;
}