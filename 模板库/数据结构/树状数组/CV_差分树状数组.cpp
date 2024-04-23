// 差分树状数组
// - 区间修改
// - 区间查询
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
