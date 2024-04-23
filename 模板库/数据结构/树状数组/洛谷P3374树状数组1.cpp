#include <vector>
#include <cstdio>



// Fenwick tree class definition
class FenwickTree {
public:
    FenwickTree(int n) : fenwick(n + 1, fenwickInitVal) {}

    // Equivalent to Go's op function
    int op(int a, int b) {
        return a + b;
    }

    // Equivalent to Go's update function
    void update(int i, int val) {
        for (; i < fenwick.size(); i += i & -i) {
            fenwick[i] = op(fenwick[i], val);
        }
    }

    // Equivalent to Go's prefix sum (pre) function
    int prefixSum(int i) {
        int result = fenwickInitVal;
        for (; i > 0; i &= i - 1) {
            result = op(result, fenwick[i]);
        }
        return result;
    }

    // Equivalent to Go's query function
    int query(int l, int r) {
        return prefixSum(r) - prefixSum(l - 1);
    }

private:
    static constexpr int fenwickInitVal = 0;
    std::vector<int> fenwick;
};


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

//int main() {
//    int n = read(), m = read();
//
//    FenwickTree ft(n + 10);  // Create a Fenwick tree with 10 elements
//
//    for (int i = 1; i <= n; ++i) {
//        ft.update(i, read());
//    }
//
//    while (m--) {
//        int ins = read();
//        if (ins == 1) {
//            int x = read(), k = read();
//
//            ft.update(x, k);
//        } else {
//            int x = read(), y = read();
//            printf("%d\n", ft.query(x, y));
//        }
//    }
//
//    return 0;
//}
