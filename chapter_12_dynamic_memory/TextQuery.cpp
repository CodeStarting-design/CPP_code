#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<memory>
using std::ifstream;
using std::string;
using std::istringstream;
using std::vector;
using std::map;
using std::set;
using std::getline;
using std::endl;
using std::cout;
using std::shared_ptr;
class QueryResult;
class TextQuery{// 构造函数需要完成数据成员的初始化
public:
    using line_no=vector<string>::size_type; 
    TextQuery(ifstream&);
    QueryResult query(const string& ) const; // 函数是const类型，返回值是QueryResult的对象
private:
    shared_ptr<vector<string>> file;
    map<string,shared_ptr<set<line_no>>> word_map;
};

// 在类外部完成构造函数的定义

TextQuery::TextQuery(ifstream& is):file(new vector<string>){
        string line;
        while(getline(is,line)){
            file->push_back(line);
            line_no n=file->size()-1;
            istringstream line_in(line);
            string word;
            while(line_in>>word){
                auto &lines=word_map[word];
                if(!lines)// 指针为空，需要向map中添加
                    lines.reset(new set<line_no>);// 重置共享指针，指向内存中一个新开辟的内存空间
                lines->insert(n);
            }           
        } 
}

class QueryResult{
    friend std::ostream& print(std::ostream& ,const QueryResult&); // 将外部函数声明为当前类的友元函数
public:
    QueryResult(string s,shared_ptr<vector<string>> f,shared_ptr<set<vector<string>::size_type>> p):
    word(s),file(f),lines(p){}
private:
    string word;
    shared_ptr<vector<string>> file;
    shared_ptr<set<vector<string>::size_type>> lines;
};

QueryResult // 先写返回值类型
TextQuery::query(const string& queryText) const{ // 
    static shared_ptr<set<line_no>> nodata(new set<line_no>); //先创建一个静态的指针，并且指向了内存中的区域
    auto loc=word_map.find(queryText); // 查找成功返回的是一个shared_ptr指针，失败返回的是word_map.end()
    if(loc==word_map.end()){
        return QueryResult(queryText,file,nodata);
    }else{
        return QueryResult(queryText,file,loc->second);
    }
}
std::ostream& print(std::ostream& os,const QueryResult& res){
    os<<res.word<<" occurs "<<res.lines->size()<<" times "<<endl;
    for(auto num:*res.lines)// 此处是对指向set的指针进行解引用
        os<<"\t(line"<<num+1<<")"<<*(res.file->begin()+num)<<endl;
    return os;
}
int main(){
    string file_path;
    std::cin>>file_path;
    string query_text;
    std::cin>>query_text;
    ifstream isf(file_path);
    TextQuery tq(isf);
    print(std::cout,tq.query(query_text));
}