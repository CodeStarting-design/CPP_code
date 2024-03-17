#include <iostream>
#include <sys/uio.h>

int main() {
    char buf1[] = "Hello, ";
    char buf2[] = "world!";
    
    // 定义 struct iovec 数组，用于描述两个缓冲区的位置和长度
    struct iovec iov[2];
    iov[0].iov_base = buf1;
    iov[0].iov_len = sizeof(buf1) - 1; // -1 排除末尾的空字符
    iov[1].iov_base = buf2;
    iov[1].iov_len = sizeof(buf2) - 1;

    // 执行数据聚集操作，将两个缓冲区中的数据聚集到一个连续的数据块中
    char combined[100];
    ssize_t total = readv(0, iov, 2); // 从标准输入读取数据到 combined 缓冲区中
    if (total == -1) {
        std::cerr << "Read error" << std::endl;
        return 1;
    }

    // 输出聚集后的数据
    std::cout << "Combined data: " << combined << std::endl;

    return 0;
}