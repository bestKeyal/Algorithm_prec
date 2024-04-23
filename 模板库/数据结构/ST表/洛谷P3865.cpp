#include <bits/stdc++.h>

using namespace std;

template<typename T>
class SparseTable {
public:
    vector<vector<T>> st;
    vector<int> log;

    SparseTable(const vector<T>& a) {
        int n = a.size();
        int max_log = 32 - __builtin_clz(n);
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            log[i] = log[i / 2] + 1;
        }
        st.assign(n, vector<T>(max_log));
        for (int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = Op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T Op(const T& a, const T& b) {
        // Define your operation here.
        return max(a, b);
    }

    T query(int l, int r) { // exclusive of r
        int j = log[r - l];
        return Op(st[l][j], st[r - (1 << j)][j]);
    }
};

// For the index version, you will need a pair with value and index
struct Pair {
    int v, i;
};

template<>
Pair SparseTable<Pair>::Op(const Pair& a, const Pair& b) {
    if (a.v <= b.v) { // Change this comparison for max-query or others
        return a;
    }
    return b;
}

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
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    SparseTable<int> st(a);

    int l, r;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &l, &r);
        // 注意：SparseTable中的r是独占的，所以无需像常规区间查询中一样减去1
        printf("%d\n", st.query(l - 1, r));
    }
    return 0;
}
