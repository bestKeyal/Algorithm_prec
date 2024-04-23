#include <bits/stdc++.h>

using namespace std;

// 索引从0开始
class ST {
public:
    // st[i][j] 对应的区间是 [i, i+2^j)
    vector<vector<int>> st;
    vector<int> log;

    // a的下标从0开始
    ST(const vector<int> & a) {
        int n = a.size();
        // 获取n所占的比特位数。
        int max_log = 32 - __builtin_clz(n);

        // 用log[i]代表log(2, i)的向上取整的对数值。
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        st.assign(n, vector<int>(max_log));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = Op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int Op(const int& a, const int& b) {
        // Define your operation here.
        return max(a, b);
    }

    // Query 查询区间 [l,r)    0 <= l < r <= n
    int query(int l, int r) { // exclusive of r
        int j = log[r - l];
        return Op(st[l][j], st[r - (1 << j)][j]);
    }
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


int main() {
    int n = read(), m = read();
    vector<int> a(n);

    for (int i = 0; i < n; ++i)
        a[i] = read();

    ST st(a);

    while (m--) {
        int l = read(), r = read();
        int res = st.query(l - 1, r);
        printf("%d\n", res);
    }
    return 0;
}
