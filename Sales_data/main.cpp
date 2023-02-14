#include<string>
#include<iostream>
#include"Sales_data.h"
using namespace std;
int main(){
    Sales_data data1;
    cin>>data1.bookNo;
    cout<<data1.bookNo<<data1.revenue<<data1.units_sold<<endl;
    return 0;
}