#include<iostream>
#include<string>
#include<memory>
#include<cstring>
using std::string;
int main() {
	const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
    for(int i=0;i<strlen(c1);i++){
        r[i]=*(c1+i);
    }
    for(int i=strlen(c1);i<len-1;i++){
        r[i]=c2[i-strlen(c1)];
    }
    std::cout<<r<<std::endl;

    string s1="hello ";
    string s2="world";
    int slen=s1.size()+s2.size();
    char *r2=new char[slen]();
    for(int i=0;i<s1.size();i++){
        r2[i]=s1[i];
    }
    for(int i=s1.size();i<slen;i++){
        r2[i]=s2[i-s1.size()];
    }
    std::cout<<r2<<std::endl;
	delete[] r;
    delete[] r2;

	return 0;
}