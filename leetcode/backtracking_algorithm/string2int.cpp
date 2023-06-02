#include <iostream>
#include <sstream>

int main()
{
    std::string str = "001";
    int num = 0;

    std::istringstream ss(str);
    ss >> num;

    std::cout << num;
    return 0;
}