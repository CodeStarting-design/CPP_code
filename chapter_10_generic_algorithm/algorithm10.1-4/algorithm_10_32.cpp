#include<iostream>
#include<fstream>
#include<iterator>
#include<string>
using std::string;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::istream_iterator;
using std::ostream_iterator;
int main(){
    string infile;
    cin>>infile;
    string outfile1,outfile2;
    cin>>outfile1>>outfile2;
    ifstream is(infile);
    ofstream os1(outfile1),os2(outfile2);
    istream_iterator<int> in_iter(is),eof;
    ostream_iterator<int> out_iter1(os1," "),out_iter2(os2," ");
    while(in_iter!=eof){
        if(*in_iter%2){
            out_iter1=*in_iter++;
        }else{
            out_iter2=*in_iter++;
        }
    }
}