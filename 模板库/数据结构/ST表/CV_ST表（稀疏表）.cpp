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

    // 信息维护方式（可选最大值，最小值等）
    int Op(const int& a, const int& b) {
        return max(a, b);
    }

    // 查询左闭右开区间 [l,r)    0 <= l < r <= n
    int query(int l, int r) { // exclusive of r
        int j = log[r - l];

        return Op(st[l][j], st[r - (1 << j)][j]);
    }
};


