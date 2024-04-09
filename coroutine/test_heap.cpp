#include <iostream>

int main() {
    // 使用 new 运算符动态分配长度为 10 的 char 数组
    char* charArray = new char[10];

    // 访问数组元素并赋值
    for (int i = 0; i < 10; ++i) {
        charArray[i] = 'A' + i; // 为数组赋值，A-J
    }

    // 打印数组 地址
    for (int i = 0; i < 10; ++i) {
        std::cout<<"索引：" << i << " 堆内存地址："<<static_cast<void*>(&charArray[i])<<std::endl;
    }
    std::cout << std::endl;

    // 释放动态分配的内存
    delete[] charArray;

    return 0;
}
