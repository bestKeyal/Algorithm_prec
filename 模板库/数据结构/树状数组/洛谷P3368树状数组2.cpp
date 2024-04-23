#include <bits/stdc++.h>

using namespace std;

// 索引从1开始


class FenwickDiff {
public:
    // [0] 维护 ∑diff[i]
    // [1] 维护 ∑i*diff[i]
    FenwickDiff(int n): tree(n + 1, vector<int>(2, 0)) {}

    // 给a[i]加上val
    void _add(int i, int val) {
        // i += i & -i代表增加在最低位的1所代表的十进制数。
        for (int iv = i * val; i < tree.size(); i += i & -i) {
            tree[i][0] += val;
            tree[i][1] += iv;
        }
    }

    // a[l] 到 a[r] 增加 val
    // 1<=l<=r<=n
    void add(int l, int r, int val) {
        _add(l, val);
        _add(r + 1, -val);
    }

    // 求前缀和 a[1] + ... + a[i0]
    // 1<=i0<=n
    int pre(int i0) {
        int s0 = 0, s1 = 0;
        // i &= i - 1 代表移除最低位的1
        for (int i = i0; i > 0; i &= i - 1) {
            s0 += tree[i][0];
            s1 += tree[i][1];
        }

        //  a[1] + ... + a[m]
        //   = ∑(m-i+1)*diff[i]
        //   = (m+1)∑diff[i] - ∑i*diff[i]
        return (i0 + 1) * s0 - s1;
    }

    int query(int l, int r) {
        return pre(r) - pre(l - 1);
    }

private:
    vector<vector<int>> tree;
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
//    FenwickDiff fd(n);
//
//    for (int i = 1; i <= n; ++i)
//        fd.add(i, i, read());
//
//    while (m--) {
//        int ins = read();
//
//        if (ins == 1) {
//            int x = read(), y = read(), k = read();
//            fd.add(x, y, k);
//        }
//        else {
//            int x = read();
//            int res = fd.query(x, x);
//            printf("%d\n", res);
//        }
//    }
//
//    return 0;
//
//}
