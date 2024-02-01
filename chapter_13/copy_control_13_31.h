#ifndef copy_control_13_31_h
#define copy_control_13_31_h
#include<string>
#include<iostream>
class HasPtr
{
public:
	friend void swap(HasPtr&, HasPtr&);// 定义为友元函数
	HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
	HasPtr& operator=(const HasPtr &hp) // 此处使用的是按值赋值
	{
		auto new_p = new std::string(*hp.ps);
		delete ps;
		ps = new_p;
		i = hp.i;
		return *this;
	}
	~HasPtr()
	{
		delete ps;
	}

	void show() { std::cout << *ps << std::endl; }
    friend bool isshorter(const HasPtr& , const HasPtr&);
private:
	std::string *ps;
	int i;
};
// 类的友元函数的定义 不需要再进行额外的声明为类的友元直接定义一个函数即可
inline
void swap(HasPtr& h1, HasPtr& h2){// 此处需要的是按值进行交换
    using std::swap;
    swap(h1.ps,h2.ps); // 此处是直接使用标准库的函数
    swap(h1.i,h2.i);
    std::cout << "call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}
bool isshorter(const HasPtr& lhp,const HasPtr& rhp){
    // std::cout<<*lhp.ps<<" "<<*rhp.ps<<std::endl;
    return lhp.ps->size()>rhp.ps->size();
}
#endif