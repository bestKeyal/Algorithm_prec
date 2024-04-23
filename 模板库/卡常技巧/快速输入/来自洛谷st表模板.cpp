#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    // 跳过前面的非数字字符，保留负号
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    // 读取数字
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}













int main() {
    // 请确保你的文件路径是正确的
    char input[] = "D:\\Algorithm\\input.txt";
    FILE* file = fopen(input, "w"); // 打开文件用于写入

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1; // 如果文件无法打开，返回错误码
    }

    // 写入一些测试数据
    srand((unsigned int)time(NULL));
    int T = 10000;
    for (int i = 0; i < T; ++i) {
        int num = (rand() % 20101) - 10000;
        fprintf(file, "%d\n", num);
        fprintf(file, "%d\n", num);
    }
    fclose(file); // 关闭文件

    freopen(input, "r", stdin); // 重新打开文件用于读取
    int number, read_number;
    bool consistent = true; // 标志位，用于检查两种方法读取的数据是否一致

    for (int i = 0; i < T; ++i) {
        // 使用 scanf 读取一个整数
        scanf("%d", &number);

        // 使用自定义的 read 函数读取一个整数
        read_number = read();

        // 比较两个值是否相等
        if (number != read_number) {
            consistent = false;
            break; // 如果发现不一致，退出循环
        }
    }

    if (consistent) {
        printf("The results are consistent.\n");
    } else {
        printf("The results are not consistent.\n");
    }

    fclose(stdin); // 关闭文件流
    return 0;
}
