#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
using std::vector;
using std::string;
using std::map;
using std::unordered_map;
unordered_map<string,map<string,bool>> tic_map;
    vector<string> res;
    bool backtracking(vector<vector<string>>& tickets){
        if(res.size()==tickets.size()+1){
            return true;
        }
        for(auto &a:tic_map[res.back()]){
            if(!a.second){
                res.push_back(a.first);
                a.second=true;
                if(backtracking(tickets))
                return true;
                res.pop_back();
                a.second=false;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const vector<string>& vec : tickets) {
            tic_map[vec[0]][vec[1]]=false; // 记录映射关系
        }
        res.push_back("JFK");
        backtracking(tickets);
        return res;
    }
    int main(){
        vector<vector<string>> tickets={{"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}};
        vector<string> jou = findItinerary(tickets);
        for(auto &a:jou)
            std::cout<<a<<" ";
    }