
// 普通树状数组
// 单点修改
// 区间查询
class FenwickTree {
public:
    FenwickTree(int n) : fenwick(n + 1, fenwickInitVal) {}

    // Equivalent to Go's op function
    int op(int a, int b) {
        return a + b;
    }

    // 点修改
    void update(int i, int val) {
        for (; i < fenwick.size(); i += i & -i) {
            fenwick[i] = op(fenwick[i], val);
        }
    }

    // 前缀和
    int pre(int i) {
        int result = fenwickInitVal;
        for (; i > 0; i &= i - 1) {
            result = op(result, fenwick[i]);
        }
        return result;
    }

    // Equivalent to Go's query function
    int query(int l, int r) {
        return pre(r) - pre(l - 1);
    }

private:
    static constexpr int fenwickInitVal = 0;
    vector<int> fenwick;
};

