#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
void elimDups(vector<string> &vec){
   sort(vec.begin(),vec.end());
   auto un_end=unique(vec.begin(),vec.end());
   vec.erase(un_end,vec.end());
}
bool isShotter(const string &s1,const string &s2){
   return s1.size()<s2.size();
}
void biggies(vector<string> vec,vector<string>::size_type sz){
   elimDups(vec);
   stable_sort(vec.begin(),vec.end(),isShotter);
   auto sz_end=partition(vec.begin(),vec.end(),[sz](const string &s1)->bool {return s1.size()>=sz;});
   auto len=sz_end-vec.begin();
   cout<<len<<endl;
   for_each(vec.begin(),sz_end,[](const string &s1){cout<<s1<<" ";});
   cout<<endl;
}
int main(){
   vector<string> vec;
   string s;
   while(cin>>s)
   vec.push_back(s);
   biggies(vec,6);
}