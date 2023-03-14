#include<iostream>
#include<string>
#include<deque>
#include<stack>
using namespace std;
    string simplifyPath(string path) {
        deque<char> s;
        int i=0;
        while(i<path.size()){
            switch(path[i]){
                case '.':
                if(!s.empty()&&s.back()=='/'){
                    if(path.substr(i,2)=="./"){
                        i+=2;
                        break;
                    }
                    if(path.substr(i,3)=="../"){
                        i+=3;
                        s.pop_back();
                        while(!s.empty()&&s.back()!='/')
                            s.pop_back();
                        if(s.empty()) s.push_back('/');
                        break;
                    }
                    s.push_back(path[i++]);
                }else{
                    s.push_back(path[i++]);
                }
                break;
                case '/':
                if(!s.empty()&&s.back()=='/'){
                    i++;
                }
                else s.push_back(path[i++]);
                break;
                default:
                s.push_back(path[i++]);
            }     
        }
        if(s.size()>1&&s.back()=='/') s.pop_back();
        string ans;
        for(auto a:s)
        ans+=a;
        return ans;
    }
int main(){
    string s;
    cin>>s;
    string ans=simplifyPath(s);
    cout<<ans<<endl;
}